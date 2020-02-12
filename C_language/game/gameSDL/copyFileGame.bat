@echo off
color 0a

echo Nhan phim bat ki de copy
:copyFile
pause > nul

echo.
echo file cpp
copy D:\github\Programming_language\C_language\game\gameSDL\*.cpp D:\visual\SDLGame\SDLGame /y
echo file header
copy D:\github\Programming_language\C_language\game\gameSDL\*.h D:\visual\SDLGame\SDLGame /y
echo ===================================================

goto copyFile
