#include "CommonFunction.h"
void CommonFunction::cls() {
  system("cls");
}
void CommonFunction::pause() {
  system("pause>nul");
}
void textColor(int index) {
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, index);
}
void CommonFunction::gotoXY(short int x, short int y) {
  static HANDLE h = NULL;
  if (!h) {
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  }
  COORD c = { x, y };
  SetConsoleCursorPosition(h, c);
}
float CommonFunction::random(int max, int min) {
  static float max_=0, min_=0, val_rand=0; // static variable
  float scale;
  if (max_!=max || min_!=min) {
    max_ = max;
    min_ = min;
    scale = rand()/(RAND_MAX*1.0);
    val_rand = min_ + scale*(max_-min_);
  }
  return val_rand;
}
void CommonFunction::delay(int a) {
  CommonFunction::gotoXY(0, 0);
  Sleep(a);
}
