/*! \file
    \brief Используем ReflectiveDLLInjection/inject.x64.exe для инжекта нашей DLL. Перетаскивать код оттуда лень, делаем тут просто лаунчер для нашей DLL с поиском нужного PID.
 */

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <Shobjidl.h>
#include <shobjidl_core.h>

#include <iostream>
#include <cctype>
#include <vector>

#include "helpers.h"

#include "coinit.h"

#include "toolhelp.h"

// #include "ods_capture.h"

#include "WinDebugMonitorImpl.h"



int main(int argc, char* argv[])
{
    CWinDebugMonitorImpl logMonitor;

    // Sleep(5000);
   
    for(auto i=0u; i!=20; ++i)
    {
        OutputDebugStringA("Hello through OutputDebugStringA\n");
        Sleep(500);
    }

    return 0;
}

