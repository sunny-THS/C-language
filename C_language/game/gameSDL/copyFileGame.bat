@echo off
color 0a

echo Nhan phim bat ki de copy
:copyFile
pause > nul

copy D:\github\Programming_language\C_language\game\gameSDL\GAME.cpp D:\visual\SDLGame\SDLGame /y

goto copyFile
