KERNEL32_HOOK_EXPORT HANDLE WINAPI hook_CreateFile2(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams)
{
    KERNEL32_HOOK_TRACE(("!!! Hook called: %s\n", "CreateFile2"));
    CreateFile2_fn_ptr_t orgFnPtr = getOriginalKernel32FunctionPtr<CreateFile2_fn_ptr_t>(KERNEL32_HOOK_FN_IDX_CREATEFILE2);
    #if defined(KERNEL32_HOOK_HANDLE_CREATEFILE2)
        KERNEL32_HOOK_HANDLE_CREATEFILE2();
    #endif
    return orgFnPtr(lpFileName, dwDesiredAccess, dwShareMode, dwCreationDisposition, pCreateExParams);
}


