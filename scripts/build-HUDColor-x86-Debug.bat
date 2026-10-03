@echo off
setlocal
set "Configuration=Debug"
call "%~dp0build-HUDColor-x86.bat" %*
exit /b %errorlevel%
