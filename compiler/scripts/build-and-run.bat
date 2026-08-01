@echo off

call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x64

cd /d "%~dp0"

if not exist "..\build" mkdir "..\build"

cl "..\src\main.c" /Fe:"..\build\main.exe" /Fo:"..\build\main.obj"

if errorlevel 1 exit /b 1

"..\build\main.exe" "..\example\hello.juk"