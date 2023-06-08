/*! \file
    \brief DLL для инжекта

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


#pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )
#pragma comment( lib, "e_sqlite3.lib" )


// Для линковки e_sqlite3.dll
static int (*true_sqlite3_close)(sqlite3*)    = sqlite3_close;


static DWORD (WINAPI *real_GetCurrentProcessId)(VOID) = GetCurrentProcessId;

DWORD WINAPI hooked_GetCurrentProcessId(VOID)
{
    static unsigned msgCounter = 0;
    if (!msgCounter++)
    {
        WHATSAPP_TRACE(("!!! hooked_GetCurrentProcessId\n"));
    }

    return real_GetCurrentProcessId();
}


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
#if 0
int (*org_sqlite3_exec)(
  sqlite3*,                                  /* An open database */
  const char *sql,                           /* SQL to be evaluated */
  int (*callback)(void*,int,char**,char**),  /* Callback function */
  void *,                                    /* 1st argument to callback */
  char **errmsg                              /* Error msg written here */
) = sqlite3_exec;


int hooked_sqlite3_exec(
  sqlite3* pdb,                              /* An open database */
  const char *sql,                           /* SQL to be evaluated */
  int (*callback)(void*,int,char**,char**),  /* Callback function */
  void * pv,                                 /* 1st argument to callback */
  char **errmsg                              /* Error msg written here */
)
{
    WHATSAPP_TRACE(("hooked_sqlite3_exec !!!\n"));
    return org_sqlite3_exec(pdb, sql, callback, pv, errmsg);
}
#endif

extern "C"{
SQLITE_API
int sqlite3_key(sqlite3 *db, const void *pKey, int nKey );
SQLITE_API
int sqlite3_key_v2(sqlite3 *db, const char *zDbName, const void *pKey, int nKey );
}


static int          (*org_sqlite3_open)(const char*,sqlite3**)                                           = sqlite3_open;
static int          (*org_sqlite3_open16)(const void*,sqlite3**)                                         = sqlite3_open16;
static int          (*org_sqlite3_open_v2)(const char*,sqlite3**,int,const char*)                        = sqlite3_open_v2;
static int          (*org_sqlite3_prepare)(sqlite3*,const char*,int,sqlite3_stmt**,const char**)         = sqlite3_prepare;
static int          (*org_sqlite3_prepare16)(sqlite3*,const void*,int,sqlite3_stmt**,const void**)       = sqlite3_prepare16;
static int          (*org_sqlite3_prepare_v2)(sqlite3*,const char*,int,sqlite3_stmt**,const char**)      = sqlite3_prepare_v2;
static int          (*org_sqlite3_prepare16_v2)(sqlite3*,const void*,int,sqlite3_stmt**,const void**)    = sqlite3_prepare16_v2;
static int          (*org_sqlite3_exec)(sqlite3*,const char*,sqlite3_callback,void*,char**)              = sqlite3_exec;
static const char * (*org_sqlite3_uri_key)(const char*,int)                                              = sqlite3_uri_key;
static const char * (*org_sqlite3_filename_database)(const char*)                                        = sqlite3_filename_database;
static const char * (*org_sqlite3_filename_journal)(const char*)                                         = sqlite3_filename_journal;
static const char * (*org_sqlite3_filename_wal)(const char*)                                             = sqlite3_filename_wal;
static void*        (*org_sqlite3_user_data)(sqlite3_context*)                                           = sqlite3_user_data;
static int          (*org_sqlite3_key)(sqlite3 *db, const void *pKey, int nKey )                         = sqlite3_key;
static int          (*org_sqlite3_key_v2)(sqlite3 *db, const char *zDbName, const void *pKey, int nKey ) = sqlite3_key_v2;



int          hooked_sqlite3_open(const char* pstr, sqlite3** ppdb)
{
    WHATSAPP_TRACE(("hooked sqlite3_open!\n"));
    auto res = org_sqlite3_open(pstr, ppdb);
    return res;
}

int          hooked_sqlite3_open16(const void* pv,sqlite3**ppdb)                                        
{
    WHATSAPP_TRACE(("hooked sqlite3_open16!\n"));
    return org_sqlite3_open16(pv, ppdb);
}

int          hooked_sqlite3_open_v2(const char* pstr,sqlite3** ppdb,int i,const char* pstr2)                       
{
    WHATSAPP_TRACE(("hooked sqlite3_open_v2!\n"));
    return org_sqlite3_open_v2(pstr, ppdb, i, pstr2);
}

int          hooked_sqlite3_prepare(sqlite3* pdb,const char* pstr, int i, sqlite3_stmt** ppstmt, const char** ppstr)        
{
    WHATSAPP_TRACE(("hooked sqlite3_prepare!\n"));
    return org_sqlite3_prepare(pdb, pstr, i, ppstmt, ppstr);
}

int          hooked_sqlite3_prepare16(sqlite3* pdb, const void* pv, int i, sqlite3_stmt** ppstmt, const void** ppv)      
{
    WHATSAPP_TRACE(("hooked sqlite3_prepare16!\n"));
    return org_sqlite3_prepare16(pdb, pv, i, ppstmt, ppv);
}

int          hooked_sqlite3_prepare_v2(sqlite3* pdb, const char* pstr, int i, sqlite3_stmt** ppstmt, const char** pstr2)     
{
    WHATSAPP_TRACE(("hooked sqlite3_prepare_v2!\n"));
    auto res = org_sqlite3_prepare_v2(pdb, pstr, i, ppstmt, pstr2);
    return res;
}

int          hooked_sqlite3_prepare16_v2(sqlite3* pdb,const void* pv, int i, sqlite3_stmt** ppstmt, const void** ppv)   
{
    WHATSAPP_TRACE(("hooked sqlite3_prepare16_v2!\n"));
    return org_sqlite3_prepare16_v2(pdb, pv, i, ppstmt, ppv);
}

int          hooked_sqlite3_exec(sqlite3* pdb,const char* pstr, sqlite3_callback cb, void* pv, char** ppstr)             
{
    WHATSAPP_TRACE(("hooked sqlite3_exec!\n"));
    return org_sqlite3_exec(pdb, pstr, cb, pv, ppstr);
}

const char * hooked_sqlite3_uri_key(const char* pstr, int i)                                             
{
    WHATSAPP_TRACE(("hooked sqlite3_uri_key!\n"));
    return org_sqlite3_uri_key(pstr, i);
}

const char * hooked_sqlite3_filename_database(const char* pstr)                                       
{
    WHATSAPP_TRACE(("hooked sqlite3_filename_database!\n"));
    return org_sqlite3_filename_database(pstr);
}

const char * hooked_sqlite3_filename_journal(const char* pstr)                                        
{
    WHATSAPP_TRACE(("hooked sqlite3_filename_journal!\n"));
    return org_sqlite3_filename_journal(pstr);
}

const char * hooked_sqlite3_filename_wal(const char* pstr)                                            
{
    WHATSAPP_TRACE(("hooked sqlite3_filename_wal!\n"));
    return org_sqlite3_filename_wal(pstr);
}

void*        hooked_sqlite3_user_data(sqlite3_context* pctx)                                          
{
    WHATSAPP_TRACE(("hooked sqlite3_user_data!\n"));
    return org_sqlite3_user_data(pctx);
}

int          hooked_sqlite3_key(sqlite3 *pdb, const void *pKey, int nKey )                        
{
    WHATSAPP_TRACE(("hooked sqlite3_key!\n"));
    return org_sqlite3_key(pdb, pKey, nKey );
}

int          hooked_sqlite3_key_v2(sqlite3 *db, const char *zDbName, const void *pKey, int nKey) 
{
    WHATSAPP_TRACE(("hooked sqlite3_key_v2!\n"));
    return org_sqlite3_key_v2(db, zDbName, pKey, nKey);
}


//  
//  
// int  (*open)(const char*,sqlite3**);
// int  (*open16)(const void*,sqlite3**);
// int  (*open_v2)(const char*,sqlite3**,int,const char*);
// int  (*prepare)(sqlite3*,const char*,int,sqlite3_stmt**,const char**);
// int  (*prepare16)(sqlite3*,const void*,int,sqlite3_stmt**,const void**);
// int (*prepare_v2)(sqlite3*,const char*,int,sqlite3_stmt**,const char**);
// int (*prepare16_v2)(sqlite3*,const void*,int,sqlite3_stmt**,const void**);
// int  (*exec)(sqlite3*,const char*,sqlite3_callback,void*,char**);
// const char *(*uri_key)(const char*,int);
// const char *(*filename_database)(const char*);
// const char *(*filename_journal)(const char*);
// const char *(*filename_wal)(const char*);
// void *(*user_data)(sqlite3_context*);
//  



void init_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE(("Hello debugger from WhatsApp hook!\n"));

    #if defined(DEBUG) || defined(_DEBUG)
    static const std::size_t maxHeapBlocksParsed =  4000; 
    #else
    static const std::size_t maxHeapBlocksParsed =  4000; 
    #endif

    std::vector<ModuleInfo>         modulesInfo;
    std::vector<ULONG_PTR>          heapList;
    std::vector<MemoryBlockInfo>    heapBlockList;

    {
        CToolhelp toolhelp;
        if (toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
        {
            modulesInfo = toolhelp.getModulesInfo();
        }

        heapList = toolhelp.getHeapList(GetCurrentProcessId());

        heapBlockList.reserve(heapList.size()*maxHeapBlocksParsed);


        // Suspend потоков не помогает - входит в бесконечный цикл или что-то ещё
        #if 0
        std::vector<DWORD> tids = toolhelp.getThreadList();
        toolhelp.threadsSuspendResume(tids, false);
        for(auto hid : heapList)
        {

            // std::vector<MemoryBlockInfo> hbl; hbl.reserve(maxHeapBlocksParsed);
            //  
            // DWORD processId = GetCurrentProcessId();
            // bool hblEnumRes = 
            // toolhelp.enumerateHeapBlocks( [&](const HEAPENTRY32 &he)
            //                               {
            //                                   hbl.emplace_back(MemoryBlockInfo{ (BYTE*)he.dwAddress, he.dwBlockSize, hid });
            //                                   return true;
            //                               }
            //                             , processId, hid, maxHeapBlocksParsed // spinLimit
            //                             );
            //  
            //  
            // // auto hbl = toolhelp.getHeapBlocks(GetCurrentProcessId(), hid, 1000);
            // /// auto hbl = toolhelp.getHeapBlocks(GetCurrentProcessId(), hid);
            // heapBlockList.insert(heapBlockList.end(), hbl.begin(), hbl.end());
            //  
            // WHATSAPP_TRACE(("\n-----\nHeap ID : %s\n", formatPtr((void*)hid).c_str()));
            // WHATSAPP_TRACE(("Enum blocks res  : %s\n" , (hblEnumRes ? "true" : "false")));
            // WHATSAPP_TRACE(("Number of blocks : %d\n" , (unsigned)hbl.size()));
            //  
            // std::size_t totalHeapBytes = 0;
            // for(auto b: hbl)
            // {
            //     //traceMemoryBlockInfo(b);
            //     //Sleep(1);
            //     totalHeapBytes += b.blockSize;
            // }
            //  
            // WHATSAPP_TRACE(("Total block bytes: %d\n" , (unsigned)totalHeapBytes));
            // WHATSAPP_TRACE(("\n"));

        }
        WHATSAPP_TRACE(("\n"));
        toolhelp.threadsSuspendResume(tids, true);
        #endif
    }


    ModuleInfo sqliteModuleInfo;
    if (findModuleByName(modulesInfo, L"e_sqlite3.dll", sqliteModuleInfo))
    {
        WHATSAPP_TRACE(("Found sqlite DLL\n\n"));
        traceMemoryBlockInfo(sqliteModuleInfo);
    }


    ModuleInfo foundModuleInfo;

    #if 0
    WHATSAPP_TRACE(("sqlite3_exec(1) addr: %s\n", formatPtr(sqlite3_exec).c_str()));
    if (findModuleByAddress(modulesInfo, reinterpret_cast<BYTE*>(sqlite3_exec), foundModuleInfo))
    {
        WHATSAPP_TRACE(("sqlite3_exec(1) found in\n"));
        traceMemoryBlockInfo(foundModuleInfo);
    }
    else
    {
        WHATSAPP_TRACE(("sqlite3_exec(1) NOT found in\n"));
    }
    WHATSAPP_TRACE(("\n"));

    PVOID sqlite3_exec2 = GetProcAddressFromModule("e_sqlite3.dll", "sqlite3_exec");
    WHATSAPP_TRACE(("sqlite3_exec(2) addr: %s\n", formatPtr(sqlite3_exec2).c_str()));
    if (findModuleByAddress(modulesInfo, reinterpret_cast<BYTE*>(sqlite3_exec2), foundModuleInfo))
    {
        WHATSAPP_TRACE(("sqlite3_exec(2) found in\n"));
        traceMemoryBlockInfo(foundModuleInfo);
    }
    else
    {
        WHATSAPP_TRACE(("sqlite3_exec(2) NOT found in\n"));
    }
    WHATSAPP_TRACE(("\n"));
    #endif

    //  
    // LONG lRes = DetourTransactionBegin();
    // WHATSAPP_TRACE(("DetourTransactionBegin lResult:  %ld\n", lRes));
    //  
    // lRes = DetourUpdateThread(GetCurrentThread());
    // WHATSAPP_TRACE(("DetourUpdateThread lResult:  %ld\n", lRes));
    //  
    // lRes = DetourAttach(&(PVOID&)real_GetCurrentProcessId      , hooked_GetCurrentProcessId);
    // WHATSAPP_TRACE(("DetourAttach lResult:  %ld\n", lRes));
    //  
    // lRes = DetourTransactionCommit();
    // WHATSAPP_TRACE(("DetourTransactionCommit lResult:  %ld\n", lRes));
    //  
    // DWORD pid = GetCurrentProcessId();
    // WHATSAPP_TRACE(("PID:  %d\n", pid));

    // HMODULE hDll = (HMODULE)hinstDLL;
    // std::wstring dllName = getModuleFileName(hDll);

    DetoursHookingTransaction hookingTransaction;

    LONG lRes;
    
    // хз как тут правильно скастить
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_exec", static_cast<PVOID&>(org_sqlite3_exec), static_cast<PVOID>(hooked_sqlite3_exec));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_exec", &(PVOID&)(org_sqlite3_exec), static_cast<PVOID>(hooked_sqlite3_exec));
    //lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_exec", &(PVOID&)(org_sqlite3_exec), static_cast<PVOID>(hooked_sqlite3_exec));
    //WHATSAPP_TRACE(("DetourAttachHookToDllProcHelper lResult:  %ld\n", lRes));


    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_open", &(PVOID&)(org_sqlite3_open), static_cast<PVOID>(hooked_sqlite3_open));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_open16", &(PVOID&)(org_sqlite3_open16), static_cast<PVOID>(hooked_sqlite3_open16));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_open_v2", &(PVOID&)(org_sqlite3_open_v2), static_cast<PVOID>(hooked_sqlite3_open_v2));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_prepare", &(PVOID&)(org_sqlite3_prepare), static_cast<PVOID>(hooked_sqlite3_prepare));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_prepare16", &(PVOID&)(org_sqlite3_prepare16), static_cast<PVOID>(hooked_sqlite3_prepare16));
    // // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_prepare_v2", &(PVOID&)(org_sqlite3_prepare_v2), static_cast<PVOID>(hooked_sqlite3_prepare_v2));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_prepare16_v2", &(PVOID&)(org_sqlite3_prepare16_v2), static_cast<PVOID>(hooked_sqlite3_prepare16_v2));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_exec", &(PVOID&)(org_sqlite3_exec), static_cast<PVOID>(hooked_sqlite3_exec));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_uri_key", &(PVOID&)(org_sqlite3_uri_key), static_cast<PVOID>(hooked_sqlite3_uri_key));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_filename_database", &(PVOID&)(org_sqlite3_filename_database), static_cast<PVOID>(hooked_sqlite3_filename_database));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_filename_journal", &(PVOID&)(org_sqlite3_filename_journal), static_cast<PVOID>(hooked_sqlite3_filename_journal));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_filename_wal", &(PVOID&)(org_sqlite3_filename_wal), static_cast<PVOID>(hooked_sqlite3_filename_wal));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_user_data", &(PVOID&)(org_sqlite3_user_data), static_cast<PVOID>(hooked_sqlite3_user_data));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_key", &(PVOID&)(org_sqlite3_key), static_cast<PVOID>(hooked_sqlite3_key));
    // lRes = DetourAttachHookToDllProcHelper("e_sqlite3.dll", "sqlite3_key_v2", &(PVOID&)(org_sqlite3_key_v2), static_cast<PVOID>(hooked_sqlite3_key_v2));



    // WHATSAPP_TRACE(("sqlite3_exec(3) addr: %s\n", formatPtr(org_sqlite3_exec).c_str()));
    // if (findModuleByAddress(modulesInfo, reinterpret_cast<BYTE*>(org_sqlite3_exec), foundModuleInfo))
    // {
    //     WHATSAPP_TRACE(("sqlite3_exec(3) found in\n"));
    //     traceMemoryBlockInfo(foundModuleInfo);
    // }
    // else
    // {
    //     WHATSAPP_TRACE(("sqlite3_exec(3) NOT found in\n"));
    // }
    // WHATSAPP_TRACE(("\n"));


    // https://learn.microsoft.com/en-us/windows/win32/memory/memory-management-functions#virtual-memory-functions
    // https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotect
    // https://learn.microsoft.com/en-us/windows/win32/Memory/memory-protection-constants
    // https://learn.microsoft.com/en-us/windows/win32/Memory/creating-guard-pages
    DWORD oldProtect = 0;
    BOOL vpRes = VirtualProtect( (LPVOID)sqliteModuleInfo.pbAddress, (SIZE_T)sqliteModuleInfo.blockSize, PAGE_NOACCESS, &oldProtect);

}

void deinit_hook(HINSTANCE hinstDLL)
{
    // HMODULE hDll = (HMODULE)hinstDLL;

    DetoursHookingTransaction hookingTransaction;

    //DetourDetach(&(PVOID&)org_sqlite3_exec     , hooked_sqlite3_exec);

    LONG lRes;

    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_open), static_cast<PVOID>(hooked_sqlite3_open));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_open16), static_cast<PVOID>(hooked_sqlite3_open16));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_open_v2), static_cast<PVOID>(hooked_sqlite3_open_v2));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_prepare), static_cast<PVOID>(hooked_sqlite3_prepare));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_prepare16), static_cast<PVOID>(hooked_sqlite3_prepare16));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_prepare_v2), static_cast<PVOID>(hooked_sqlite3_prepare_v2));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_prepare16_v2), static_cast<PVOID>(hooked_sqlite3_prepare16_v2));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_exec), static_cast<PVOID>(hooked_sqlite3_exec));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_uri_key), static_cast<PVOID>(hooked_sqlite3_uri_key));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_filename_database), static_cast<PVOID>(hooked_sqlite3_filename_database));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_filename_journal), static_cast<PVOID>(hooked_sqlite3_filename_journal));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_filename_wal), static_cast<PVOID>(hooked_sqlite3_filename_wal));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_user_data), static_cast<PVOID>(hooked_sqlite3_user_data));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_key), static_cast<PVOID>(hooked_sqlite3_key));
    // lRes = DetourDetach(&(PVOID&)(org_sqlite3_key_v2), static_cast<PVOID>(hooked_sqlite3_key_v2));

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


