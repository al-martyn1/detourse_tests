
#include <winsock2.h>
#include <windows.h>

#include <iostream>
#include <cctype>

#include "helpers.h"


static const wchar_t *pStrWhatsAppExe = L"C:\\Program Files\\WindowsApps\\5319275A.WhatsAppDesktop_2.2318.2.0_x64__cv1g1gvanyjgm\\WhatsApp.exe";

// C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2318.2.0_x64__cv1g1gvanyjgm\WhatsApp.exe
// C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2318.2.0_x64__cv1g1gvanyjgm
// C:\Program Files\WindowsApps

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


// Ярлык для метро аппы
// 1. Открыть Explorer.
// 2. В адресной строке написать shell:AppsFolder.
// 3. Найти нужное приложение в списке и правой кнопкой создать ярлык.

// 5319275A.WhatsAppDesktop_cv1g1gvanyjgm!App

// https://www.google.com/search?q=%D0%A0%D1%89%D1%86+%D0%B5%D1%89+%D0%B4%D1%84%D0%B3%D1%82%D1%81%D1%80+%D1%84%D0%B7%D0%B7%D1%8B%D0%B5%D1%89%D0%BA%D1%83+%D1%84%D0%B7%D0%B7%D0%B4%D1%88%D1%81%D1%84%D0%B5%D1%88%D1%89%D1%82%D1%8B+%D1%81%D0%BA%D1%83%D1%84%D0%B5%D1%83%D0%B7%D0%BA%D1%89%D1%81%D1%83%D1%8B%D1%8B&rlz=1C1GCEA_enRU1053RU1053&oq=%D0%A0%D1%89%D1%86+%D0%B5%D1%89+%D0%B4%D1%84%D0%B3%D1%82%D1%81%D1%80+%D1%84%D0%B7%D0%B7%D1%8B%D0%B5%D1%89%D0%BA%D1%83+%D1%84%D0%B7%D0%B7%D0%B4%D1%88%D1%81%D1%84%D0%B5%D1%88%D1%89%D1%82%D1%8B+%D1%81%D0%BA%D1%83%D1%84%D0%B5%D1%83%D0%B7%D0%BA%D1%89%D1%81%D1%83%D1%8B%D1%8B&aqs=chrome..69i57j33i10i160l4.16191j0j7&sourceid=chrome&ie=UTF-8
//  
// https://stackoverflow.com/questions/17944718/how-do-i-launch-a-windows-store-application-programmatically
//  
// https://github.com/forderud/RunInSandbox
// Require .NET 4.8, build tools 143
//  
// https://learn.microsoft.com/en-us/windows/uwp/launch-resume/handle-app-prelaunch


// ---------------------------
// WhatsApp.exe - Системная ошибка
// ---------------------------
// Не удается продолжить выполнение кода, поскольку система не обнаружила mrt100_app.dll. Для устранения этой проблемы попробуйте переустановить программу. 
// ---------------------------
// ОК   
// ---------------------------

// mrt100_app.dll is part of Microsoft® .NET Framework and developed by Microsoft Corporation according to the mrt100_app.dll version information.
// mrt100_app.dll is usually located in the 'c:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.1_1.1.23406.0_x86__8wekyb3d8bbwe\' folder.

// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.4_1.4.24201.0_x64__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.4_1.4.24201.0_x86__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.7_1.7.25531.0_x64__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.7_1.7.27422.0_x64__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.1.7_1.7.27422.0_x86__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.1_2.1.26424.0_x64__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.1_2.1.26424.0_x86__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.2_2.2.27328.0_x64__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.2_2.2.28604.0_x64__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files\WindowsApps\Microsoft.NET.Native.Runtime.2.2_2.2.28604.0_x86__8wekyb3d8bbwe\mrt100_app.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\arm\mrt100_app.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\x64\mrt100_app.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\x86\mrt100_app.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\arm\ilc\lib\Runtime\mrt100_app.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x64\ilc\lib\Runtime\mrt100_app.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x86\ilc\lib\Runtime\mrt100_app.dll
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2728.1.7\amd64_ppi-ppiskype-c-a_31bf3856ad364e35_10.0.19041.662_none_4fe74cf432204574\f\mrt100_app.dll
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2728.1.7\amd64_ppi-ppiskype-c-a_31bf3856ad364e35_10.0.19041.662_none_4fe74cf432204574\r\mrt100_app.dll
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2846.1.6\amd64_ppi-ppiskype-c-a_31bf3856ad364e35_10.0.19041.662_none_4fe74cf432204574\f\mrt100_app.dll
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2846.1.6\amd64_ppi-ppiskype-c-a_31bf3856ad364e35_10.0.19041.662_none_4fe74cf432204574\r\mrt100_app.dll
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2965.1.8\amd64_ppi-ppiskype-c-a_31bf3856ad364e35_10.0.19041.662_none_4fe74cf432204574\f\mrt100_app.dll
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2965.1.8\amd64_ppi-ppiskype-c-a_31bf3856ad364e35_10.0.19041.662_none_4fe74cf432204574\r\mrt100_app.dll

// "C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\x64\" 
// "C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\x86\" 
// "C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.NET.Native.Runtime.1.4\1.4\AppX\arm\"


// ---------------------------
// WhatsApp.exe - Системная ошибка
// ---------------------------
// Не удается продолжить выполнение кода, поскольку система не обнаружила VCRUNTIME140_APP.dll. Для устранения этой проблемы попробуйте переустановить программу. 
// ---------------------------
// ОК   
// ---------------------------

// C:\Program Files\WindowsApps\Microsoft.DesktopAppInstaller_1.19.10173.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
// C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.27810.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
// C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.29231.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
// C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30035.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
// C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
// C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x86__8wekyb3d8bbwe\vcruntime140_app.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\arm\ilc\lib\MSCRT\vcruntime140_app.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x64\ilc\lib\MSCRT\vcruntime140_app.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x86\ilc\lib\MSCRT\vcruntime140_app.dll
// C:\Users\martinov\AppData\Local\Application Data\Microsoft\OneDrive\23.091.0430.0001\vcruntime140_app.dll
// C:\Users\martinov\AppData\Local\Microsoft\OneDrive\23.091.0430.0001\vcruntime140_app.dll
// C:\Users\martinov\Local Settings\Microsoft\OneDrive\23.091.0430.0001\vcruntime140_app.dll
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2728.1.7\amd64_microsoft-windows-holoshell.appxmain_31bf3856ad364e35_10.0.19041.546_none_0193b0cedf0d3cd3\f\vcruntime140_app.dll
// ...
// C:\Windows\servicing\LCU\Package_for_RollupFix~31bf3856ad364e35~amd64~~19041.2965.1.8\amd64_windowsdeviceportal..oolsplugin.appxmain_31bf3856ad364e35_10.0.19041.746_none_2dbc56fc404ea90b\r\vcruntime140_app.dll
// C:\Windows\SystemApps\MicrosoftWindows.Client.CBS_cw5n1h2txyewy\vcruntime140_app.dll
// C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2673_none_fb4cfdd37e97dcd2\vcruntime140_app.dll
// C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2673_none_fb4cfdd37e97dcd2\n\vcruntime140_app.dll
// C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2788_none_fb42bc497e9f923f\vcruntime140_app.dll
// C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2788_none_fb42bc497e9f923f\n\vcruntime140_app.dll
// C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2913_none_fb268c537eb5989b\CBS\vcruntime140_app.dll
// C:\Windows\WinSxS\amd64_microsoft-windows-userexperience-desktop_31bf3856ad364e35_10.0.19041.2913_none_fb268c537eb5989b\n\CBS\vcruntime140_app.dll


// ---------------------------
// WhatsApp.exe - Ошибка приложения
// ---------------------------
// Ошибка при запуске приложения (0xc000007b). Для выхода из приложения нажмите кнопку "ОК". 
// ---------------------------
// ОК   
// ---------------------------

// Debug - ucrtbased.dll?

// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10240.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10240.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10240.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10240.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10586.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10586.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10586.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.10586.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.14393.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.14393.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.14393.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.14393.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.15063.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.15063.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.15063.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.15063.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.16299.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.16299.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.16299.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.16299.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17134.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17134.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17134.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17134.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17763.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17763.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17763.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.17763.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.19041.0\Redist\Debug\arm\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.19041.0\Redist\Debug\arm64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.19041.0\Redist\Debug\x64\ucrtbased.dll
// C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.UniversalCRT.Debug\10.0.19041.0\Redist\Debug\x86\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.15063.0\arm\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.15063.0\arm64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.15063.0\x64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.15063.0\x86\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\arm\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\arm64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\x64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\x86\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17134.0\arm\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17134.0\arm64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17134.0\x64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17134.0\x86\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17763.0\arm\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17763.0\arm64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17763.0\x64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.17763.0\x86\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\arm\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\arm64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x86\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\arm\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\arm64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\x64\ucrt\ucrtbased.dll
// C:\Program Files (x86)\Windows Kits\10\bin\x86\ucrt\ucrtbased.dll
// C:\Windows\System32\ucrtbased.dll
// C:\Windows\SysWOW64\ucrtbased.dll


// Release - api-ms-win-crt-runtime-l1-1-0.dll


// C:\Idea\jbr\bin\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files\dotnet\shared\Microsoft.NETCore.App\2.0.0\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files\dotnet\shared\Microsoft.NETCore.App\2.0.9\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files\dotnet\shared\Microsoft.NETCore.App\2.1.30\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\Remote Debugger\x64\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\Remote Debugger\x86\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\Extensions\Microsoft\LiveShare\Agent\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\Remote Debugger\x64\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\Remote Debugger\x86\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\bin\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\x64\bin\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\Installer\resources\app\ServiceHub\Services\Microsoft.VisualStudio.Setup.Service\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Microsoft Visual Studio\Installer.8c30fb2a3c1443aa97b0d18311a56152\resources\app\ServiceHub\Services\Microsoft.VisualStudio.Setup.Service\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\arm\ilc\lib\MSCRT\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x64\ilc\lib\MSCRT\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x86\ilc\lib\MSCRT\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\10.0.17763.0\ucrt\DLLs\arm\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\10.0.17763.0\ucrt\DLLs\x64\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\10.0.17763.0\ucrt\DLLs\x86\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\10.0.19041.0\ucrt\DLLs\arm\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\10.0.19041.0\ucrt\DLLs\x64\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\10.0.19041.0\ucrt\DLLs\x86\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\ucrt\DLLs\arm\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\ucrt\DLLs\x64\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Program Files (x86)\Windows Kits\10\Redist\ucrt\DLLs\x86\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Windows\System32\downlevel\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Windows\SysWOW64\downlevel\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Windows\WinSxS\amd64_microsoft-windows-m..namespace-downlevel_31bf3856ad364e35_10.0.19041.1_none_7d55e8342077d456\api-ms-win-crt-runtime-l1-1-0.dll
// C:\Windows\WinSxS\x86_microsoft-windows-m..namespace-downlevel_31bf3856ad364e35_10.0.19041.1_none_21374cb0681a6320\api-ms-win-crt-runtime-l1-1-0.dll



//NOTE: !!! x64
static std::wstring path_mrt100_app_dll       = L"C:\\Program Files\\WindowsApps\\Microsoft.NET.Native.Runtime.2.2_2.2.28604.0_x64__8wekyb3d8bbwe";
static std::wstring path_vcruntime140_app_dll = L"C:\\Program Files\\WindowsApps\\Microsoft.VCLibs.140.00_14.0.30704.0_x86__8wekyb3d8bbwe";
// static std::wstring path_ucrtbased_dll        = L"C:\\Program Files (x86)\\Microsoft SDKs\\Windows Kits\\10\\ExtensionSDKs\\Microsoft.UniversalCRT.Debug\\10.0.19041.0\\Redist\\Debug\\x64";
static std::wstring path_ucrtbased_dll        = L"C:\\Program Files (x86)\\Windows Kits\\10\\bin\\x64\\ucrt";
static std::wstring path_api_ms_win_crt_runtime_l1_1_0_dll = L"C:\\Program Files (x86)\\Windows Kits\\10\\Redist\\10.0.19041.0\\ucrt\\DLLs\\x64";




int main(int argc, char* argv[])
{
    
    wchar_t miscBuf[32767]; // GetEnvironmentVariable limit
    std::size_t miscBufSizeBytes  = sizeof(miscBuf);
    std::size_t miscBufSizeWchars = sizeof(miscBuf)/sizeof(miscBuf[0]);


    DWORD len = GetModuleFileNameW(0, miscBuf, miscBufSizeWchars);
    if (!len || len>=miscBufSizeWchars)
    {
        std::cout << "Failed to get exe name\n";
        return 1;
    }

    // miscBuf[len] = 0;
    // std::wstring exeName = exeNameBuf;

    std::wstring exeName = std::wstring(miscBuf, len);

    std::cout << "Exe name: " << to_ascii(exeName) << "\n";

    std::wstring dllName = exeName;
    std::wstring::size_type slashPos = dllName.rfind(L'\\');
    std::wstring::size_type dotPos   = dllName.rfind(L'.');
    if (dotPos>slashPos)
    {
        dllName.erase(dotPos,std::wstring::npos);
    }
    std::cout << "Dll name (1): " << to_ascii(dllName) << "\n";
    dllName.append(L"_dll.dll");
    std::cout << "Dll name (2): " << to_ascii(dllName) << "\n";


    len = GetEnvironmentVariableW( L"PATH", miscBuf, miscBufSizeWchars);
    if (!len)
    {
        std::cout << "Failed to get PATH env var\n";
        return 1;
    }

    std::wstring pathEnvVar = std::wstring(miscBuf, len);
    // std::cout << "PATH: " << to_ascii(pathEnvVar) << "\n";

    // check 32,767 limit
    std::wstring newPathEnvVar = path_ucrtbased_dll + L";"
                               + path_api_ms_win_crt_runtime_l1_1_0_dll + L";"
                               + path_mrt100_app_dll + L";"
                               + path_vcruntime140_app_dll + L";"
                               + pathEnvVar;


    if (!SetEnvironmentVariable(L"PATH", newPathEnvVar.c_str()))
    {
        std::cout << "Failed to set PATH env var\n";
        return 1;
    }


    wchar_t cmdLine[16384];
    std::wstring strWhatsAppExe = pStrWhatsAppExe;
    std::wstring strWhatsAppExeQuoted = L"\"" + strWhatsAppExe + L"\"";

    // Размер буфера лень проверять - его хватает
    //strWhatsAppExe.copy(cmdLine, strWhatsAppExe.size(), 0);
    strWhatsAppExeQuoted.copy(cmdLine, strWhatsAppExeQuoted.size(), 0);


    PROCESS_INFORMATION pi = { 0 };

    STARTUPINFO si = { 0 };
    si.cb          = sizeof(STARTUPINFO);
    /*
    si.lpReserved  = 0;
    si.lpDesktop   = 0;
    si.lpTitle     = 0;
    si.dwX         = 0;
    si.dwY         = 0;
    si.dwXSize     = 0;
    si.dwYSize     = 0;
    si.dwXCountChars = 0;
    si.dwYCountChars = 0;
    si.dwFillAttribute  = 0;
    */
    si.dwFlags = 0;
    si.lpReserved  = 0;
    si.cbReserved2 = 0;
    si.lpReserved2 = 0;

    BOOL cpRes = CreateProcessW ( 0 // appName     // lpApplicationName
                               , cmdLine     // lpCommandLine
                               , 0           // lpProcessAttributes
                               , 0           // lpThreadAttributes
                               , FALSE       // bInheritHandles
                               , CREATE_SUSPENDED // dwCreationFlags
                               , 0           // lpEnvironment
                               , 0           // lpCurrentDirectory
                               , &si
                               , &pi
                               );

    if (!cpRes)
    {
        ::std::cout<<"CreateProcess failed, error: "<<GetLastError()<<"\n";
        return 1;
    }


    if (!injectDll( dllName.c_str(), pi.hProcess /* , pi.dwProcessId */ ))
    {
        // ---------------------------
        // WhatsApp.exe - Ошибка приложения
        // ---------------------------
        // Ошибка при запуске приложения (0xc0000022). Для выхода из приложения нажмите кнопку "ОК". 
        // ---------------------------
        // ОК   
        // ---------------------------
        std::cout<<"Failed to inject hook dll\n";
        return 1;
    }

    std::cout<<"Hook Dll injected Ok\n";

    //bool injectDll( const wchar_t *dllName, HANDLE hProcess /* , DWORD pid */ )

    ResumeThread( pi.hThread );

    std::cout<<"Resume remote process\n";


    return 0;
}

