#pragma once

#include <winsock2.h>
#include <windows.h>

#include <Objbase.h>
#include <combaseapi.h>

#pragma comment( lib, "Ole32.lib" )


class CoInit
{

public:

    HRESULT hr = S_OK;

    CoInit(DWORD  dwCoInit = COINIT_MULTITHREADED)
    {
        hr = CoInitializeEx(0, dwCoInit);    
    }

    ~CoInit()
    {
        if (hr==S_OK || hr==S_FALSE)
        {
            CoUninitialize();
        }
    }


};