// INI: ProxyImplArrayNamesPrefix, FunctionPtrTypeFormat, GetOriginalFunctionPtrFuncTemplateName, getOriginalFunctionFarprocPtrFuncNameinline
HMODULE getOriginalKernel32Hmodule()
{
    static HMODULE hMdod = GetModuleHandleA("kernel32.dll");
    return hMdod;
}

inline
FARPROC getOriginalKernel32FunctionFarprocPtr(unsigned idx)
{
    return GetProcAddress(getOriginalKernel32Hmodule(), fnTableKernel32Names[idx]);
}

template<typename FnPtrType>
FnPtrType getOriginalKernel32FunctionPtr(unsigned idx)
{
    return reinterpret_cast<FnPtrType>(fnTableKernel32Pointers[idx]);
}

