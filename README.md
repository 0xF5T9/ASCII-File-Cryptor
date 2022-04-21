# ASCII File Cryptor
Crypt file using ASCII
 
Compiler: Visual Studio 2022

Build Mode: Release x64

Architecture: x64

## Set-up compile environment:
Needs:
- Visual Studio 2022 with C++ Compiler

VS Project Configurations:
1. C/C++ → Command Line → Additional Options → Add "/utf-8".
2. Linker → Input → Additional Dependencies → Add "winmm.lib".

Executables:
- The target file must be located in the same directory as the executable file to be found.

Notes:
- The file could be recognized as malware by Anti Virus because it perform sensitive tasks.
- Either excluded the file from Anti Virus or compile the code yourself.
