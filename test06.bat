@rem e_sqlite3.dll
@rem set PATH=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2320.2.0_x64__cv1g1gvanyjgm;%PATH%
@set PATH=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm;%PATH%
@rem VCRUNTIME140_APP.dll
@rem C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.27810.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
@rem C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.29231.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
@rem C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30035.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
@rem C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe\vcruntime140_app.dll
@rem C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x86__8wekyb3d8bbwe\vcruntime140_app.dll
@rem C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\arm\ilc\lib\MSCRT\vcruntime140_app.dll
@rem C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x64\ilc\lib\MSCRT\vcruntime140_app.dll
@rem C:\Program Files (x86)\MSBuild\15.0\.Net\.NetNative\15.0.24211\x86\ilc\lib\MSCRT\vcruntime140_app.dll
@set PATH=C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe;%PATH%

@rem set BIN_ROOT=.out\msvc2019\x64\Release
@set BIN_ROOT=.out\msvc2019\x64\Debug
@set TEST06=%BIN_ROOT%\test06.exe

@if exist %BIN_ROOT%\..\Debug\injected_test03_dll.dll    del %BIN_ROOT%\..\Debug\injected_test03_dll.dll
@if exist %BIN_ROOT%\..\Release\injected_test03_dll.dll  del %BIN_ROOT%\..\Release\injected_test03_dll.dll

@rem %TEST06%

F:\_github\detourse_tests\_3dp\uwp-injector\build\injector.exe WhatsApp.exe F:\_github\detourse_tests\.out\msvc2019\x64\Debug\test06_dll.dll