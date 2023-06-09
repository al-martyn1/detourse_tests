/*! \file
    \brief Запускатель WhatsApp и инжектора хука test07_dll. Тест поиска по бинарной сигнатуре
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


int main(int argc, char* argv[])
{

    simple_bin_signature_match::testSignatureMatch();

    // return 0;

    //std::size_t blockIdx = (std::size_t)-1;

    // Requires
    // @set PATH=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2320.2.0_x64__cv1g1gvanyjgm;%PATH%
    // @set PATH=C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe;%PATH%
    // static const wchar_t *pStrWhatsAppExe = L"C:\\Program Files\\WindowsApps\\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm";


    CoInit coInit;


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

