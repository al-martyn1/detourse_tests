/*! \file
    \brief DLL для инжекта, делаем перехват всех возможных функций sqlite

    Опция /ZW (для WinRT) находится на вкладке C/C++ - General - Consume Windows Runtime Extention
    Требует /EHsc (C/C++ - Code Generation - Enable C++ Exceptions)

 */

#define DETOUR_DEBUG

#include "trace.h"

#include <winsock2.h>
#include <windows.h>

#include "helpers.h"
#include "toolhelp.h"

#include <../_3dp/Detours/src/detours.h>

#define SQLITE_OMIT_LOAD_EXTENSION

#include "../_3dp/sqlite/sqlite3.h"
#include "../_3dp/sqlite/sqlite3ext.h"

#include "detours_helpers.h"

#include <string>
#include <vector>


// #pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )
#pragma comment( lib, "e_sqlite3.lib" )


// Для линковки e_sqlite3.dll
static int (*true_sqlite3_close)(sqlite3*)    = sqlite3_close;



#include "generated_hook\sqlite_fn_idx_defs.h"
#include "generated_hook\sqlite_fntables.h"
#include "generated_hook\sqlite_proxytypes.h"

HMODULE getOriginalSqliteHmodule()
{
    static HMODULE hMdod = GetModuleHandleA("e_sqlite3.dll");
    return hMdod;
}

FARPROC getOriginalFunctionFarprocPtr(unsigned idx)
{
    return GetProcAddress(getOriginalSqliteHmodule(), sqlite3orgFuncNames[idx]);
}

template<typename FnPtrType>
FnPtrType getOriginalFunctionPtr(unsigned idx)
{
    return reinterpret_cast<FnPtrType>(sqlite3orgFuncPointers[idx]);
}

#define SQLITE3_PROXY_HELO_TRACE(x) WHATSAPP_TRACE(x)
// #define SQLITE3_PROXY_HELO_TRACE(x) DETOURS_TRACE(x)


#define SQLITE3_PROXY_EXPORT
// __declspec(dllexport)
#define SQLITE3_PROXY_EXPORT_DATA

#include "generated_hook\sqlite_hooks.h"


void init_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE(("Hello debugger from WhatsApp init_hook!\n"));

    //DetoursHookingTransaction hookingTransaction;

    #include "generated_hook\sqlite_hooks_init.h"

    LONG lRes;

}

void deinit_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE(("Hello debugger from WhatsApp deinit_hook!\n"));
    // HMODULE hDll = (HMODULE)hinstDLL;

    // DetoursHookingTransaction hookingTransaction;

    //DetourDetach(&(PVOID&)org_sqlite3_exec     , hooked_sqlite3_exec);

    #include "generated_hook\sqlite_hooks_deinit.h"

    LONG lRes;

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
            // For correct results, DetourRestoreAfterWith should be called in the PROCESS_ATTACH portion of the DllMain function of the DLL loaded into the target process.
            DetourRestoreAfterWith();
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


