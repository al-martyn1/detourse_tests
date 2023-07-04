WhatsApp Path    - C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2320.2.0_x64__cv1g1gvanyjgm
                   C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm

WhatsApp AppId   - 5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App
WhatsApp DB Path - "C:\Users\[User]\AppData\Local\Application Data\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\" 

Способы инжекта - https://resources.infosecinstitute.com/topic/api-hooking-and-dll-injection-on-windows/
AppInit_DLLs - реестр HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Windows
    This is done by using the LoadLibrary() function call during the DLL_PROCESS_ATTACH process of user32.dll
    F:\_github\detourse_tests\.out\msvc2019\x64\Debug\test06_dll.dll
SetWindowsHookEx
CreateRemoteThread

Basic Windows API Hooking - https://medium.com/geekculture/basic-windows-api-hooking-acb8d275e9b8

3 Effective DLL Injection Techniques for Setting API Hooks - https://www.apriorit.com/dev-blog/679-windows-dll-injection-for-api-hooks

Powerful x86/x64 Mini Hook-Engine - https://ntcore.com/files/nthookengine.htm

Windows API Hooking and DLL Injection - https://dzone.com/articles/windows-api-hooking-and-dll-injection

Full DLL Unhooking with C++ - https://www.ired.team/offensive-security/defense-evasion/how-to-unhook-a-dll-using-c++

DLL injection - https://en.wikipedia.org/wiki/DLL_injection


// https://www.makeuseof.com/windows-access-windowsapps-folder/
// Take ownership

// https://www.wintips.org/how-to-access-windowsapps-folder-windows-10-8/
// Back current permissions
// cmd (admin mode)
//  >icacls "%ProgramFiles%\WindowsApps" /save WindowsApps.acl
// restore command:
//  >icacls "%ProgramFiles%" /restore WindowsApps.acl
// Take ownership
//  >takeown /F "%ProgramFiles%\WindowsApps"
// For sub folders and files
//  >takeown /F "%ProgramFiles%\WindowsApps" /r /d y
// Assign Full Control permissions to the folder
//  >icacls "%ProgramFiles%\WindowsApps" /grant Administrators:F
//  >icacls "%ProgramFiles%\WindowsApps" /grant Администраторы:F
// For its sub folders and files
//  >icacls "%ProgramFiles%\WindowsApps" /grant Administrators:F /t
//  >icacls "%ProgramFiles%\WindowsApps" /grant Администраторы:F /t
// Finally assign the ownership of "WindowsApps" folder, back to the TrustedInstaller account,
//  >icacls "%ProgramFiles%\WindowsApps" /setowner "NT Service\TrustedInstaller"

attrib -R /S /D "%ProgramFiles%\WindowsApps"

cd "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm"
ren e_sqlite3.dll e_sqlite3_org.dll

https://www.windowsphoneinfo.com/threads/trying-to-rename-a-file-in-the-windowsapps-folder.304970/
https://droidrant.com/how-do-i-rename-the-windowsapps-folder-in-windows-10/

https://www.makeuseof.com/windows-access-windowsapps-folder/#:~:text=The%20problem%20is%20that%20a,to%20disable%20it%20in%20detail.
https://stackoverflow.com/questions/60248596/bypassing-windowsapps-folder-protection-other-than-acls
https://helpdeskgeek.com/windows-10/how-to-access-the-windowsapps-folder-in-windows-10/

https://stackoverflow.com/questions/52254719/permission-to-access-windowsapps-folder

Editing/Creating files in C:\Program Files\WindowsApps - https://superuser.com/questions/940693/editing-creating-files-in-c-program-files-windowsapps
robocopy /B /E /COPY:DAT D:\WindowsApps\xxx D:\MyTargetDir

Settings -> Storage -> Change where new content is stored -> New apps will save to

copy "C:\WinStoreTmp\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm\e_sqlite3_org.dll" "C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm\e_sqlite3_org.dll"


>rem Backup current permissions
>icacls "%ProgramFiles%\WindowsApps" /save WindowsApps.acl
>rem Take ownership
>takeown /F "%ProgramFiles%\WindowsApps"
>rem For sub folders and files
>takeown /F "%ProgramFiles%\WindowsApps" /r /d y
>rem Assign Full Control permissions to the folder
>icacls "%ProgramFiles%\WindowsApps" /grant Administrators:F
>rem For its sub folders and files
>icacls "%ProgramFiles%\WindowsApps" /grant Administrators:F /t
>rem remove Readonly attr
>attrib -R /S /D "%ProgramFiles%\WindowsApps"
>rem Rename DLL
>ren "%ProgramFiles%\WindowsApps\SomeApp\sqlite3_org.dll" "%ProgramFiles%\WindowsApps\SomeApp\sqlite3_org.dll"
Access denied

SYSTEM_PROCESS_TRUST_LABEL_ACE_TYPE
Protected Process Light
http://publications.alex-ionescu.com/Recon/Recon%202018%20-%20Unknown%20Known%20DLLs%20and%20other%20code%20integrity%20trust%20violations.pdf
https://www.youtube.com/watch?v=35L_qJNMu1A
  https://nosuchcon.orgtalks/2014/D3_05_Alex_ionescu_Breaking_protected_processes.pdf
  http://publications.alex-ionescu.com/NoSuchCon/NoSuchCon%202014%20-%20Unreal%20Mode%20-%20Breaking%20Protected%20Processes.pdf
http://publications.alex-ionescu.com/


ACE Strings - https://learn.microsoft.com/en-us/windows/win32/secauthz/ace-strings
A brief summary of the various versions of the Security Descriptor Definition Language (SDDL) - https://devblogs.microsoft.com/oldnewthing/20220510-00/?p=106640
Sandboxing Antimalware Products for Fun and Profit - https://www.elastic.co/security-labs/sandboxing-antimalware-products


https://github.com/winsiderss/systeminformer/releases/tag/v2.39

Винда 10 полеченная
  https://rutracker.org/forum/viewtopic.php?t=6364960
  https://rutracker.org/forum/viewtopic.php?t=6364674
  https://rutracker.org/forum/viewtopic.php?t=6364673

Прямое использование гостем жесткого диска хост системы - http://mirspo.narod.ru/vbox/ch09s10.html
Образы жестких дисков VHD могут быть смонтированы в Microsoft Windows Server 2008 и таких программах виртуализации, как VirtualBox и VMware. Содержимое файла VHD также можно просмотреть с помощью программы 7-Zip. 

Windows 10 Домашняя: YTMG3-N6DKC-DKB77-7M9GH-8HVX7
Windows 10 Домашняя N: 4CPRK-NM3K3-X6XXQ-RXX86-WXCHW
Windows 10 Home для одного языка: BT79Q-G7N6G-PGBYW-4YWX6-6F4BT
Windows 10 Pro: VK7JG-NPHTM-C97JM-9MPGT-3V66T
Windows 10 Pro N: 2B87N-8KFHP-DKV6R-Y2C8J-PKCKT
Windows 10 Pro для рабочих станций: DXG7C-N36C4-C4HTG-X4T3X-2YV77
Windows 10 Pro N для рабочих станций: WYPNQ-8C467-V2W6J-TX4WX-WT2RQ
Windows 10 Pro для образовательных учреждений: 8PTT6-RNW4C-6V7J2-C2D3X-MHBPB
Windows 10 Pro для образовательных учреждений N: GJTYN-HDMQY-FRR76-HVGC7-QPF8P
Windows 10 для образовательных учреждений: YNMGQ-8RYV3-4PGQ3-C8XTP-7CFBY
Windows 10 Education N: 84NGF-MHBT6-FXBX8-QWJK7-DRR8H
Windows 10 Корпоративная: XGVPP-NMH47-7TTHJ-W3FW7-8HV2C
Windows 10 Enterprise GN: FW7NV-4T673-HF4VX-9X4MM-B4H4T
Windows 10 Корпоративная N: WGGHN-J84D6-QYCPR-T7PJ7-X766F
Windows 10 Корпоративная N LTSB 2016: RW7WN-FMT44-KRGBK-G44WK-QV7YK
Windows 10 Корпоративная S: NK96Y-D9CD8-W44CQ-R8YTK-DYJWX
Windows 10 S: 3NF4D-GF9GY-63VKH-QRC3V-7QW8P
  Подробнее: https://pro-spo.ru/system/5689-universalnyj-klyuch-aktivaczii-windows

Диск отключен из-за конфликта подписей с другим диском, находящимся в сети - http://proftech19.ru/2016/02/%D0%B4%D0%B8%D1%81%D0%BA-%D0%BE%D1%82%D0%BA%D0%BB%D1%8E%D1%87%D0%B5%D0%BD-%D0%B8%D0%B7-%D0%B7%D0%B0-%D0%BA%D0%BE%D0%BD%D1%84%D0%BB%D0%B8%D0%BA%D1%82%D0%B0-%D0%BF%D0%BE%D0%B4%D0%BF%D0%B8%D1%81%D0%B5/
C:>diskpart

DISKPART> list disk
 Диск 0    В сети          232 Gбайт  1024 Kбайт
 Диск 1    Вне сети        298 Gбайт  1024 Kбайт

DISKPART> select disk 1
Выбран диск 1.

DISKPART> online disk
DiskPart успешно перевел выбранный диск в состояние «в сети».

После произведенный действий, все диски будут подключены к системе и с ними можно будет работать.

How to Decrypt WhatsApp DataBase Crypt8/12/14 Without Key Online/PC
  https://www.imyfone.com/whatsapp/decrypt-whatsapp-database-without-key/
На PC считывает с андроида - https://github.com/EliteAndroidApps/WhatsApp-Key-DB-Extractor

WhatsApp DB folder - "C:\Users\martinov\AppData\Local\Application Data\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\LocalState\" 
Where Are WhatsApp Messages Stored On PC? - https://www.techuntold.com/where-whatsapp-messages-stored/

Linux Live CD to access NTFS - Linux Mint - https://superuser.com/questions/940693/editing-creating-files-in-c-program-files-windowsapps
  Linux Mint 19.3 Cinnamon Edition (Live CD?) - https://linuxmint.com/edition.php?id=274

  >sudo parted -l
  >sudo mkdir /mnt/ntfs
  >sudo mount -t ntfs /dev/sda2 /mnt/ntfs


Debugging Tools for Windows - https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/debugger-download-tools
Debugging a UWP app using WinDbg - https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/debugging-a-uwp-app-using-windbg
  "C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\windbg.exe"
  C:\Program Files\WindowsApps\Microsoft.WinDbg_1.2306.12001.0_x64__8wekyb3d8bbwe\DbgX.Shell.exe

Windows 10 universal Windows platform (UWP) app lifecycle - https://learn.microsoft.com/en-us/windows/uwp/launch-resume/app-lifecycle
Launching, resuming, and background tasks - https://learn.microsoft.com/en-us/windows/uwp/launch-resume/

Collecting User-Mode Dumps - https://learn.microsoft.com/en-us/windows/win32/wer/collecting-user-mode-dumps

gpedit.msc
  https://learn.microsoft.com/ru-ru/troubleshoot/windows-client/system-management-components/windows-error-reporting-diagnostics-enablement-guidance
  https://datbaze.ru/windows/sistema-windows-error-reporting.html
  https://its.1c.ru/db/metod8dev/content/2924/hdoc

Тегирование EXE файлов без повреждения цифровой подписи - https://habr.com/ru/companies/alawar/articles/155365/
Инструменты для подписывания файлов и проверки подписей - https://learn.microsoft.com/ru-ru/windows/win32/seccrypto/tools-to-sign-files-and-check-signatures
MakeCat - https://learn.microsoft.com/ru-ru/windows/win32/seccrypto/makecat
