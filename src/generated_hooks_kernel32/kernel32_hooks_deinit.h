DetourTransactionBegin(); DetourUpdateThread(GetCurrentThread());

DetourDetach(&(PVOID&)fnTableKernel32Pointers[KERNEL32_HOOK_FN_IDX_CREATEFILE2], (PVOID)hook_CreateFile2);


DetourTransactionCommit();

