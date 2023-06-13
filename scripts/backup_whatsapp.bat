@robocopy /? >robocopy.txt
@xcopy /? >xcopy.txt
@if not exist d:\WindowsAppsBackups mkdir d:\WindowsAppsBackups
@rem  /M /E /G /H /Y
@rem robocopy /E "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm" D:\WindowsAppsBackups\WindowsApps
@rem robocopy /E D:\WindowsAppsBackups\WindowsApps  D:\WindowsAppsBackups\WindowsAppsTmp

@rem /Q /Y /E /R /O
@rem xcopy /Q /Y /E /R "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm\" D:\WindowsAppsBackups\WindowsApps\
@rem xcopy /Q /Y /E /R D:\WindowsAppsBackups\WindowsApps\ D:\WindowsAppsBackups\WindowsAppsTmp\

@set WHATSAPPDIR=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm

rem https://superuser.com/questions/940693/editing-creating-files-in-c-program-files-windowsapps
if not exist D:\WindowsAppsBackups\WhatsApp robocopy /B /E /COPY:DAT "%WHATSAPPDIR%" D:\WindowsAppsBackups\WhatsApp
if not exist "%WHATSAPPDIR%_" mv "%WHATSAPPDIR%" "%WHATSAPPDIR%_"
if not exist D:\WindowsAppsBackups\WhatsApp\e_sqlite3_org.dll mv D:\WindowsAppsBackups\WhatsApp\e_sqlite3.dll   D:\WindowsAppsBackups\WhatsApp\e_sqlite3_org.dll
copy /Y ..\.out\msvc2019\x64\Debug\e_sclite3.dll  D:\WindowsAppsBackups\WhatsApp\e_sqlite3.dll
robocopy /B /E /COPY:DAT D:\WindowsAppsBackups\WhatsApp "%WHATSAPPDIR%"

rem robocopy /B /E /COPY:DAT D:\MyTargetDir D:\WindowsApps\xxx