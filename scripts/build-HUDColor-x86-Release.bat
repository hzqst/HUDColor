@echo off
setlocal
set "Configuration=Release"
call "%~dp0build-HUDColor-x86.bat" %*
exit /b %errorlevel%
