#pragma once

#include <winsock2.h>
#include <windows.h>
#include <tlhelp32.h>

#include <string>
#include <utility>
#include <algorithm>
#include <cstdint>

#if defined(_WIN64) || defined(WIN64)

    #define WIN_X64

#elif defined(_M_ARM) || defined(_M_ARM64)

    #define WIN_ARM

#else 

    #define WIN_X86

#endif


//----------------------------------------------------------------------------
inline
BYTE* getModuleNextFreeAddr(const MODULEENTRY32 &me)
{
    return (BYTE*)me.modBaseAddr+me.modBaseSize;
}

//----------------------------------------------------------------------------
inline
std::string formatPtr(const void* ptr)
{
    static const char digits[17] = "0123456789ABCDEF";
    const std::size_t ptrSize   = sizeof(ptr);
    const std::size_t ptrDigits = 2*ptrSize;

    std::string strRes; strRes.reserve(ptrDigits);

    std::uintptr_t uintPtr = reinterpret_cast<std::uintptr_t>(ptr);

    for(std::size_t i=0; i!=ptrDigits; ++i)
    {
        auto d = uintPtr&0xF;
        uintPtr >>= 4;
        strRes.append(1, digits[d]);
    }

    std::reverse(strRes.begin(), strRes.end());

    return strRes;
}
//----------------------------------------------------------------------------

inline
std::wstring getModuleFileName(HMODULE hModule = 0)
{
    wchar_t buf[4096];
    std::size_t bufSizeBytes  = sizeof(buf);
    std::size_t bufSizeWchars = sizeof(buf)/sizeof(buf[0]);
    DWORD len = GetModuleFileNameW(0, buf, bufSizeWchars);
    if (!len || len>=bufSizeWchars)
    {
        return std::wstring();
    }

    return std::wstring(buf, len);
}

//----------------------------------------------------------------------------
inline
std::wstring getInjectDllName()
{
    std::wstring exeName  = getModuleFileName();
    std::wstring dllName = exeName;
    std::wstring::size_type slashPos = dllName.rfind(L'\\');
    std::wstring::size_type dotPos   = dllName.rfind(L'.');
    if (dotPos>slashPos)
    {
        dllName.erase(dotPos,std::wstring::npos);
    }
    dllName.append(L"_dll.dll");
    return dllName;
}

//----------------------------------------------------------------------------
inline
std::wstring getPath(const std::wstring &s)
{
    std::wstring::size_type slashPos = s.find_last_of( L"\\/" );
    return std::wstring(s, 0, slashPos);
}

//----------------------------------------------------------------------------
inline
std::wstring getPath(std::wstring s, std::size_t upCount)
{
    for(auto i=0u; i!=upCount; ++i)
    {
        s = getPath(s);
    }

    return s;
}

//----------------------------------------------------------------------------
template<typename StringType>
inline
StringType to_lower(StringType s)
{
    using CharType = typename StringType::value_type;
    //typedef typename StringType::value_type
    //StringType res; res.reserve(s.size())
    //return str ? to_ascii(std::wstring(str)) : std::string();

    for(auto &ch: s)
    {
        if (ch>=(CharType)'A' && ch<=(CharType)'Z')
            ch = ch - (CharType)'A' + (CharType)'a';
    }

    return s;
}

template<typename StringType>
inline
StringType to_upper(StringType s)
{
    using CharType = typename StringType::value_type;
    //StringType res; res.reserve(s.size())
    //return str ? to_ascii(std::wstring(str)) : std::string();

    for(auto &ch: s)
    {
        if (ch>=(CharType)'a' && ch<=(CharType)'z')
            ch = ch - (CharType)'a' + (CharType)'A';
    }

    return s;
}

//----------------------------------------------------------------------------
inline
std::string to_ascii(const char* str)
{
    return str ? std::string(str) : std::string();
}

inline
std::string to_ascii(const std::string &str)
{
    return str;
}

inline
std::string to_ascii(const std::wstring &str)
{
    std::string strRes; strRes.reserve(str.size());
    for(auto ch : str)
        strRes.append(1, (char)(unsigned char)ch);
    return strRes;
}

inline
std::string to_ascii(const wchar_t* str)
{
    return str ? to_ascii(std::wstring(str)) : std::string();
}

//------------------------------
inline
std::wstring to_wide(const wchar_t* str)
{
    return str ? std::wstring(str) : std::wstring();
}

inline
std::wstring to_wide(const std::wstring &str)
{
    return str;
}

inline
std::wstring to_wide(const std::string &str)
{
    std::wstring strRes; strRes.reserve(str.size());
    for(auto ch : str)
        strRes.append(1, (char)ch);
    return strRes;
}

inline
std::wstring to_wide(const char* str)
{
    return str ? to_wide(std::string(str)) : std::wstring();
}

//------------------------------
template<typename ResultStringType, typename StringType>
ResultStringType to_string_type(StringType s)
{
    if constexpr (sizeof(typename ResultStringType::value_type)>1)
        return to_wide(s);
    else
        return to_ascii(s);
}



//----------------------------------------------------------------------------
inline
bool injectDll( const wchar_t *dllName, HANDLE hProcess /* , DWORD pid */ )
   {
    if (!dllName) return false;
    int nameLen = lstrlenW(dllName);
    nameLen *= sizeof(wchar_t);
    int nameLenBufSize = nameLen + sizeof(wchar_t);

    void *remoteBuf = (void*)VirtualAllocEx( hProcess
                                           , 0
                                           , nameLenBufSize
                                           , MEM_COMMIT
                                           , PAGE_READWRITE
                                           );
    if (!remoteBuf) return false;

    if (!WriteProcessMemory( hProcess
                           , remoteBuf
                           , (void*)dllName
                           , nameLenBufSize, 0 ) )
       {
        VirtualFreeEx( hProcess, remoteBuf, 0, MEM_RELEASE );
        return false;
       }

    FARPROC loadLibraryAddr = ::GetProcAddress( GetModuleHandleA( "Kernel32.dll" ), "LoadLibraryW" );
    if (!loadLibraryAddr)
       {
        VirtualFreeEx( hProcess, remoteBuf, 0, MEM_RELEASE );
        return false;
       }
    
    DWORD rc = 0;
    HANDLE hRemoteThread = CreateRemoteThread( hProcess
                                             , 0
                                             , 0 /*stackSize*/
                                             , (LPTHREAD_START_ROUTINE)loadLibraryAddr
                                             , remoteBuf
                                             , 0
                                             , &rc 
                                             );
    if ( hRemoteThread == NULL )
       {
        VirtualFreeEx( hProcess, remoteBuf, 0, MEM_RELEASE );
        return false;
       }

    // ждем завершения удаленного потока 10 секунд.
    // можно INFINITE, но есть риск зависнуть   
    rc = WaitForSingleObject( hRemoteThread, 10000 );
    VirtualFreeEx( hProcess, remoteBuf, 0, MEM_RELEASE );
    CloseHandle( hRemoteThread );

    // поток отработал нормально
    if (rc==WAIT_OBJECT_0) return true;
    // завершения не дождались, беда
    return false;
   }
