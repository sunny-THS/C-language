#ifndef Common_Function_H_
  #define Common_Function_H_
  #include<iostream> // cout
  #include<Windows.h> // GetStdHandle(), SetConsoleCursorPosition(), SetConsoleTextAttribute(), STD_OUTPUT_HANDLE,
  #include<conio.h> // _getch(), kbhit()
  #include<cstdlib> // rand(), srand()
  #include<vector>
  #include<ctime> // time(), time_t and struct tm, localtime()
  #define CONSOLE_HEIGHT 30 // the height of console
  #define CONSOLE_WIDTH 120 // the width of console
  #define CENTER_CONSOLE_HEIGHT CONSOLE_HEIGHT/2
  #define AMOUNT_FOOD 3 // the amount food in game
  #define SCROLL_WIDTH 2
  #define LIMIT_BOARD_GAME CONSOLE_WIDTH-CONSOLE_WIDTH/3
  #define LIMIT_BOARD_INFO CONSOLE_WIDTH/3-1
  #define HEIGHT_BOARD_INFO CONSOLE_HEIGHT/3
  #define WIDTH_BOARD_INFO LIMIT_BOARD_GAME+1
  #define LIMIT_SPEED 1
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
