@echo off
color 0a

echo Nhan phim bat ki de copy
:copyFile
pause > nul

echo.
echo file cpp
copy D:\github\Programming_language\C_language\game\snakeGame\*.cpp D:\visual\SnakeGame\SnakeGame /y
echo file header
copy D:\github\Programming_language\C_language\game\snakeGame\*.h D:\visual\SnakeGame\SnakeGame /y
echo ===================================================

goto copyFile
