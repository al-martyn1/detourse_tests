/*! \file
    \brief DLL для инжекта, делаем перехват CreateFile2, и всякого из kernel32, для проверки, заодно выводим адрес, откуда вызвали. Было интересно, откуда с какими параметрами оно вызывается.
 */

#define DETOUR_DEBUG

#include "trace.h"

#include <winsock2.h>
#include <windows.h>
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

#include "helpers.h"
#include "toolhelp.h"

#include <../_3dp/Detours/src/detours.h>

#include "detours_helpers.h"

#include <string>
#include <vector>


// #pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )


#include "generated_hooks_kernel32\kernel32_fn_idx_defs.h"
#include "generated_hooks_kernel32\kernel32_fntables.h"
#include "generated_hooks_kernel32\kernel32_proxytypes.h"

#include "generated_hooks_kernel32\kernel32_getprocptrfuncs.h"


#define KERNEL32_HOOK_TRACE(x) WHATSAPP_TRACE(x)
// #define SQLITE3_PROXY_HELO_TRACE(x) DETOURS_TRACE(x)


#define KERNEL32_HOOK_EXPORT
#define KERNEL32_HOOK_EXPORT_DATA

inline
void printReturnAddress(const char* title, void* pv)
{
    std::vector<ModuleInfo> modulesInfo;
    CToolhelp toolhelp;
    if (toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
    {
        modulesInfo = toolhelp.getModulesInfo();
    }

    std::size_t 
    blockIdx = findBlockByAddress(modulesInfo, (BYTE*)pv);
    if (blockIdx!=(std::size_t)-1)
    {
        const ModuleInfo &mi = modulesInfo[blockIdx];
        //std::cout << "sqlite3_close(1) found in:\n";
        //KERNEL32_HOOK_TRACE(("CreateFile2(%s)\n", to_ascii(lpFileName).c_str()));
        // printMemoryBlockInfo(modulesInfo[blockIdx]);
        int diff = (BYTE*)pv - mi.pbAddress;
        KERNEL32_HOOK_TRACE(("%s: called from %s (%s), offset from module: %d", title, to_ascii(mi.moduleName).c_str(), formatPtr(pv).c_str(), diff ));
    }

    // void printMemoryBlockInfo(const ModuleInfo &mi)
    // {
    //     std::cout << "Module: " << to_ascii(mi.moduleName) << "\n";
    //     std::cout << "Path  : " << to_ascii(mi.moduleExeName) << "\n";



}


// https://learn.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2010/64ez38eh(v=vs.100)?redirectedfrom=MSDN

#define KERNEL32_HOOK_HANDLE_CREATEFILE2()  \
                                            \
            do                              \
            {                               \
                void * pCaller = _ReturnAddress();          \
                KERNEL32_HOOK_TRACE(("CreateFile2(%s)\n", to_ascii(lpFileName).c_str())); \
                printReturnAddress("CreateFile2", pCaller); \
                                                            \
            } while(0)





#include "generated_hooks_kernel32\kernel32_hooks.h"


void init_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE(("Hello debugger from WhatsApp init_hook!\n"));

    //DetoursHookingTransaction hookingTransaction;

    #include "generated_hooks_kernel32\kernel32_hooks_init.h"

    LONG lRes;

}

void deinit_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE(("Hello debugger from WhatsApp deinit_hook!\n"));
    // HMODULE hDll = (HMODULE)hinstDLL;

    // DetoursHookingTransaction hookingTransaction;

    //DetourDetach(&(PVOID&)org_sqlite3_exec     , hooked_sqlite3_exec);

    #include "generated_hooks_kernel32\kernel32_hooks_deinit.h"

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


