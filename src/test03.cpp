/*! \file
    \brief Используем ReflectiveDLLInjection/inject.x64.exe для инжекта нашей DLL. Перетаскивать код оттуда лень, делаем тут просто лаунчер для нашей DLL с поиском нужного PID.
 */

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <cctype>

#include "helpers.h"

#include "toolhelp.h"


static const wchar_t *pStrWhatsAppExe = L"C:\\Program Files\\WindowsApps\\5319275A.WhatsAppDesktop_2.2318.2.0_x64__cv1g1gvanyjgm\\WhatsApp.exe";



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

// Рантаймы (или аналогичная шляпа для сборки в UWP)
// C:\Documents and Settings\martinov\AppData\Local\VirtualStore\Program Files (x86)\Microsoft SDKs\Windows\v8.1\ExtensionSDKs\Microsoft.VCLibs\12.0\References\CommonConfiguration\neutral\platform.winmd
// C:\Documents and Settings\martinov\Local Settings\VirtualStore\Program Files (x86)\Microsoft SDKs\Windows\v8.1\ExtensionSDKs\Microsoft.VCLibs\12.0\References\CommonConfiguration\neutral\platform.winmd
// C:\Program Files (x86)\Microsoft SDKs\Windows\v8.1\ExtensionSDKs\Microsoft.VCLibs\12.0\References\CommonConfiguration\neutral\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Tools\MSVC\14.16.27023\lib\x86\store\references\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\VC\vcpackages\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023\lib\x86\store\references\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\vcpackages\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.16.27023\lib\x86\store\references\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.20.27508\lib\x86\store\references\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\lib\x86\store\references\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\lib\x86\store\references\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x86\store\references\platform.winmd
// C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\store\references\platform.winmd
// C:\Users\martinov\AppData\Local\Application Data\VirtualStore\Program Files (x86)\Microsoft SDKs\Windows\v8.1\ExtensionSDKs\Microsoft.VCLibs\12.0\References\CommonConfiguration\neutral\platform.winmd
// C:\Users\martinov\AppData\Local\VirtualStore\Program Files (x86)\Microsoft SDKs\Windows\v8.1\ExtensionSDKs\Microsoft.VCLibs\12.0\References\CommonConfiguration\neutral\platform.winmd
// C:\Users\martinov\Local Settings\VirtualStore\Program Files (x86)\Microsoft SDKs\Windows\v8.1\ExtensionSDKs\Microsoft.VCLibs\12.0\References\CommonConfiguration\neutral\platform.winmd


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

    std::wstring exeName  = std::wstring(miscBuf, len);
    std::wstring exePath  = getPath(exeName);
    std::wstring prjRoot  = getPath(exeName,5);
    std::wstring inject   = prjRoot + L"\\_3dp\\ReflectiveDLLInjection\\bin\\" 
#ifdef WIN_X64
	L"inject.x64.exe"
#else
#ifdef WIN_X86
	"inject.exe"
#else WIN_ARM
	L"inject.arm.exe";
#endif
    L"unknown"
#endif
    ;


    std::cout << "Exe name: " << to_ascii(exeName) << "\n";
    std::cout << "Exe path: " << to_ascii(exePath) << "\n";
    std::cout << "Prj root: " << to_ascii(prjRoot) << "\n";
    std::cout << "Inject  : " << to_ascii(inject) << "\n";


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


    char pidBuf[256];
    // https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170
    sprintf(pidBuf, "%u", pidWhatsapp);
    std::string pidStr = pidBuf;

    std::cout << "Inject: " << to_ascii(inject) << "\n";
    std::cout << "PID   : " << pidStr << "\n";
    std::cout << "Inject: " << to_ascii(dllName) << "\n";

    std::string cmdLine = to_ascii(inject) + " " + pidStr + " " + to_ascii(dllName);

    std::cout << "Cmd   : " << cmdLine << "\n";

    system(cmdLine.c_str());


    return 0;
}

