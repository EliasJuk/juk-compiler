@echo off

call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x64

cd /d "%~dp0"

if not exist "..\build" mkdir "..\build"

cl "..\src\main.c" "..\src\lexer.c" /Fe:"..\build\jukc.exe" /Fo:"..\build\\"

if errorlevel 1 exit /b 1

"..\build\jukc.exe" "..\example\hello.juk"