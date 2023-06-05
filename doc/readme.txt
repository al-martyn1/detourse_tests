WhatsApp Path   - C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2320.2.0_x64__cv1g1gvanyjgm
WhatsApp AppId  - 5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App

Способы инжекта - https://resources.infosecinstitute.com/topic/api-hooking-and-dll-injection-on-windows/
AppInit_DLLs - реестр HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Windows
    This is done by using the LoadLibrary() function call during the DLL_PROCESS_ATTACH process of user32.dll
SetWindowsHookEx
CreateRemoteThread

Basic Windows API Hooking - https://medium.com/geekculture/basic-windows-api-hooking-acb8d275e9b8

3 Effective DLL Injection Techniques for Setting API Hooks - https://www.apriorit.com/dev-blog/679-windows-dll-injection-for-api-hooks

Powerful x86/x64 Mini Hook-Engine - https://ntcore.com/files/nthookengine.htm

Windows API Hooking and DLL Injection - https://dzone.com/articles/windows-api-hooking-and-dll-injection

Full DLL Unhooking with C++ - https://www.ired.team/offensive-security/defense-evasion/how-to-unhook-a-dll-using-c++

DLL injection - https://en.wikipedia.org/wiki/DLL_injection

