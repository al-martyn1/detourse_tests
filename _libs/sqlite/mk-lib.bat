rem https://stackoverflow.com/questions/9360280/how-to-make-a-lib-file-when-have-a-dll-file-and-a-header-file
rem dumpbin /EXPORTS /OUT:e_sqlite3.exports "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2319.7.0_x64__cv1g1gvanyjgm\e_sqlite3.dll"  
rem e_sqlite3.exports
gendef "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2319.7.0_x64__cv1g1gvanyjgm\e_sqlite3.dll"

lib /def:e_sqlite3.def /out:..\..\.out\msvc2019\x64\Debug\e_sqlite3.lib
lib /def:e_sqlite3.def /out:..\..\.out\msvc2019\x64\Release\e_sqlite3.lib