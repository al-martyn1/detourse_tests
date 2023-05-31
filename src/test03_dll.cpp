/*! \file
    \brief DLL для инжекта

    Опция /ZW (для WinRT) находится на вкладке C/C++ - General - Consume Windows Runtime Extention
    Требует /EHsc (C/C++ - Code Generation - Enable C++ Exceptions)

 */

#include <winsock2.h>
#include <windows.h>

#include <windowsstoragecom.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Storage.Streams.h>

// https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/nf-fileapifromapp-createfilefromappw
#include <fileapifromapp.h>

// https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfile2
#include <fileapi.h>

#include "helpers.h"

// // https://github.com/microsoft/Windows-universal-samples/blob/main/Samples/MessageDialog/cpp/pch.h
// #include <collection.h>
// #include <ppltasks.h>

// https://www.c-sharpcorner.com/article/hello-world-with-universal-windows-platform-in-cpp/

#include "../_3dp/sqlite/sqlite3.h"
#include "../_3dp/sqlite/sqlite3ext.h"


#pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )
#pragma comment( lib, "e_sqlite3.lib" )

//  Kernel32.lib


// using namespace SDKTemplate;
//  
// using namespace Windows::UI::Popups;
// using namespace Windows::UI::Xaml;
// using namespace Windows::UI::Xaml::Controls;
// using namespace Windows::UI::Xaml::Navigation;


HANDLE hLog = INVALID_HANDLE_VALUE;

void createLogFile(const std::wstring &name)
{
    // // hLog = CreateFileW(name.c_str(), GENERIC_WRITE, FILE_SHARE_READ, 0 /*sec attrs*/, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 /*hTpl*/);
    // // hLog = CreateFileFromAppW(name.c_str(), GENERIC_WRITE, FILE_SHARE_READ, 0 /*sec attrs*/, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 /*hTpl*/);
    // hLog = CreateFileFromAppW(L"InjectLog.txt", GENERIC_WRITE, FILE_SHARE_READ, 0 /*sec attrs*/, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 /*hTpl*/);
    hLog = CreateFile2(name.c_str(), GENERIC_WRITE, FILE_SHARE_READ, CREATE_ALWAYS, 0);
    if (hLog==INVALID_HANDLE_VALUE)
    {
        //char *ptr = 
        DebugBreak();
     
        // MessageDialog^ msg = ref new MessageDialog("No internet connection has been found.");
     
        // MessageBoxW(0, L"Text", L"Caption", 0);
     
    }
     
    std::string hello = "Hello world!\r\n";
    WriteFile(hLog, (LPCVOID)hello.c_str(), hello.size(), 0, 0);

    //  
    // //hStdin = GetStdHandle(STD_INPUT_HANDLE);

    // https://learn.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/consume-apis
    // https://learn.microsoft.com/en-us/windows/win32/api/windowsstoragecom/
    // IID_IStorageItemHandleAccess;
    // MIDL_INTERFACE("5CA296B2-2C25-4D22-B785-B885C8201E6A")


};

void init_hook(HINSTANCE hinstDLL)
{
    HMODULE hDll = (HMODULE)hinstDLL;
    std::wstring dllName = getModuleFileName(hDll);
    // std::wstring dllPath = getPath(dllName);
    // std::wstring logName = dllPath + 

    std::wstring logName = dllName;
    std::wstring::size_type slashPos = logName.rfind(L'\\');
    std::wstring::size_type dotPos   = logName.rfind(L'.');
    if (dotPos>slashPos)
    {
        logName.erase(dotPos,std::wstring::npos);
    }

    logName.append(L".log");

    createLogFile(logName);
}

void deinit_hook(HINSTANCE hinstDLL)
{
    HMODULE hDll = (HMODULE)hinstDLL;
}


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
            init_hook(hinstDLL);

            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
        
            if (lpvReserved != nullptr)
            {
                break; // do not do cleanup if process termination scenario
            }
            
         // Perform any necessary cleanup.

            deinit_hook(hinstDLL);

            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.}
}


