
#include <winsock2.h>
#include <windows.h>

#include <iostream>


ctatic const wchar_t *pStrWhatsAppExe = "C:\\Program Files\\WindowsApps\\5319275A.WhatsAppDesktop_2.2318.2.0_x64__cv1g1gvanyjgm\\WhatsApp.exe";

int main(int argc, char* argv[])
{
    
    wchar_t cmdLine[16384];
    std::wstring strWhatsAppExe = pStrWhatsAppExe;

    // Размер буфера лень проверять - его хватает
    strWhatsAppExe.copy(cmdLine, strWhatsAppExe.size(), 0);


    PROCESS_INFORMATION pi = { 0 };

    STARTUPINFO si = { 0 };
    si.cb          = sizeof(STARTUPINFO);
    /*
    si.lpReserved  = 0;
    si.lpDesktop   = 0;
    si.lpTitle     = 0;
    si.dwX         = 0;
    si.dwY         = 0;
    si.dwXSize     = 0;
    si.dwYSize     = 0;
    si.dwXCountChars = 0;
    si.dwYCountChars = 0;
    si.dwFillAttribute  = 0;
    */
    si.dwFlags = 0;
    si.lpReserved  = 0;
    si.cbReserved2 = 0;
    si.lpReserved2 = 0;

    BOOL cpRes = CreateProcessW ( 0 // appName     // lpApplicationName
                               , cmdLine     // lpCommandLine
                               , 0           // lpProcessAttributes
                               , 0           // lpThreadAttributes
                               , FALSE       // bInheritHandles
                               , CREATE_SUSPENDED // dwCreationFlags
                               , 0           // lpEnvironment
                               , 0           // lpCurrentDirectory
                               , &si
                               , &pi
                               );

    if (!cpRes)
    {
        ::std::cout<<"CreateProcess failed, error: "<<GetLastError()<<"\n";
        return 0;
    }

    if (!injectDll( dllName, pi.hProcess /* , pi.dwProcessId */ ))
    {
        #if 1
        ::std::cout<<"Failed to inject hook dll\n";
        #else
        MessageBox( 0, _T("Failed to inject hook dll."), _T("S63dn.exe"), MB_OK | MB_ICONERROR );
        #endif
        return 0;
    }

    ResumeThread( pi.hThread );


    return 0;
}

