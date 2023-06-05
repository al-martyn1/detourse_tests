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
#include "helpers.h"

#include <../_3dp/Detours/src/detours.h>

#define SQLITE_OMIT_LOAD_EXTENSION

#include "../_3dp/sqlite/sqlite3.h"
#include "../_3dp/sqlite/sqlite3ext.h"


#pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )
#pragma comment( lib, "e_sqlite3.lib" )


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





void init_hook(HINSTANCE hinstDLL)
{

    DETOUR_TRACE(("Hello debugger!\n"));

    HMODULE hDll = (HMODULE)hinstDLL;
    std::wstring dllName = getModuleFileName(hDll);
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


