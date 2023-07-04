#pragma once

// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l?view=msvc-170
#define _CRT_SECURE_NO_WARNINGS
#include <winsock2.h>
#include <windows.h>
#include <debugapi.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>


inline
void debug_print( char const * const format, ... )
{
    va_list args;
    int     len;
    char    *buffer;

    // retrieve the variable arguments
    va_start( args, format );

    len = _vscprintf( format, args ) // _vscprintf doesn't count
                                + 1; // terminating '\0'

    buffer = (char*)malloc( len * sizeof(char) );
    if ( 0 != buffer )
    {
        vsprintf( buffer, format, args ); // C4996
        // Note: vsprintf is deprecated; consider using vsprintf_s instead
        // puts( buffer );
        OutputDebugStringA(buffer);
        free( buffer );
    }
    va_end( args );
}


// #define DETOUR_TRACE(x) debug_print x
// #define DETOUR_BREAK()  __debugbreak()

#define DETOUR_TRACE(x) 
#define DETOUR_BREAK()



#define WHATSAPP_TRACE(x) debug_print x



        // DETOUR_TRACE(("ReadProcessMemory(idh@%p..%p) failed: %lu\n",
        //               pbModule, pbModule + sizeof(idh), GetLastError()));
        // return NULL;
