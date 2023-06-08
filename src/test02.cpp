/*! \file
    \brief Подключение к запущеному WhatsApp (toolhelp API). SE_DEBUG_PROVELEDGE требует адмиских прав, и инжект всё равно не срабатывает - Access denied (5)
 */

#include <winsock2.h>
#include <windows.h>

#include <iostream>
#include <cctype>

#include "helpers.h"

#include "toolhelp.h"


// static const wchar_t *pStrWhatsAppExe = L"C:\\Program Files\\WindowsApps\\5319275A.WhatsAppDesktop_2.2318.2.0_x64__cv1g1gvanyjgm\\WhatsApp.exe";
static const wchar_t *pStrWhatsAppExe = L"C:\\Program Files\\WindowsApps\\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm";



//NOTE: !!! x64
static std::wstring path_mrt100_app_dll       = L"C:\\Program Files\\WindowsApps\\Microsoft.NET.Native.Runtime.2.2_2.2.28604.0_x64__8wekyb3d8bbwe";
static std::wstring path_vcruntime140_app_dll = L"C:\\Program Files\\WindowsApps\\Microsoft.VCLibs.140.00_14.0.30704.0_x86__8wekyb3d8bbwe";
// static std::wstring path_ucrtbased_dll        = L"C:\\Program Files (x86)\\Microsoft SDKs\\Windows Kits\\10\\ExtensionSDKs\\Microsoft.UniversalCRT.Debug\\10.0.19041.0\\Redist\\Debug\\x64";
static std::wstring path_ucrtbased_dll        = L"C:\\Program Files (x86)\\Windows Kits\\10\\bin\\x64\\ucrt";
static std::wstring path_api_ms_win_crt_runtime_l1_1_0_dll = L"C:\\Program Files (x86)\\Windows Kits\\10\\Redist\\10.0.19041.0\\ucrt\\DLLs\\x64";


// Пока не работает - инжект фейлиться
// Как инжектировать dll в UWP процесс
// Снова не работает, будем пробовать ещё варианты
// https://stackoverflow.com/questions/26395243/getmodulehandle-for-a-dll-in-another-process
// Ссылка на инжект - https://github.com/stephenfewer/ReflectiveDLLInjection

int main(int argc, char* argv[])
{
    
    wchar_t miscBuf[32767]; // GetEnvironmentVariable limit
    std::size_t miscBufSizeBytes  = sizeof(miscBuf);
    std::size_t miscBufSizeWchars = sizeof(miscBuf)/sizeof(miscBuf[0]);


    DWORD len = GetModuleFileNameW(0, miscBuf, miscBufSizeWchars);
    if (!len || len>=miscBufSizeWchars)
    {
        std::cout << "Failed to get exe name\n";
        return 1;
    }

    std::wstring exeName = std::wstring(miscBuf, len);

    //std::cout << "Exe name: " << to_ascii(exeName) << "\n";

    std::wstring dllName = exeName;
    std::wstring::size_type slashPos = dllName.rfind(L'\\');
    std::wstring::size_type dotPos   = dllName.rfind(L'.');
    if (dotPos>slashPos)
    {
        dllName.erase(dotPos,std::wstring::npos);
    }
    //std::cout << "Dll name (1): " << to_ascii(dllName) << "\n";
    dllName.append(L"_dll.dll");
    //std::cout << "Dll name (2): " << to_ascii(dllName) << "\n";


    len = GetEnvironmentVariableW( L"PATH", miscBuf, miscBufSizeWchars);
    if (!len)
    {
        std::cout << "Failed to get PATH env var\n";
        return 1;
    }

    std::wstring pathEnvVar = std::wstring(miscBuf, len);
    // std::cout << "PATH: " << to_ascii(pathEnvVar) << "\n";

    // check 32,767 limit
    // std::wstring newPathEnvVar = path_ucrtbased_dll + L";"
    //                            + path_api_ms_win_crt_runtime_l1_1_0_dll + L";"
    //                            + path_mrt100_app_dll + L";"
    //                            + path_vcruntime140_app_dll + L";"
    //                            + pathEnvVar;
    //  
    //  
    // if (!SetEnvironmentVariable(L"PATH", newPathEnvVar.c_str()))
    // {
    //     std::cout << "Failed to set PATH env var\n";
    //     return 1;
    // }


    DWORD pidWhatsapp = 0; //    th32ProcessID;
    
    {
        //CToolhelp toolhelp = CToolhelp(TH32CS_SNAPPROCESS);
        CToolhelp toolhelp; //  = CToolhelp(TH32CS_SNAPALL, 0);
    
        // C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\shared\winerror.h
    
        if (!toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
        {
            std::cout << "Failed to get toolhelp snapshot, error: " << GetLastError() << "\n";
            return 1;
        }
    
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(pe);
        auto processEnumRes = toolhelp.ProcessFirst(&pe);
        if (!processEnumRes)
        {
           std::cout << "ProcessFirst failed, error: " << GetLastError() << "\n";
           // 24 - ERROR_BAD_LENGTH - The program issued a command but the command length is incorrect.
        }
        while(processEnumRes)
        {
            pe.szExeFile[MAX_PATH-1] = 0;
            std::wstring exeName = &pe.szExeFile[0];
    
            // std::cout << to_ascii(exeName) << ": " << to_ascii(to_lower(exeName)) << "\n";
    
            if (to_lower(exeName)==L"whatsapp.exe")
            {
                pidWhatsapp = pe.th32ProcessID;
            }
    
            pe.dwSize = sizeof(pe);
            processEnumRes = processEnumRes = toolhelp.ProcessNext(&pe);
        }

    }

    if (pidWhatsapp!=0)
    {
        std::cout << "WhatsApp found, PID: " << pidWhatsapp << "\n";
    }


    // https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid
    // DWORD GetProcessId( [in] HANDLE Process );

    // https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess
    // HANDLE OpenProcess(
    //   [in] DWORD dwDesiredAccess,
    //   [in] BOOL  bInheritHandle,
    //   [in] DWORD dwProcessId
    // );

    // https://learn.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights
    HANDLE hWhatsApp = OpenProcess( PROCESS_CREATE_THREAD | PROCESS_VM_READ | PROCESS_VM_WRITE // DWORD dwDesiredAccess,
                                  , FALSE // bInheritHandle
                                  , pidWhatsapp
                                  );
    if (hWhatsApp==0)
    {
        std::cout << "WhatsApp process open failed, error: " << GetLastError() << "\n";
        return 1;
    }
    else
    {
        std::cout << "Got an WhatsApp handle\n";
    }

    if (!CToolhelp::EnableDebugPrivilege(TRUE))
    {
        std::cout<<"Failed to get DebugPrivilege, error: " << GetLastError() << "\n";
        // 1300 - ERROR_NOT_ALL_ASSIGNED - Not all privileges or groups referenced are assigned to the caller.
        // 5    - ERROR_ACCESS_DENIED    - Access is denied.
        // 6    - ERROR_INVALID_HANDLE   - The handle is invalid.
    }


    if (!injectDll(dllName.c_str(), hWhatsApp))
//    if (0)
    {
        std::cout<<"Failed to inject hook dll, error: " << GetLastError() << "\n";
        return 1;
    }

    std::cout<<"Hook Dll injected Ok\n";


    return 0;
}

