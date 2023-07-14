/*! \file
    \brief Запускатель WhatsApp и инжектора хука test08_dll. Заодно проверяем поиск сигнатуры на ватсапповской DLL. Тут же пробую открыть базу с найденым ключем. Лень было отдельно делать
 */

/*
    Для запуска из другого места нужны
    mrt100_app.dll

C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.4_1.4.24201.0_x64__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.4_1.4.24201.0_x86__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.7_1.7.25531.0_x64__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.7_1.7.27422.0_x64__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.7_1.7.27422.0_x86__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.1_2.1.26424.0_x64__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.1_2.1.26424.0_x86__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.2_2.2.27328.0_x64__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.2_2.2.28604.0_x64__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.2_2.2.28604.0_x86__8wekyb3d8bbwe\mrt100_app.dll
C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\arm\mrt100_app.dll
C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\x64\mrt100_app.dll
C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\x86\mrt100_app.dll
C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\arm\ilc\lib\Runtime\mrt100_app.dll
C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x64\ilc\lib\Runtime\mrt100_app.dll
C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x86\ilc\lib\Runtime\mrt100_app.dll

    VCRUNTIME140_APP.dll

C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.29231.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30035.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.32530.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.32530.0_x86__8wekyb3d8bbwe\vcruntime140_app.dll
C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\arm\ilc\lib\MSCRT\vcruntime140_app.dll
C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x64\ilc\lib\MSCRT\vcruntime140_app.dll
C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x86\ilc\lib\MSCRT\vcruntime140_app.dll
C:\Windows\SystemApps\MicrosoftWindows.Client.CBS_cw5n1h2txyewy\vcruntime140_app.dll
C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2913_none_fb268c537eb5989b\CBS\vcruntime140_app.dll
C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2913_none_fb268c537eb5989b\n\CBS\vcruntime140_app.dll
C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.3031_none_fb8a0ba97e6a99b5\CBS\vcruntime140_app.dll
C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.3031_none_fb8a0ba97e6a99b5\n\CBS\vcruntime140_app.dll

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

#include "simple_bin_signature_match.h"

#include <../_3dp/Detours/src/detours.h>

#define SQLITE_OMIT_LOAD_EXTENSION

// #include "../_3dp/sqlite/sqlite3.h"
// #include "../_3dp/sqlite/sqlite3ext.h"
#include "sqlite3.h"
#include "sqlite3ext.h"

#pragma comment( lib, "detours.lib" )
// #pragma comment( lib, "e_sqlite3.lib" )



static DWORD (WINAPI *real_GetCurrentProcessId)(VOID) = GetCurrentProcessId;

DWORD WINAPI hooked_GetCurrentProcessId(VOID)
{
    std::cout << "!!! hooked_GetCurrentProcessId\n";

    return real_GetCurrentProcessId();
}


int sqlite_exec_callback(void *a_param, int argc, char **argv, char **column)
{
    std::cout << "Exec called:";
    for (int i=0; i< argc; i++)
    {
        std::cout << " " << argv[i];
    }
    std::cout << "\n";
    return 0;
}



std::string whatsAppExeName = "WhatsApp.exe";


int main(int argc, char* argv[])
{

    using namespace simple_bin_signature_match;

    #if 0

    testSignatureMatch();
    // return 0;


    const wchar_t *whatsappnativedllName = L"c:\\program files\\windowsapps\\5319275a.whatsappdesktop_2.2324.6.0_x64__cv1g1gvanyjgm\\whatsappnative.dll";

    // https://stackoverflow.com/questions/13288452/what-is-the-purpose-of-the-win32-createfile2-api-call
    HANDLE hFile = CreateFile2( whatsappnativedllName
                      , GENERIC_READ
                      , FILE_SHARE_READ
                      , OPEN_EXISTING
                      , 0 // LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams
                      );

    if (hFile==INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to read 'whatsappnative.dll'\n";
        return 0;
    }

    DWORD fileSizeHi = 0;
    DWORD fileSizeLo = GetFileSize(hFile, &fileSizeHi);
    if (fileSizeLo==INVALID_FILE_SIZE)
    {
        std::cout << "Failed to get 'whatsappnative.dll' file size\n";
        CloseHandle(hFile);
        return 0;
    }

    std::vector<std::uint8_t> whatsappnativedllData = std::vector<std::uint8_t>((std::size_t)fileSizeLo, 0);
    if (!ReadFile(hFile, (LPVOID)&whatsappnativedllData[0], fileSizeLo, 0, 0))
    {
        std::cout << "Failed to read 'whatsappnative.dll' file\n";
        CloseHandle(hFile);
        return 0;
    }

    CloseHandle(hFile);

    

    #include "code_signature_sqlite3_key.h"
    #include "code_signature_sqlite3_open.h"

    const std::uint8_t *pRawDataBase = &whatsappnativedllData[0];
    const std::uint8_t *pRawData     = pRawDataBase;
    std::size_t rawDataLen = whatsappnativedllData.size();

    if (findUniqueSignatureMatch(code_signature_sqlite3_key, pRawData, rawDataLen))
    {
        std::cout << "Found single signature match (key)\n";
    }
    else
    {
        std::cout << "No signature (key) matches found\n";
    }

    if (findUniqueSignatureMatch(code_signature_sqlite3_open, pRawData, rawDataLen))
    {
        std::cout << "Found single signature match (open)\n";
    }
    else
    {
        std::cout << "No signature (open) matches found\n";
    }


    return 0;
    #endif

    // sqlite3* pDb = 0;
    // sqlite3_open("testdb", &pDb);
    // sqlite3_filename name1 = sqlite3_db_filename(pDb, 0);
    // sqlite3_filename name2 = sqlite3_db_filename(pDb, "main");
    //  
    // return 0;

    // DB name : C:\Users\martinov\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\concur.db-journal
    // DB name : C:\Users\martinov\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\syncd.db-journal
    // DB name : C:\Users\martinov\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\emojidict.db-journal
    // Key len: 32
    // Key    : DF 89 38 A3 F0 16 60 8C 29 CD 3B D2 48 76 EC 8D 00 CC 99 7A B0 D6 40 8C 64 01 25 C0 7B A5 76 84

    // abprops.db          
    // abprops.db-shm      
    // abprops.db-wal      
    // axolotl.db          
    // axolotl.db-shm      
    // axolotl.db-wal      
    // concur.db           
    // concur.db-shm       
    // concur.db-wal       
    // contacts.db         
    // contacts.db-shm     
    // contacts.db-wal     
    // emojidict.db        
    // emojidict.db-shm    
    // emojidict.db-wal    
    // messages.db         
    // messages.db-shm     
    // messages.db-wal     
    // settings.db         
    // settings.db-shm     
    // settings.db-wal     
    // syncd.db            
    // syncd.db-shm        
    // syncd.db-wal        

    std::string dbRootPath = "C:\\Users\\martinov\\AppData\\Local\\Packages\\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\\LocalState\\";

    static const std::uint8_t key[32] = { 0xDF, 0x89, 0x38, 0xA3, 0xF0, 0x16, 0x60, 0x8C, 0x29, 0xCD, 0x3B, 0xD2, 0x48, 0x76, 0xEC, 0x8D, 0x00, 0xCC, 0x99, 0x7A, 0xB0, 0xD6, 0x40, 0x8C, 0x64, 0x01, 0x25, 0xC0, 0x7B, 0xA5, 0x76, 0x84 };
    sqlite3* pDb = 0;
    int sqRes = sqlite3_open((dbRootPath+"messages.db").c_str(), &pDb);
    if (sqRes!=SQLITE_OK)
    {
        std::cout << "Open DB failed\n";
    }
    else
    {
        sqRes = sqlite3_key_v2(pDb, (dbRootPath+"messages.db").c_str(), (const void*)&key[0], 32);
        if (sqRes!=SQLITE_OK)
        {
            std::cout << "sqlite3_key_v2 failed\n";
        }
    }

    //int sqlite_exec_callback(void*,int,char**,char**)

    // https://stackoverflow.com/questions/1805982/use-of-sqlite3-exec

    // https://cpp.hotexamples.com/examples/-/-/sqlite3_exec/cpp-sqlite3_exec-function-examples.html

    char *errMsg = 0;
    //sqRes = sqlite3_exec(pDb, ".schema;", sqlite_exec_callback, (void*)0, &errMsg);
    //sqRes = sqlite3_exec(pDb, ".tables;", sqlite_exec_callback, (void*)0, &errMsg);
    sqRes = sqlite3_exec(pDb, "SELECT * FROM sqlite_schema", sqlite_exec_callback, (void*)0, &errMsg);
    if (sqRes!=SQLITE_OK)
    {
        std::cout << "Exec failed\n";
        if (errMsg)
        {
             std::cout << "Error: " << errMsg << "\n";
        }
    }

    return 0;



    CoInit coInit;

    // auto coInitDump = dumpData((const std::uint8_t*)&coInit, 20);
    // std::cout << "Dump data test: " << coInitDump.c_str() << "\n";
    //  
    // return 0;


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
            return 1;
        }
        else
        {
        }
    }

    std::wstring exeName  = getModuleFileName();
    std::wstring prjRoot  = getPath(exeName,5);
    std::wstring inject   = prjRoot + L"\\_3dp\\uwp-injector\\build\\injector.exe";
    std::wstring dllName  = getInjectDllName();


    std::string cmdLine = to_ascii(inject) + " " + whatsAppExeName + " " + to_ascii(dllName);
    std::cout << "Cmd   : " << cmdLine << "\n";

    system(cmdLine.c_str());


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
            return 1;
        }

        pIApplicationActivationManager->Release();
        pIApplicationActivationManager = 0;
    }


    return 0;
}

