/*! \file
    \brief Перечисляем модули и кучи для поиска указателей на нужные функции, тестируе перехват с детурс
 */

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <Shobjidl.h>
#include <shobjidl_core.h>

#include <iostream>
#include <cctype>
#include <vector>

#include "helpers.h"

#include "coinit.h"

#include "toolhelp.h"

#include "WinDebugMonitorImpl.h"

#include "helpers.h"

#include <../_3dp/Detours/src/detours.h>

#define SQLITE_OMIT_LOAD_EXTENSION

#include "../_3dp/sqlite/sqlite3.h"
#include "../_3dp/sqlite/sqlite3ext.h"

#pragma comment( lib, "detours.lib" )
#pragma comment( lib, "e_sqlite3.lib" )



static DWORD (WINAPI *real_GetCurrentProcessId)(VOID) = GetCurrentProcessId;

DWORD WINAPI hooked_GetCurrentProcessId(VOID)
{
    std::cout << "!!! hooked_GetCurrentProcessId\n";

    return real_GetCurrentProcessId();
}





std::string whatsAppExeName = "WhatsApp.exe";

void printModuleEntry(const MODULEENTRY32 &me)
{
    std::cout << "Module: " << to_ascii(&me.szModule[0]) << "\n";
    std::cout << "Path  : " << to_ascii(&me.szExePath[0]) << "\n";

    // modBaseAddr The base address of the module in the context of the owning process.

    std::cout << "hMod  : " << formatPtr(me.hModule) << "\n";
    std::cout << "Base  : " << formatPtr(me.modBaseAddr) << "\n";
    std::cout << "Size  : " << formatPtr((void*)me.modBaseSize) << " (" << me.modBaseSize << ")\n";
    std::cout << "Next  : " << formatPtr(getModuleNextFreeAddr(me)) << "\n";

}

void printMemoryBlockInfo(const ModuleInfo &mi)
{
    std::cout << "Module: " << to_ascii(mi.moduleName) << "\n";
    std::cout << "Path  : " << to_ascii(mi.moduleExeName) << "\n";

    std::cout << "Base  : " << formatPtr(mi.pbAddress) << "\n";
    std::cout << "Size  : " << formatPtr((void*)mi.blockSize) << " (" << mi.blockSize << ")\n";
    std::cout << "Next  : " << formatPtr(mi.getNextFreeAddress()) << "\n";
}

void printMemoryBlockInfo(const MemoryBlockInfo &mi)
{
    std::cout << "Base  : " << formatPtr(mi.pbAddress) << "\n";
    std::cout << "Size  : " << formatPtr((void*)mi.blockSize) << " (" << mi.blockSize << ")\n";
    std::cout << "Next  : " << formatPtr(mi.getNextFreeAddress()) << "\n";
}


int main(int argc, char* argv[])
{

    std::vector<MODULEENTRY32> moduleInfoList; moduleInfoList.reserve(16);

    {
        CToolhelp toolhelp;
        if (!toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
        {
            std::cout << "Failed to get toolhelp snapshot (1), error: " << GetLastError() << "\n";
            return 1;
        }

        // See also https://learn.microsoft.com/en-us/windows/win32/api/psapi/nf-psapi-getmoduleinformation
        toolhelp.enumerateModules( [&](const MODULEENTRY32 &me)
                                   {
                                       moduleInfoList.emplace_back(me);
                                       return true; // allow continue
                                   }
                                 );
    }

    std::string argv1;
    if (argc>1)
    {
        argv1 = argv[1];
    }

    if (IsDebuggerPresent())
    {
        argv1 = "prnboth";
    }

    // prnboth нужен, чтобы за один приём напечатать сортированное и не сортированное
    // В современных виндах адреса загрузки могут плавать от запуска к запуску, поэтому, 
    // возможно, надо бы за один раз всё выводить

    if (argv1=="prngot" || argv1=="prnboth")
    {
        std::cout << "\n------------------------------\n";
        std::cout << "*** Modile list as got\n";
        for(const auto &me : moduleInfoList)
        {
            std::cout << "----------\n";
            printModuleEntry(me);
        }
    }

    std::sort(moduleInfoList.begin(), moduleInfoList.end(), [](const MODULEENTRY32 &me1, const MODULEENTRY32 &me2) { return me1.modBaseSize < me2.modBaseSize; });

    if (IsDebuggerPresent())
    {
        argv1 = "prnsorted";
    }

    if (argv1=="prnsorted" || argv1=="prnboth")
    {
        std::cout << "\n------------------------------\n";
        std::cout << "*** Modile list sorted\n";
    
        BYTE* prevNext = 0; // address next for the prev module end
        for(const auto &me : moduleInfoList)
        {
            std::cout << "----------\n";
            if (prevNext)
            {
                if (prevNext!=me.modBaseAddr)
                {
                    auto delta = me.modBaseAddr - prevNext;
                    std::cout << "* Gap : " << formatPtr((void*)delta) << " (" << (std::uintptr_t)delta << ")\n\n";
                }
                // else
                // {
                //     std::cout << "* NoGap\n\n";
                // }
            }
    
            printModuleEntry(me);
    
            prevNext = getModuleNextFreeAddr(me);
        }

    }

    // void printMemoryBlockInfo(const MemoryBlockInfo &me)

    
    // Requires
    // @set PATH=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2320.2.0_x64__cv1g1gvanyjgm;%PATH%
    // @set PATH=C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe;%PATH%
    int sqlRes = sqlite3_close(0); // force link & e_sqlite3.dll load DLL

    BYTE* sqlite3_close_pbfnptr1 = (BYTE*)&sqlite3_close;
    BYTE* sqlite3_close_pbfnptr2 = 0;
    {
        HMODULE hSqlDll = LoadLibraryA("e_sqlite3.dll");
        if (hSqlDll!=0)
        {
            sqlite3_close_pbfnptr2 = (BYTE*)GetProcAddress(hSqlDll, "sqlite3_close");
            FreeLibrary(hSqlDll);
        }
    }
    
    std::cout << "sqlite3_close(1) : " << formatPtr(sqlite3_close_pbfnptr1) << "\n";
    std::cout << "sqlite3_close(2) : " << formatPtr(sqlite3_close_pbfnptr2) << "\n";

    std::vector<ModuleInfo> modulesInfo;
    {
        CToolhelp toolhelp;
        if (toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
        {
            modulesInfo = toolhelp.getModulesInfo();
        }
    }

    std::size_t 
    blockIdx = findBlockByAddress(modulesInfo, sqlite3_close_pbfnptr1);
    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "sqlite3_close(1) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }

    blockIdx = findBlockByAddress(modulesInfo, sqlite3_close_pbfnptr2);
    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "sqlite3_close(2) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }


    if (argv1=="prngot" || argv1=="prnsorted" || argv1=="prnboth")
    {
        if (!IsDebuggerPresent())
        {
            // Если не под отладчиком и задана команда prn*, то выходим
            return 0;
        }
    }

    return 0;
}

