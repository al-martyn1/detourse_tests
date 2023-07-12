@call before_test.bat

@rem set PATH=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2321.4.0_x64__cv1g1gvanyjgm;%PATH%
@rem set PATH=C:\Program Files\WindowsApps\Microsoft.VCLibs.140.00_14.0.30704.0_x64__8wekyb3d8bbwe;%PATH%

@rem set BIN_ROOT=.out\msvc2019\x64\Release
@set BIN_ROOT=.out\msvc2019\x64\Debug
@set TEST08=%BIN_ROOT%\test08.exe

@if exist %BIN_ROOT%\..\Debug\injected_test08_dll.dll    del %BIN_ROOT%\..\Debug\injected_test08_dll.dll
@if exist %BIN_ROOT%\..\Release\injected_test08_dll.dll  del %BIN_ROOT%\..\Release\injected_test08_dll.dll

@%TEST08%

@rem F:\_github\detourse_tests\_3dp\uwp-injector\build\injector.exe WhatsApp.exe F:\_github\detourse_tests\.out\msvc2019\x64\Debug\test08_dll.dll