@echo off
color 0a

echo Nhan phim bat ki de copy
:copyFile
pause > nul

echo.
echo file cpp
copy D:\github\Programming_language\C_language\game\gameSDL\GAME.cpp D:\visual\SDLGame\SDLGame /y
copy D:\github\Programming_language\C_language\game\gameSDL\CommonFunction.cpp D:\visual\SDLGame\SDLGame /y
echo file header
copy D:\github\Programming_language\C_language\game\gameSDL\CommonFunction.h D:\visual\SDLGame\SDLGame /y
echo ===================================================

goto copyFile
