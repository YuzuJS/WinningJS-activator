@call "%VS110COMNTOOLS%..\..\VC\vcvarsall.bat" amd64
cd %~dp0\src
@call msbuild /p:Configuration=Release /p:Platform=Win32 /m
