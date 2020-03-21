#include<iostream>
#include<windows.h>
#include<cstdio>
#include<conio.h>
using namespace std;

#define SCREEN_HEIGHT 30
#define SCREEN_WIDTH 120
#define BLUE 11
#define GREEN 10

void textColor(int x) {
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, x);
}
void gotoxy(short int x, short int y) {
  static HANDLE h = NULL;
  if (!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h, c);
}
void inChongChong(int s, int color1, int color2) {
  for (int i = 0; i < s; i++) {
    for (int j = 1; j <= s; j++) {
      // tam giac 1 - top left
      textColor(color2);
      gotoxy(j+(SCREEN_WIDTH/2-s-s),i+(SCREEN_HEIGHT/2-s));
      if (j>i) {
        cout << "*";
      }
      // tam giac 2 - top right
      textColor(color1);
      gotoxy(j+s-1+(SCREEN_WIDTH/2-s-s), i+(SCREEN_HEIGHT/2-s));
      if (s-j-1<i) {
        cout << "*";
      }
      // tam giac 3 - bottom left
      textColor(color1);
      gotoxy(j-1+(SCREEN_WIDTH/2-s-s), i+s-1+(SCREEN_HEIGHT/2-s));
      if (s-j+1>i) {
        cout << "*";
      }
      // tam giac 4 - bottom right
      textColor(color2);
      gotoxy(j+s-1+(SCREEN_WIDTH/2-s-s), i+s-1+(SCREEN_HEIGHT/2-s));
      if (j<=i+1) {
        cout << "*";
      }

    }
  }
}
int main() {
  int a=10, color1=BLUE, color2=GREEN, tmp;
  bool repeat = true;
  while (repeat) {
    if (kbhit()) {
      repeat=false;
    }
    tmp = color1;
    color1 = color2;
    color2 = tmp;
    inChongChong(a, color1, color2);
    Sleep(200);
  }
  system("pause>nul");
  return 0;
}
