/*! \file
    \brief Перечисляем модули и кучи для поиска указателей на нужные функции, тестируе перехват с детурс
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

#include "WinDebugMonitorImpl.h"

#include "helpers.h"

#include <../_3dp/Detours/src/detours.h>

#define SQLITE_OMIT_LOAD_EXTENSION

#include "../_3dp/sqlite/sqlite3.h"
#include "../_3dp/sqlite/sqlite3ext.h"

#pragma comment( lib, "detours.lib" )
#pragma comment( lib, "e_sqlite3.lib" )



static DWORD (WINAPI *real_GetCurrentProcessId)(VOID) = GetCurrentProcessId;

DWORD WINAPI hooked_GetCurrentProcessId(VOID)
{
    std::cout << "!!! hooked_GetCurrentProcessId\n";

    return real_GetCurrentProcessId();
}





std::string whatsAppExeName = "WhatsApp.exe";


void printMemoryBlockInfo(const ModuleInfo &mi)
{
    std::cout << "Module: " << to_ascii(mi.moduleName) << "\n";
    std::cout << "Path  : " << to_ascii(mi.moduleExeName) << "\n";

    std::cout << "Base  : " << formatPtr(mi.pbAddress) << "\n";
    std::cout << "Size  : " << formatPtr((void*)mi.blockSize) << " (" << mi.blockSize << ")\n";
    std::cout << "Next  : " << formatPtr(mi.getNextFreeAddress()) << "\n";
}

void printMemoryBlockInfo(const MemoryBlockInfo &mi)
{
    std::cout << "Base  : " << formatPtr(mi.pbAddress) << "\n";
    std::cout << "Size  : " << formatPtr((void*)mi.blockSize) << " (" << mi.blockSize << ")\n";
    std::cout << "Next  : " << formatPtr(mi.getNextFreeAddress()) << "\n";
}


int main(int argc, char* argv[])
{

    // Requires
    // @set PATH=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2320.2.0_x64__cv1g1gvanyjgm;%PATH%
    // @set PATH=C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe;%PATH%
    int sqlRes = sqlite3_close(0); // force link & e_sqlite3.dll load DLL

    BYTE* sqlite3_close_pbfnptr0 = (BYTE*)&sqlite3_close;
    BYTE* sqlite3_close_pbfnptr1 = (BYTE*)sqlite3_close;
    BYTE* sqlite3_close_pbfnptr2 = 0;
    {
        HMODULE hSqlDll = LoadLibraryA("e_sqlite3.dll");
        if (hSqlDll!=0)
        {
            sqlite3_close_pbfnptr2 = (BYTE*)GetProcAddress(hSqlDll, "sqlite3_close");
            FreeLibrary(hSqlDll);
        }
    }
    
    std::cout << "sqlite3_close(0) : " << formatPtr(sqlite3_close_pbfnptr0) << "\n";
    std::cout << "sqlite3_close(1) : " << formatPtr(sqlite3_close_pbfnptr1) << "\n";
    std::cout << "sqlite3_close(2) : " << formatPtr(sqlite3_close_pbfnptr2) << "\n";

    std::vector<ModuleInfo> modulesInfo;
    {
        CToolhelp toolhelp;
        if (toolhelp.CreateSnapshot(TH32CS_SNAPALL, 0) || !toolhelp.snapshotValid())
        {
            modulesInfo = toolhelp.getModulesInfo();
        }
    }

    std::size_t 
    blockIdx = findBlockByAddress(modulesInfo, sqlite3_close_pbfnptr0);
    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "\nsqlite3_close(0) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }

    blockIdx = findBlockByAddress(modulesInfo, sqlite3_close_pbfnptr1);
    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "\nsqlite3_close(1) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }

    blockIdx = findBlockByAddress(modulesInfo, sqlite3_close_pbfnptr2);
    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "\nsqlite3_close(2) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }

    BYTE* GetCurrentProcessId_pbfnptr0 = (BYTE*)&GetCurrentProcessId;
    BYTE* GetCurrentProcessId_pbfnptr1 = (BYTE*)GetCurrentProcessId;
    BYTE* GetCurrentProcessId_pbfnptr2 = 0;
    {
        HMODULE hSqlDll = LoadLibraryA("Kernel32.dll");
        if (hSqlDll!=0)
        {
            GetCurrentProcessId_pbfnptr2 = (BYTE*)GetProcAddress(hSqlDll, "GetCurrentProcessId");
            FreeLibrary(hSqlDll);
        }
    }
    
    std::cout << "\n";
    std::cout << "GetCurrentProcessId(0) : " << formatPtr(GetCurrentProcessId_pbfnptr0) << "\n";
    std::cout << "GetCurrentProcessId(1) : " << formatPtr(GetCurrentProcessId_pbfnptr1) << "\n";
    std::cout << "GetCurrentProcessId(2) : " << formatPtr(GetCurrentProcessId_pbfnptr2) << "\n";
    blockIdx = findBlockByAddress(modulesInfo, GetCurrentProcessId_pbfnptr1);
    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "\nGetCurrentProcessId(0) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }

    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "\nGetCurrentProcessId(1) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }

    blockIdx = findBlockByAddress(modulesInfo, GetCurrentProcessId_pbfnptr2);
    if (blockIdx!=(std::size_t)-1)
    {
        std::cout << "\nGetCurrentProcessId(2) found in:\n";
        printMemoryBlockInfo(modulesInfo[blockIdx]);
    }

    std::cout << "\n";


    DetourRestoreAfterWith();

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DetourAttach(&(PVOID&)real_GetCurrentProcessId    , hooked_GetCurrentProcessId);

    DetourTransactionCommit();


    DWORD curPid = GetCurrentProcessId();
    std::cout << "Cur PID: " << curPid << "\n";


// GetCurrentProcess
// GetCurrentProcessId

#if 0
typedef int (*sqlite3_loadext_entry)(
  sqlite3 *db,                       /* Handle to the database. */
  char **pzErrMsg,                   /* Used to set error string on failure. */
  const sqlite3_api_routines *pThunk /* Extension API function pointers. */
);

sqlite3_data_directory DATA
sqlite3_temp_directory DATA
sqlite3_version DATA

sqlite3_declare_vtab
sqlite3_enable_load_extension
sqlite3_libversion
sqlite3_libversion_number
sqlite3_load_extension

sqlite3_os_end
sqlite3_os_init

sqlite3_set_auxdata

sqlite3_user_data

sqlite3_vtab_collation
sqlite3_vtab_config
sqlite3_vtab_distinct
sqlite3_vtab_in
sqlite3_vtab_in_first
sqlite3_vtab_in_next
sqlite3_vtab_nochange
sqlite3_vtab_on_conflict
sqlite3_vtab_rhs_value

// Imports from WhatsApp.dll
sqlite3_aggregate_context
sqlite3_bind_int
sqlite3_bind_int64
sqlite3_bind_text
sqlite3_close_v2
sqlite3_column_bytes
sqlite3_column_count
sqlite3_column_int64
sqlite3_column_text
sqlite3_column_type
sqlite3_errmsg
sqlite3_exec
sqlite3_finalize
sqlite3_free
sqlite3_libversion_number
sqlite3_open
sqlite3_prepare_v2
sqlite3_step


TODO: !!!
  0) OutputDebugString - работает и с UWP
  1) Выяснить, где вообще в адресном пространстве процесса могут быть расположены какие-либо данные, пользовательские, 
     данные с кодом (модулей/DLLек), и тд и тп - уточнить!!!
  2) Найти адреса некоторых функций SQLite3 - из таблицы экспорта
     Тут надо бы перелопатить по хорошему таблицу экспорта каждой DLLки,
     Но пока просто линкуем SQLite3 либу и получаем адреса оттуда
  3) Адреса в таблице экспорта - это круто, но есть вероятность, что при вызовах они не обязательно используются.
     В SQLite3 есть куча структур с указателями на функции, и, возможно, используется что-то такое.
     Такая таблица может быть получена хз как, но изнутри либы, и тогда реальные адреса функций SQLite3 не будут
     совпадать с тем, что лежит в таблице импорта - там трамплины, которые настраиваются при загрузке DLL
     Значит, нам надо продизасмить то, что лежит по адресам экспорта, и найти, куда эти трамплины ведут
  4) а. Нашли, куда ведут трамплины - пропатчим их там.
     б. У нас есть все возможные адреса используемой памяти процесса, и есть все возможные адреса искомых функций
     Тупо обходим всю память с шагом выравнивания указателя и ищем что-то похожее на искомые адреса.
     Будет найдена скорее всего какая-то VTBL или что-то подобное, можно пропатчить адреса там, без трамплинов.
  5) Вопрос - когда загружается хук. Если хук загружается после загрузки основных ядрёных DLL, но до загрузки всех
     необходимых EXE-шнику DLL - как патчить хукаемую DLL? Тогда получается, что надо бы, чтобы моя хук-DLL сама
     бы загружала нужную DLL. Но LoadLibrary использовать нельзя, тогда остается линковаться с патчуемой DLL, чтобы
     системный PE-загрузчик сам её загрузил, найдя её в моих зависимостях. Это плохо.
     Не может ли загрузчик хука триггериться на загрузку DLL с определенным именем?
     уточнить!!!


  1) Сделать метод заморозки/разморозки всех потоков процесса, кроме текущего
  2) Научится перечислять кучи
  3) Научиться пробегать по блокам с шагом указателя и проверять содержимое
     https://stackoverflow.com/questions/18394647/can-i-check-if-memory-block-is-readable-without-raising-exception-with-c

#endif


    return 0;
}

