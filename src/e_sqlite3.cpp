/*! \file
    \brief DLL для подмены

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

#include <string>
#include <vector>

#pragma comment( lib, "e_sqlite3_org.lib" )


#include "e_sqlite3/sqlite_defs_config.h"


#include "e_sqlite3/sqlite_fn_idx_defs.h"
#include "e_sqlite3/sqlite_fntables.h"
#include "e_sqlite3/sqlite_proxytypes.h"


HMODULE getOriginalSqliteHmodule()
{
    static HMODULE hMdod = LoadLibraryA("e_sqlite3_org.dll");
    return hMdod;
}

template<typename FnPtrType>
FnPtrType getOriginalFunctionPtr(unsigned idx)
{
    // not safe for multithreading
    if (sqlite3orgFuncPointers[idx]==0)
    {
        sqlite3orgFuncPointers[idx] = GetProcAddress(getOriginalSqliteHmodule(), sqlite3orgFuncNames[idx]);
    }

    return reinterpret_cast<FnPtrType>(sqlite3orgFuncPointers[idx]);
}


#define SQLITE3_PROXY_HELO_TRACE(x) WHATSAPP_TRACE(x)
// #define SQLITE3_PROXY_HELO_TRACE(x) DETOURS_TRACE(x)



#define SQLITE3_PROXY_EXPORT
// __declspec(dllexport)
#define SQLITE3_PROXY_EXPORT_DATA



#if !defined(SQLITE3_PROXY_CONFIG_FORWARDDATA) || SQLITE3_PROXY_CONFIG_FORWARDDATA==0

#define SQLITE3_PROXY_DATA_SQLITE3_DATA_DIRECTORY()  \
    char *sqlite3_data_directory = 0

#define SQLITE3_PROXY_DATA_SQLITE3_TEMP_DIRECTORY()  \
    char *sqlite3_temp_directory = 0

#define SQLITE3_PROXY_DATA_SQLITE3_VERSION()         \
    const char sqlite3_version[] = SQLITE_VERSION

#endif


/*

C-language Interface Specification for SQLite - https://www.sqlite.org/capi3ref.html

Result and Error Codes - https://www.sqlite.org/rescode.html

Ellipsis function: mprintf       - vmprintf(const char*,va_list);
Ellipsis function: xsnprintf     - xvsnprintf(int,char*,const char*,va_list);
Ellipsis function: test_control  - нет va_args версии
Ellipsis function: db_config     - sqlite3_db_config - нет va_args версии
Ellipsis function: log           - нет va_args версии
Ellipsis function: vtab_config   - нет va_args версии
Ellipsis function: str_appendf   - str_vappendf(sqlite3_str*, const char *zFormat, va_list);
Ellipsis function: config        - нет va_args версии
Ellipsis function: snprintf      - vsnprintf(int,char*,const char*, va_list);

SQLITE_ERROR

*/
// PROXY_SQLITE3_CONFIG_IMPL();

#include "e_sqlite3/sqlite3_internal_defs.h"

#if 0
#define SQLITE_OK           0   /* Successful result */
/* beginning-of-error-codes */
#define SQLITE_ERROR        1   /* Generic error */
#define SQLITE_INTERNAL     2   /* Internal logic error in SQLite */
#endif



#if !defined(SQLITE3_PROXY_CONFIG_FORWARDELLIPSIS) || SQLITE3_PROXY_CONFIG_FORWARDELLIPSIS==0


#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_CONFIG()       return SQLITE_ERROR

#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_DB_CONFIG()    return SQLITE_ERROR

#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_LOG()          do{} while(0)

#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_MPRINTF()           \
/*SQLITE_API char *sqlite3_mprintf(const char *zFormat, ...)*/  \
/*{*/                                                           \
  va_list ap;                                                   \
  char *z;                                                      \
 /* #ifndef SQLITE_OMIT_AUTOINIT */                             \
   /* if( sqlite3_initialize() ) return 0; */                   \
 /* #endif */                                                   \
  va_start(ap, zFormat);                                        \
  z = sqlite3_vmprintf(zFormat, ap);                            \
  va_end(ap);                                                   \
  return z                                                      \
/*}*/

#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_SNPRINTF()          \
 /* char *sqlite3_snprintf(int n, char *zBuf, const char *zFormat, ...) */ \
 /* { */                                                        \
  StrAccum acc;                                                 \
  va_list ap;                                                   \
  if( n<=0 ) return zBuf;                                       \
 /* #ifdef SQLITE_ENABLE_API_ARMOR */                           \
 /*   if( zBuf==0 || zFormat==0 ) { */                          \
 /*     (void)SQLITE_MISUSE_BKPT; */                            \
 /*     if( zBuf ) zBuf[0] = 0; */                              \
 /*     return zBuf; */                                         \
 /*   } */                                                      \
 /* #endif */                                                   \
  sqlite3StrAccumInit(&acc, 0, zBuf, n, 0);                     \
  va_start(ap,zFormat);                                         \
  sqlite3_str_vappendf(&acc, zFormat, ap);                      \
  va_end(ap);                                                   \
  zBuf[acc.nChar] = 0;                                          \
  return zBuf /* ; */                                           \
 /* } */ 


#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_STR_APPENDF()       \
 /* SQLITE_API void sqlite3_str_appendf(StrAccum *p, const char *zFormat, ...) */ \
 /* { */                                                        \
  va_list ap;                                                   \
  va_start(ap,zFormat);                                         \
  sqlite3_str_vappendf(p, zFormat, ap);                         \
  va_end(ap)                                                    \
 /* } */ 

#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_TEST_CONTROL()   return SQLITE_OK

#define SQLITE3_PROXY_ELLIPSIS_IMPL_SQLITE3_VTAB_CONFIG()    return SQLITE_OK


#endif // #if !defined(SQLITE3_PROXY_CONFIG_FORWARDELLIPSIS) || SQLITE3_PROXY_CONFIG_FORWARDELLIPSIS==0




#include "e_sqlite3/sqlite_proxybodies.h"







BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{

    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
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
            
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.}
}


