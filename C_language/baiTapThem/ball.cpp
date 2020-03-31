#include <iostream>
#include <Windows.h>

void textColor(int x) {
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, x);
}
void gotoxy(int x, int y) {
  static HANDLE h = NULL;
  if (!h) {
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  }
  COORD c = { x, y };
  SetConsoleCursorPosition(h, c);
}
