@call "%VS110COMNTOOLS%..\..\VC\vcvarsall.bat" amd64
@call msbuild /p:Configuration=Release /p:Platform=Win32 /m
