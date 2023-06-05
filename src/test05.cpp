/*! \file
    \brief Используем ReflectiveDLLInjection/inject.x64.exe для инжекта нашей DLL. Перетаскивать код оттуда лень, делаем тут просто лаунчер для нашей DLL с поиском нужного PID.
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

    if (argv1=="prngot" || argv1=="prnsorted" || argv1=="prnboth")
    {
        if (!IsDebuggerPresent())
        {
            // Если не под отладчиком и задана команда prn*, то выходим
            return 0;
        }
    }

#if 0
typedef int (*sqlite3_loadext_entry)(
  sqlite3 *db,                       /* Handle to the database. */
  char **pzErrMsg,                   /* Used to set error string on failure. */
  const sqlite3_api_routines *pThunk /* Extension API function pointers. */
);

sqlite3_data_directory DATA
sqlite3_temp_directory DATA
sqlite3_version DATA

sqlite3_declare_vtab
sqlite3_enable_load_extension
sqlite3_libversion
sqlite3_libversion_number
sqlite3_load_extension

sqlite3_os_end
sqlite3_os_init

sqlite3_set_auxdata

sqlite3_user_data

sqlite3_vtab_collation
sqlite3_vtab_config
sqlite3_vtab_distinct
sqlite3_vtab_in
sqlite3_vtab_in_first
sqlite3_vtab_in_next
sqlite3_vtab_nochange
sqlite3_vtab_on_conflict
sqlite3_vtab_rhs_value

// Imports from WhatsApp.dll
sqlite3_aggregate_context
sqlite3_bind_int
sqlite3_bind_int64
sqlite3_bind_text
sqlite3_close_v2
sqlite3_column_bytes
sqlite3_column_count
sqlite3_column_int64
sqlite3_column_text
sqlite3_column_type
sqlite3_errmsg
sqlite3_exec
sqlite3_finalize
sqlite3_free
sqlite3_libversion_number
sqlite3_open
sqlite3_prepare_v2
sqlite3_step


TODO: !!!
  0) OutputDebugString - работает и с UWP
  1) Выяснить, где вообще в адресном пространстве процесса могут быть расположены какие-либо данные, пользовательские, 
     данные с кодом (модулей/DLLек), и тд и тп - уточнить!!!
  2) Найти адреса некоторых функций SQLite3 - из таблицы экспорта
     Тут надо бы перелопатить по хорошему таблицу экспорта каждой DLLки,
     Но пока просто линкуем SQLite3 либу и получаем адреса оттуда
  3) Адреса в таблице экспорта - это круто, но есть вероятность, что при вызовах они не обязательно используются.
     В SQLite3 есть куча структур с указателями на функции, и, возможно, используется что-то такое.
     Такая таблица может быть получена хз как, но изнутри либы, и тогда реальные адреса функций SQLite3 не будут
     совпадать с тем, что лежит в таблице импорта - там трамплины, которые настраиваются при загрузке DLL
     Значит, нам надо продизасмить то, что лежит по адресам экспорта, и найти, куда эти трамплины ведут
  4) а. Нашли, куда ведут трамплины - пропатчим их там.
     б. У нас есть все возможные адреса используемой памяти процесса, и есть все возможные адреса искомых функций
     Тупо обходим всю память с шагом выравнивания указателя и ищем что-то похожее на искомые адреса.
     Будет найдена скорее всего какая-то VTBL или что-то подобное, можно пропатчить адреса там, без трамплинов.
  5) Вопрос - когда загружается хук. Если хук загружается после загрузки основных ядрёных DLL, но до загрузки всех
     необходимых EXE-шнику DLL - как патчить хукаемую DLL? Тогда получается, что надо бы, чтобы моя хук-DLL сама
     бы загружала нужную DLL. Но LoadLibrary использовать нельзя, тогда остается линковаться с патчуемой DLL, чтобы
     системный PE-загрузчик сам её загрузил, найдя её в моих зависимостях. Это плохо.
     Не может ли загрузчик хука триггериться на загрузку DLL с определенным именем?
     уточнить!!!


#endif


    CoInit coInit;

    std::wstring prjRoot  = getPath(getModuleFileName(),5);
    std::wstring inject   = prjRoot + L"\\_3dp\\uwp-injector\\build\\injector.exe";
    std::wstring dllName = getInjectDllName();


    // https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nn-shobjidl_core-iapplicationactivationmanager
    IApplicationActivationManager *pIApplicationActivationManager = 0;

    // https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance
    HRESULT hr = CoCreateInstance(
        CLSID_ApplicationActivationManager,
        NULL,
        CLSCTX_INPROC_SERVER, // CLSCTX_LOCAL_SERVER
        IID_PPV_ARGS(&pIApplicationActivationManager)
        );

    if (!SUCCEEDED(hr))
    {
        //return false;
        std::cout << "Failed to run WhatsApp\n";
        pIApplicationActivationManager = 0;
    }

    DWORD startedWhatsAppPid = 0;
    if (pIApplicationActivationManager)
    {
        // https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nf-shobjidl_core-iapplicationactivationmanager-activateapplication
        // https://cpp.hotexamples.com/examples/-/IApplicationActivationManager/ActivateApplication/cpp-iapplicationactivationmanager-activateapplication-method-examples.html
        hr = pIApplicationActivationManager->ActivateApplication( L"5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App"
                                                                , 0, AO_PRELAUNCH // AO_NONE // AO_PRELAUNCH
                                                                , &startedWhatsAppPid
                                                                );
        if (!SUCCEEDED(hr))
        {
            //return false;
            std::cout << "Failed to run WhatsApp\n";
        }
        else
        {
            // odsHandleProcessId = startedWhatsAppPid;
            CToolhelp toolhelp;
            if (!toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
            {
                std::cout << "Failed to get toolhelp snapshot (1), error: " << GetLastError() << "\n";
                return 1;
            }
        }
    }



    std::cout << "Inject  : " << to_ascii(inject) << "\n";
    std::cout << "WhatsApp: " << whatsAppExeName << "\n";
    std::cout << "Inject  : " << to_ascii(dllName) << "\n";


    std::string cmdLine = to_ascii(inject) + " " + whatsAppExeName + " " + to_ascii(dllName);

    std::cout << "Cmd   : " << cmdLine << "\n";


    system(cmdLine.c_str());

    //Sleep(3000);

    std::cout << "Resuming WhatsApp threads\n";

    if (pIApplicationActivationManager)
    {
        hr = pIApplicationActivationManager->ActivateApplication( L"5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App"
                                                                , 0, AO_NONE // AO_NONE // AO_PRELAUNCH
                                                                , &startedWhatsAppPid
                                                                );
        if (!SUCCEEDED(hr))
        {
            //return false;
            std::cout << "Failed to run WhatsApp\n";
        }

        pIApplicationActivationManager->Release();
        pIApplicationActivationManager = 0;

    }


    // Sleep(5000);
    std::cout << "Press any key to exit\n";
   
    // while (!kbhit())
    // {
    // }
    //  

    return 0;
}

