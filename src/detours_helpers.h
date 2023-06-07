#pragma once

#include "trace.h"
#include <../_3dp/Detours/src/detours.h>

// https://github.com/microsoft/detours/wiki/Reference


class DetoursHookingTransaction
{
public:

     DetoursHookingTransaction()
     {
         LONG 
         lRes = DetourTransactionBegin();
         WHATSAPP_TRACE(("DetourTransactionBegin lResult:  %ld\n", lRes));

         lRes = DetourUpdateThread(GetCurrentThread());
         WHATSAPP_TRACE(("DetourUpdateThread lResult:  %ld\n", lRes));
     }

     ~DetoursHookingTransaction()
     {
         LONG 
         lRes = DetourTransactionCommit();
         WHATSAPP_TRACE(("DetourTransactionCommit lResult:  %ld\n", lRes));
     }

}; // DetoursHookingTransaction


inline
PVOID GetProcAddressFromModule(const char *dllName, const char *fnName)
{
    // https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-functions
    HMODULE hModule = GetModuleHandleA(dllName);
    if (hModule==0)
    {
        WHATSAPP_TRACE(("DetourAttachHookToDllHelper: GetModuleHandleA(\"%s\") failed: %lu\n", (dllName?dllName:"<EXE>"), GetLastError()));
        return 0;
    }

    PVOID fnPtr = GetProcAddress(hModule, fnName);
    if (fnPtr==0)
    {
        WHATSAPP_TRACE(("DetourAttachHookToDllHelper: GetProcAddress(\"%s\") failed: %lu\n", fnName, GetLastError()));
    }

    return fnPtr;
}

inline
LONG DetourAttachHookToDllProcHelper( const char *dllName, const char *fnName, PVOID* orgFunctionPtrPtr, PVOID hookFunctionPtr)
{
    // Делает то же, что и я - ручками, но ещё пытается найти имя в дебаг символах или где-то ещё, для
    // этого, как я понял, динамически подгружает Dll, что делать нельзя в DllMain
    // https://github.com/microsoft/detours/wiki/DetourFindFunction
    // PVOID DetourFindFunction(
    //     _In_ LPCSTR pszModule,
    //     _In_ LPCSTR pszFunction
    // );

    PVOID fnPtr = GetProcAddressFromModule(dllName, fnName);
    if (fnPtr==0)
    {
        return GetLastError();
    }

    WHATSAPP_TRACE(("DetourAttachHookToDllHelper: found proc \"%s\" from \"%s\" module\n", fnName, (dllName?dllName:"<EXE>"), GetLastError()));

    *orgFunctionPtrPtr = fnPtr;

    return DetourAttach(orgFunctionPtrPtr, orgFunctionPtrPtr);

}



