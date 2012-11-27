@call "%VS110COMNTOOLS%..\..\VC\vcvarsall.bat" x86
cd %~dp0\src
@call msbuild /p:Configuration=Release /p:Platform=Win32 /m
