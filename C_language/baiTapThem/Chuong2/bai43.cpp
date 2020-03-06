#include<iostream>
#include<windows.h>
#include<cstdio>
using namespace std;

#define SCREEN_HEIGHT 30
#define SCREEN_WIDTH 120

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
void inChongChong(int s) {
  for (int i = 0; i < s; i++) {
    for (int j = 1; j <= s; j++) {
      // tam giac 1
      gotoxy(j-1+(SCREEN_WIDTH/2-s-s),i+(SCREEN_HEIGHT/2-s));
      if (j>i) {
        cout << "*";
      }else {
        cout << ' ';
      }
      // tam giac 2
      gotoxy(j+s-1+(SCREEN_WIDTH/2-s-s), i+(SCREEN_HEIGHT/2-s));
      if (s-j-1<i) {
        cout << "*";
      }else {
        cout << ' ';
      }
      // tam giac 3
      gotoxy(j+s-2+(SCREEN_WIDTH/2-s-s), i+s-1+(SCREEN_HEIGHT/2-s));
      if (j>i+1) {
        cout << ' ';
      }else {
        cout << "*";
      }
      // tam giac 4
      gotoxy(j-1+(SCREEN_WIDTH/2-s-s), i+s-1+(SCREEN_HEIGHT/2-s));
      if (s-j+1>i) {
        cout << "*";
      }else {
        cout << ' ';
      }

    }
  }
}
int main() {
  int a=6;
  inChongChong(a);
  system("pause>nul");
  return 0;
}
