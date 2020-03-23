#ifndef Common_Function_H_
#define Common_Function_H_

  #include<iostream>
  #include<Windows.h>
  #include<conio.h>
  #include<cstdlib>
  #include<vector>
  #include<ctime>

  #define CONSOLE_HEIGHT 30 // the height of console
  #define CONSOLE_WIDTH 120 // the width of console
  #define AMOUNT_FOOD 3 // the amount food in game
  #define SCROLL_WIDTH 2
  // #define WIDTH_GAME 110
  // #define HEIGHT_GAME 20

  enum COLOR {
    Blue = 1,
    Green = 10,
    Purple = 13,
    Orange = 12,
    Yellow = 14,
    White = 15,
    Gray = 8,
    Red = 4,
    CadetBlue = 11  // xanh lam
  };

  enum TrangThai {UP, DOWN, LEFT, RIGHT};

  typedef struct toaDo {
    int x, y;
  }TD;


  namespace CommonFunction {
    void gotoxy(int x, int y);
    void cls();
    void textColor(int x);
    int random(int max, int min=0);
    void pause();
  }

#endif
