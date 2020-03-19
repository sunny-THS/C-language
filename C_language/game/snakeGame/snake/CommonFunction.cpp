#include "CommonFunction.h"

void CommonFunction::gotoxy(int x, int y){
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h, c);
}
void CommonFunction::cls(){
  system("cls");
}
//tao mau chu
void CommonFunction::textColor(int x){
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, x);
}
// ham random
int CommonFunction::random(int min, int max){
  return min + rand()%(max-min+1);
}
// pause
void CommonFunction::pause() {
  system("pause>nul");
}
