@echo off
color 0a

echo Nhan phim bat ki de copy
:copyFile
pause > nul

echo.
echo file cpp
copy D:\github\Programming_language\C_language\game\pongGame\*.cpp D:\visual\pongGame\pongGame /y
echo file header
copy D:\github\Programming_language\C_language\game\pongGame\*.h D:\visual\pongGame\pongGame /y
echo ===================================================

goto copyFile
