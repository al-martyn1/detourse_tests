@rem e_sqlite3.dll
@REM set PATH=C:\Program Files\WindowsApps\5319275A.WhatsAppDesktop_2.2320.2.0_x64__cv1g1gvanyjgm;%PATH%
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

@set BIN_ROOT=.out\msvc2019\x64\Debug
@set TEST03=%BIN_ROOT%\test05.exe

%TEST03% prngot    > prngot.txt
%TEST03% prnsorted > prnsorted.txt
%TEST03% prnboth   > prnboth.txt

start tgdiff prngot.txt prnsorted.txt