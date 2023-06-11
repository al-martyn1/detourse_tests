rem https://stackoverflow.com/questions/9360280/how-to-make-a-lib-file-when-have-a-dll-file-and-a-header-file
rem dumpbin /EXPORTS /OUT:e_sqlite3.exports "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2319.7.0_x64__cv1g1gvanyjgm\e_sqlite3.dll"  
rem static const wchar_t *pStrWhatsAppExe = L"C:\\Program Files\\WindowsApps\\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm";
rem e_sqlite3.exports

rem gendef "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2319.7.0_x64__cv1g1gvanyjgm\e_sqlite3.dll"
rem gendef "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm\e_sqlite3.dll"

@rem /MACHINE:{ALPHA|ARM|IX86|MIPS|MIPS16|MIPSR41XX|PPC|SH3|SH4}
@rem /MACHINE:{ARM|ARM64|ARM64EC|EBC|X64|X86}
@rem /MACHINE:
@set LIB="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64\lib.exe"
%LIB%
rem %LIB% /MACHINE:X64 /def:e_sqlite3.def /out:..\..\.out\msvc2019\x64\Debug\e_sqlite3.lib
rem %LIB% /MACHINE:X64 /def:e_sqlite3.def /out:..\..\.out\msvc2019\x64\Release\e_sqlite3.lib

%LIB% /MACHINE:X64 /def:e_sqlite3.def /out:..\..\.out\msvc2019\x64\Debug\e_sqlite3_org.lib
%LIB% /MACHINE:X64 /def:e_sqlite3.def /out:..\..\.out\msvc2019\x64\Release\e_sqlite3_org.lib
