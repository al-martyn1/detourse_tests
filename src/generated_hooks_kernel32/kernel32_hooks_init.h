DetourTransactionBegin(); DetourUpdateThread(GetCurrentThread());

fnTableKernel32Pointers[KERNEL32_HOOK_FN_IDX_CREATEFILE2] = getOriginalKernel32FunctionFarprocPtr(KERNEL32_HOOK_FN_IDX_CREATEFILE2); DetourAttach(&(PVOID&)fnTableKernel32Pointers[KERNEL32_HOOK_FN_IDX_CREATEFILE2], (PVOID)hook_CreateFile2);


DetourTransactionCommit();

