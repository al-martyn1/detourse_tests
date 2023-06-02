@set BIN_ROOT=.out\msvc2019\x64\Debug
@set TEST03=%BIN_ROOT%\test03.exe

@if exist F:\_github\detourse_tests\.out\msvc2019\x64\Debug\injected_test03_dll.dll    del F:\_github\detourse_tests\.out\msvc2019\x64\Debug\injected_test03_dll.dll
@if exist F:\_github\detourse_tests\.out\msvc2019\x64\Release\injected_test03_dll.dll  del F:\_github\detourse_tests\.out\msvc2019\x64\Release\injected_test03_dll.dll

%TEST03%