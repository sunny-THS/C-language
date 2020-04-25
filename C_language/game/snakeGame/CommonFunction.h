#ifndef Common_Function_H_
  #define Common_Function_H_
  #include <iostream>
  #include <Windows.h>
  #include <string>
  #include <cstring>
  #include <cstdlib>
  #include <ctime>
  #include <vector>
  #include <conio.h>
  // define
  #define HEIGHT 30
  #define WIDTH 120
  #define AMOUNT_FOOD 3 // the amount food in game
  //enum
  enum COLOR {
    Blue = 1,
    Green = 10,
    Purple = 13,
    Orange = 12,
    Yellow = 14,
    White = 15,
    Gray = 8,
    Red = 4,
    CadetBlue = 11
  };
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
  enum TrangThai {UP, DOWN, LEFT, RIGHT};
  //struct
  struct Rect {
    int x, y;
  };
  // prototype
  namespace CommonFunction {
    int random(int max, int min = 0);
    void cls();
    void SetColor(int);
    void GotoXY(int, int);
    void SetConsole(int w, int h, char *text, bool, bool);
    int whereX();
    int whereY();
    void ShowCur(bool CursorVisibility);
  }
#endif
