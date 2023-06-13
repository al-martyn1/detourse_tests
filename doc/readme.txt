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

