#pragma once

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
        strRes.append(1, (wchar_t)ch);
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

    // ���� ���������� ���������� ������ 10 ������.
    // ����� INFINITE, �� ���� ���� ���������   
    rc = WaitForSingleObject( hRemoteThread, 10000 );
    VirtualFreeEx( hProcess, remoteBuf, 0, MEM_RELEASE );
    CloseHandle( hRemoteThread );

    // ����� ��������� ���������
    if (rc==WAIT_OBJECT_0) return true;
    // ���������� �� ���������, ����
    return false;
   }