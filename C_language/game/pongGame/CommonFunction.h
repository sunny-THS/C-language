#ifndef CommonFunction_H_
  #define CommonFunction_H_
  #include <iostream>
  #include <cstdlib>
  #include <Windows.h>
  #include <conio.h>
  #include <ctime>
  #define CONSOLE_HEIGHT 30
  #define CONSOLE_WIDTH 120
  #define GAME_HEIGHT 3*CONSOLE_HEIGHT/5
  #define GAME_WIDTH 3*CONSOLE_WIDTH/5
  enum KeyPress {
    Numpad_2 = 50,
    Numpad_4 = 52,
    Numpad_6 = 54,
    Numpad_8 = 56,
    Up_Arrow = 72,
    Down_Arrow = 80,
    Left_Arrow = 75,
    Right_Arrow = 77,
    Esc_Key = 27,
    Space_Key = 32,
    Enter_Key = 13
  };
  namespace CommonFunction {
    void gotoXY(short int, short int);
    float random(int max, int min = 0);
    void textColor(int);
    void cls();
    void pause();
    void delay(int);
  }
#endif
