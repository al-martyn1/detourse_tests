/*! \file
    \brief DLL для инжекта, делаем перехват CreateFile2, и всякого из kernel32
 */

#define DETOUR_DEBUG

#include "trace.h"

#include <winsock2.h>
#include <windows.h>
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

#include "helpers.h"
#include "toolhelp.h"
#include "simple_bin_signature_match.h"

#include <../_3dp/Detours/src/detours.h>
#include "../_3dp/sqlite/sqlite3.h"
#include "../_3dp/sqlite/sqlite3ext.h"

#include "generated_hook/sqlite_proxytypes.h"


#include "detours_helpers.h"

#include <string>
#include <vector>
#include <cstring>
#include <unordered_set>


// #pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )


// [114812] CreateFile2(C:\Users\martinov\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\emojidict.db-wal)
// C:\Users\martinov\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\tmp\ 

HANDLE hLog = INVALID_HANDLE_VALUE;

inline
void log_print( char const * const format, ... )
{
    va_list args;
    int     len;
    char    *buffer;

    if (hLog==INVALID_HANDLE_VALUE)
    {
        return;
    }

    // retrieve the variable arguments
    va_start( args, format );

    len = _vscprintf( format, args ) // _vscprintf doesn't count
                                + 1; // terminating '\0'

    buffer = (char*)malloc( len * sizeof(char) );
    if ( 0 != buffer )
    {
        vsprintf( buffer, format, args ); // C4996
        // Note: vsprintf is deprecated; consider using vsprintf_s instead
        // puts( buffer );
        //OutputDebugStringA(buffer);
        WriteFile(hLog, buffer, (DWORD)std::strlen(buffer), 0, 0);
        free( buffer );
    }
    va_end( args );
}

#define WHATSAPP_TRACE2(x) do{ debug_print x ; log_print x ; } while(0)

#define SQLITE3_PROXY_HELO_TRACE(x) WHATSAPP_TRACE2(x)

// https://github.com/microsoft/detours/wiki/OverviewInterception


sqlite3_key_fn_ptr_t   sqlite3_key_fn_ptr  = 0;
sqlite3_open_fn_ptr_t  sqlite3_open_fn_ptr = 0;

sqlite3_key_fn_ptr_t   copy_of_sqlite3_key_fn_ptr  = 0;
sqlite3_open_fn_ptr_t  copy_of_sqlite3_open_fn_ptr = 0;

using namespace simple_bin_signature_match;

#include "code_signature_sqlite3_key.h"
#include "code_signature_sqlite3_open.h"


// https://github.com/microsoft/detours/wiki/Using-Detours
// https://github.com/microsoft/detours/wiki/OverviewInterception

// int sqlite3_key_v2(
//   sqlite3 *db,                   /* Database to be rekeyed */
//   const char *zDbName,           /* Name of the database */
//   const void *pKey, int nKey     /* The key */
// );


int hook_sqlite3_key(sqlite3* db, const void* pKey, int nKey)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_key"));

    if (db)
    {
        SQLITE3_PROXY_HELO_TRACE(("DB ptr: %s\n", formatPtr(db).c_str() ));
    }

    SQLITE3_PROXY_HELO_TRACE(("Key len: %d\n", nKey ));
    SQLITE3_PROXY_HELO_TRACE(("Key ptr: %s\n", formatPtr(pKey).c_str() ));
    if (!pKey)
    {
        SQLITE3_PROXY_HELO_TRACE(("Key    : %s\n", "<NULL>" ));
    }
    else
    {
        SQLITE3_PROXY_HELO_TRACE(("Key    : %s\n", dumpData((const std::uint8_t*)pKey, nKey).c_str() ));
    }

    return sqlite3_key_fn_ptr(db, pKey, nKey);
}

int hook_sqlite3_open(const char* pcStr, sqlite3** ppDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_open"));
    //return sqlite3_open_fn_ptr(pcStr, ppDb);

    if (ppDb)
    {
        *ppDb = 0;
    }
    
    return SQLITE_NOMEM;
}


void init_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE2(("Hello debugger from WhatsApp init_hook!\n"));

    hLog = CreateFile2( L"C:\\Users\\martinov\\AppData\\Local\\Packages\\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\\LocalState\\tmp\\inter.log"
                      , GENERIC_READ|GENERIC_WRITE
                      , FILE_SHARE_READ
                      , CREATE_ALWAYS
                      , 0 // LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams
                      );

    if (hLog==INVALID_HANDLE_VALUE)
    {
        WHATSAPP_TRACE2(("Failed to open log!\n"));
    }
    else
    {
        // Write UTF-8 BOM to proper autodetect encoding
        static const std::uint8_t bom[] = { 0xEF, 0xBB, 0xBF };
        WriteFile(hLog, bom, (DWORD)3, 0, 0);
    }

    CToolhelp toolhelp;
    if (!toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
    {
        WHATSAPP_TRACE2(("Failed to get toolhelp snapshot (1), error: %d!\n", GetLastError()));
        return;
    }


    std::vector<ModuleInfo> modulesInfo = toolhelp.getModulesInfo();

    using namespace simple_bin_signature_match;


    #include "code_signature_sqlite3_key.h"

    static std::unordered_set<std::string> whatsapps = {  /* "whatsapp.exe", "whatsapp.dll", */  "whatsappnative.dll" };

    for(const auto &mi: modulesInfo)
    {
        //WHATSAPP_TRACE2(("Module: %s (%s)\n", to_ascii(mi.moduleName).c_str(), to_ascii(mi.moduleExeName).c_str() ));

        std::string modNameAsciiLower = to_lower(to_ascii(mi.moduleName));
        if (whatsapps.find(modNameAsciiLower)==whatsapps.end())
        {
            continue;
        }

        
        sqlite3_key_fn_ptr  = (sqlite3_key_fn_ptr_t )findUniqueSignatureMatch(code_signature_sqlite3_key , mi.pbAddress, mi.blockSize );
        //sqlite3_open_fn_ptr = (sqlite3_open_fn_ptr_t)findUniqueSignatureMatch(code_signature_sqlite3_open, mi.pbAddress, mi.blockSize );

        if (sqlite3_key_fn_ptr)
        {
            WHATSAPP_TRACE2(("Found sqlite3_key\n"));
        }
        if (sqlite3_open_fn_ptr)
        {
            WHATSAPP_TRACE2(("Found sqlite3_open\n"));
        }

        break;

    }

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    LONG detRes = 0;

    copy_of_sqlite3_key_fn_ptr  = sqlite3_key_fn_ptr ;
    copy_of_sqlite3_open_fn_ptr = sqlite3_open_fn_ptr;

    if (sqlite3_key_fn_ptr )
    {
        WHATSAPP_TRACE2(("Detouring sqlite3_key\n"));
        WHATSAPP_TRACE2(("Original proc: %s\n", formatPtr((void*)sqlite3_key_fn_ptr).c_str()));
        WHATSAPP_TRACE2(("Prolog (sqlite3_key)  : %s\n", dumpData((const std::uint8_t*)sqlite3_key_fn_ptr , 20).c_str() ));
        detRes = DetourAttach(&(PVOID&)sqlite3_key_fn_ptr , (PVOID)hook_sqlite3_key);
        WHATSAPP_TRACE2(("Detoured proc: %s\n", formatPtr((void*)sqlite3_key_fn_ptr).c_str()));
        if (detRes)
        {
            WHATSAPP_TRACE2(("Detouring failed: %d\n", detRes));
        }
    }

    if (sqlite3_open_fn_ptr)
    {
        WHATSAPP_TRACE2(("Detouring sqlite3_open\n"));
        WHATSAPP_TRACE2(("Original proc: %s\n", formatPtr((void*)sqlite3_open_fn_ptr).c_str()));
        WHATSAPP_TRACE2(("Prolog (sqlite3_open) : %s\n", dumpData((const std::uint8_t*)sqlite3_open_fn_ptr, 20).c_str() ));
        detRes = DetourAttach(&(PVOID&)sqlite3_open_fn_ptr, (PVOID)hook_sqlite3_open);
        WHATSAPP_TRACE2(("Detoured proc: %s\n", formatPtr((void*)sqlite3_open_fn_ptr).c_str()));
        if (detRes)
        {
            WHATSAPP_TRACE2(("Detouring failed: %d\n", detRes));
        }
    }

    WHATSAPP_TRACE2(("init_hook done\n"));

    DetourTransactionCommit();

    WHATSAPP_TRACE2(("After commit\n", detRes));

    if (sqlite3_key_fn_ptr)
    {
        WHATSAPP_TRACE2(("Detoured proc (sqlite3_key) : %s\n", formatPtr((void*)sqlite3_key_fn_ptr).c_str()));
        WHATSAPP_TRACE2(("Prolog org location (sqlite3_key)  : %s\n", dumpData((const std::uint8_t*)copy_of_sqlite3_key_fn_ptr , 20).c_str() ));
        WHATSAPP_TRACE2(("Prolog trampoline   (sqlite3_key)  : %s\n", dumpData((const std::uint8_t*)sqlite3_key_fn_ptr , 20).c_str() ));
    }

    if (sqlite3_open_fn_ptr)
    {
        WHATSAPP_TRACE2(("Detoured proc (sqlite3_open): %s\n", formatPtr((void*)sqlite3_open_fn_ptr).c_str()));
        WHATSAPP_TRACE2(("Prolog org location (sqlite3_open) : %s\n", dumpData((const std::uint8_t*)copy_of_sqlite3_open_fn_ptr, 20).c_str() ));
        WHATSAPP_TRACE2(("Prolog trampoline   (sqlite3_open) : %s\n", dumpData((const std::uint8_t*)sqlite3_open_fn_ptr, 20).c_str() ));
    }

}

void deinit_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE(("Hello debugger from WhatsApp deinit_hook!\n"));

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    if (sqlite3_key_fn_ptr)
    {
        DetourDetach(&(PVOID&)sqlite3_key_fn_ptr, (PVOID)hook_sqlite3_key);
    }

    if (sqlite3_open_fn_ptr)
    {
        DetourDetach(&(PVOID&)sqlite3_open_fn_ptr, (PVOID)hook_sqlite3_open);
    }

    DetourTransactionCommit();

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


