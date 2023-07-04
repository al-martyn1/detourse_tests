/*! \file
    \brief DLL для инжекта, делаем перехват CreateFile2, и всякого из kernel32
 */

#define DETOUR_DEBUG

#include "trace.h"

#include <winsock2.h>
#include <windows.h>
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

#include "helpers.h"
#include "toolhelp.h"
#include "match.h"

#include <../_3dp/Detours/src/detours.h>

#include "detours_helpers.h"

#include <string>
#include <vector>
#include <cstring>
#include <unordered_set>


// #pragma comment( lib, "windowsapp.lib" )
#pragma comment( lib, "detours.lib" )


// [114812] CreateFile2(C:\Users\martinov\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\emojidict.db-wal)
// C:\Users\martinov\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\tmp\ 

HANDLE hLog = INVALID_HANDLE_VALUE;

inline
void log_print( char const * const format, ... )
{
    va_list args;
    int     len;
    char    *buffer;

    if (hLog==INVALID_HANDLE_VALUE)
    {
        return;
    }

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
        //OutputDebugStringA(buffer);
        WriteFile(hLog, buffer, (DWORD)std::strlen(buffer), 0, 0);
        free( buffer );
    }
    va_end( args );
}

#define WHATSAPP_TRACE2(x) do{ debug_print x ; log_print x ; } while(0)



void init_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE2(("Hello debugger from WhatsApp init_hook!\n"));

    hLog = CreateFile2( L"C:\\Users\\martinov\\AppData\\Local\\Packages\\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\\LocalState\\tmp\\inter.log"
                      , GENERIC_READ|GENERIC_WRITE
                      , FILE_SHARE_READ
                      , CREATE_ALWAYS
                      , 0 // LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams
                      );

    if (hLog==INVALID_HANDLE_VALUE)
    {
        WHATSAPP_TRACE2(("Failed to open log!\n"));
    }
    else
    {
        // Write UTF-8 BOM to proper autodetect encoding
        static const std::uint8_t bom[] = { 0xEF, 0xBB, 0xBF };
        WriteFile(hLog, bom, (DWORD)3, 0, 0);
    }

    CToolhelp toolhelp;
    if (!toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
    {
        WHATSAPP_TRACE2(("Failed to get toolhelp snapshot (1), error: %d!\n", GetLastError()));
        return;
    }


    // toolhelp.enumerateModules( [&](const MODULEENTRY32 &me)
    //                            {
    //                                // moduleInfoList.emplace_back(me);
    //                                return true; // allow continue
    //                            }
    //                          );

    std::vector<ModuleInfo> modulesInfo = toolhelp.getModulesInfo();


    #include "code_signature_sqlite3_key.h"

    static std::unordered_set<std::string> whatsapps = { "whatsapp.exe", "whatsapp.dll", "whatsappnative.dll" };

    for(const auto &mi: modulesInfo)
    {
        WHATSAPP_TRACE2(("Module: %s (%s)\n", to_ascii(mi.moduleName).c_str(), to_ascii(mi.moduleExeName).c_str() ));

        std::string modNameAsciiLower = to_lower(to_ascii(mi.moduleName));
        if (whatsapps.find(modNameAsciiLower)==whatsapps.end())
        {
            continue;
        }

        const std::uint8_t *pRawData = mi.pbAddress;
        std::size_t rawDataLen = mi.blockSize;

        std::size_t matchCount = 0;

        std::size_t matchPos = 0;
        do
        {
            matchPos = findMemMatch(code_signature_sqlite3_key, pRawData, rawDataLen);
            if (matchPos!=(std::size_t )-1)
            {
                const std::uint8_t *pMatchPos = pRawData + matchPos;
                // WHATSAPP_TRACE2(("Found match, addr: %s, module: %s\n", formatPtr(pMatchPos).c_str(), to_ascii(mi.moduleName).c_str() ));
                WHATSAPP_TRACE2(("Found match, addr: %s\n", formatPtr(pMatchPos).c_str() ));
                pRawData   += matchPos+1;
                rawDataLen -= matchPos+1;
                ++matchCount;
            }
        }
        while(matchPos!=(std::size_t)-1);

        if (matchCount)
        {
            WHATSAPP_TRACE2(("Match count: %d\n", (unsigned)matchCount ));
        }

    }

}

void deinit_hook(HINSTANCE hinstDLL)
{
    WHATSAPP_TRACE(("Hello debugger from WhatsApp deinit_hook!\n"));

}


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved )  // reserved
{
    if (DetourIsHelperProcess())
    {
        return TRUE;
    }

    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
            // For correct results, DetourRestoreAfterWith should be called in the PROCESS_ATTACH portion of the DllMain function of the DLL loaded into the target process.
            DetourRestoreAfterWith();
            init_hook(hinstDLL);

            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
        
            if (lpvReserved != nullptr)
            {
                break; // do not do cleanup if process termination scenario
            }
            
         // Perform any necessary cleanup.

            deinit_hook(hinstDLL);

            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.}
}


