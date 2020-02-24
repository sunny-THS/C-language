@echo off
color 0a

echo Nhan phim bat ki de copy
:copyFile
pause > nul

echo.
echo file cpp
copy D:\github\Programming_language\C_language\baiTapThem\SortingAlgorithm\*.cpp D:\visual\ths\ths /y
echo file header
copy D:\github\Programming_language\C_language\baiTapThem\SortingAlgorithm\*.h D:\visual\ths\ths /y
echo ===================================================

goto copyFile
