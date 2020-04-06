#ifndef CommonFunction_H_
  #define CommonFunction_H_
  #include <iostream>
  #include <cstdlib>
  #include <Windows.h>
  #define CONSOLE_HEIGHT 30
  #define CONSOLE_WIDTH 120
  #define GAME_HEIGHT 3*CONSOLE_HEIGHT/5
  #define GAME_WIDTH 3*CONSOLE_WIDTH/5
  namespace CommonFunction {
    void gotoXY(short int, short int);
    int random(int max, int min = 0);
    void textColor(int);
    void cls();
    void pause();
    void delay(int);
  }
#endif
