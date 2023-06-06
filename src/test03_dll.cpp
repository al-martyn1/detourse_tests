/*! \file
    \brief DLL для инжекта

    Опция /ZW (для WinRT) находится на вкладке C/C++ - General - Consume Windows Runtime Extention
    Требует /EHsc (C/C++ - Code Generation - Enable C++ Exceptions)

 */

#define DETOUR_DEBUG

#include "trace.h"

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

#include <../_3dp/Detours/src/detours.h>


// // https://github.com/microsoft/Windows-universal-samples/blob/main/Samples/MessageDialog/cpp/pch.h
// #include <collection.h>
// #include <ppltasks.h>

// https://www.c-sharpcorner.com/article/hello-world-with-universal-windows-platform-in-cpp/

#define SQLITE_OMIT_LOAD_EXTENSION

#include "../_3dp/sqlite/sqlite3.h"
#include "../_3dp/sqlite/sqlite3ext.h"


#pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )
#pragma comment( lib, "e_sqlite3.lib" )

//  Kernel32.lib


// WhatsApp.dll
// sqlite3_aggregate_context
// sqlite3_bind_int
// sqlite3_bind_int64
// sqlite3_bind_text
// sqlite3_close_v2
// sqlite3_column_bytes
// sqlite3_column_count
// sqlite3_column_int64
// sqlite3_column_text
// sqlite3_column_type
// sqlite3_errmsg
// sqlite3_exec
// sqlite3_finalize
// sqlite3_free
// sqlite3_libversion_number
// sqlite3_open
// sqlite3_prepare_v2
// sqlite3_step
// sqlite3_user_data

// WhatsAppNative.dll



// using namespace SDKTemplate;
//  
// using namespace Windows::UI::Popups;
// using namespace Windows::UI::Xaml;
// using namespace Windows::UI::Xaml::Controls;
// using namespace Windows::UI::Xaml::Navigation;

// SQLITE_API 
// int sqlite3_close(sqlite3*);
// SQLITE_API 
// int sqlite3_close_v2(sqlite3*);

static int (*true_sqlite3_close)(sqlite3*)    = sqlite3_close;
static int (*true_sqlite3_close_v2)(sqlite3*) = sqlite3_close_v2;
static int (*true_sqlite3_exec)(
  sqlite3*,                                  /* An open database */
  const char *sql,                           /* SQL to be evaluated */
  int (*callback)(void*,int,char**,char**),  /* Callback function */
  void *,                                    /* 1st argument to callback */
  char **errmsg                              /* Error msg written here */
) = sqlite3_exec;

static int (*true_sqlite3_prepare_v2)(
  sqlite3 *db,            /* Database handle */
  const char *zSql,       /* SQL statement, UTF-8 encoded */
  int nByte,              /* Maximum length of zSql in bytes. */
  sqlite3_stmt **ppStmt,  /* OUT: Statement handle */
  const char **pzTail     /* OUT: Pointer to unused portion of zSql */
) = sqlite3_prepare_v2;


// sqlite3_exec
// sqlite3_prepare
// sqlite3_prepare16
// sqlite3_prepare16_v2
// sqlite3_prepare16_v3
// sqlite3_prepare_v2
// sqlite3_prepare_v3


int hacked_sqlite3_close(sqlite3* psq3)
{
    DETOUR_TRACE(("!!! hacked_sqlite3_close\n"));
    // DebugBreak();
    return true_sqlite3_close(psq3);
}

int hacked_sqlite3_close_v2(sqlite3* psq3)
{
    DETOUR_TRACE(("!!! hacked_sqlite3_close_v2\n"));
    // DebugBreak();
    return true_sqlite3_close_v2(psq3);
}

int hacked_sqlite3_exec(
  sqlite3* psq3,                                  /* An open database */
  const char *sql,                           /* SQL to be evaluated */
  int (*callback)(void*,int,char**,char**),  /* Callback function */
  void * pv,                                    /* 1st argument to callback */
  char **errmsg                              /* Error msg written here */
)
{
    DETOUR_TRACE(("!!! hacked_sqlite3_exec\n"));
    // DebugBreak();
    return true_sqlite3_exec(psq3, sql, callback, pv, errmsg);
}

int hacked_sqlite3_prepare_v2(
  sqlite3 *db,            /* Database handle */
  const char *zSql,       /* SQL statement, UTF-8 encoded */
  int nByte,              /* Maximum length of zSql in bytes. */
  sqlite3_stmt **ppStmt,  /* OUT: Statement handle */
  const char **pzTail     /* OUT: Pointer to unused portion of zSql */
)
{
    DETOUR_TRACE(("!!! hacked_sqlite3_prepare_v2\n"));
    // DebugBreak();
    return true_sqlite3_prepare_v2(db, zSql, nByte, ppStmt, pzTail);
}


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
        //DebugBreak();
     
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

    DETOUR_TRACE(("Hello debugger!\n"));
    DetourRestoreAfterWith();

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DetourAttach(&(PVOID&)true_sqlite3_close       , hacked_sqlite3_close);
    DetourAttach(&(PVOID&)true_sqlite3_close_v2    , hacked_sqlite3_close_v2);
    DetourAttach(&(PVOID&)true_sqlite3_exec        , hacked_sqlite3_exec);
    DetourAttach(&(PVOID&)true_sqlite3_prepare_v2  , hacked_sqlite3_prepare_v2);

    DetourTransactionCommit();


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
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DetourDetach(&(PVOID&)true_sqlite3_close      , hacked_sqlite3_close);
    DetourDetach(&(PVOID&)true_sqlite3_close_v2   , hacked_sqlite3_close_v2);
    DetourDetach(&(PVOID&)true_sqlite3_exec       , hacked_sqlite3_exec);
    DetourDetach(&(PVOID&)true_sqlite3_prepare_v2 , hacked_sqlite3_prepare_v2);
    //DetourDetach(&(PVOID&)TrueSleep, TimedSleep);

    DetourTransactionCommit();
    

    HMODULE hDll = (HMODULE)hinstDLL;
}


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{
    if (DetourIsHelperProcess())
    {
        return TRUE;
    }


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


