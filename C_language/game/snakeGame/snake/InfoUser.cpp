#include "InfoUser.h"

InfoUser::InfoUser() {
  score_ = 0;
  strcpy(user_name_, "");
}
void InfoUser::SetTime() {
  time(&rawTime);
  localTime = localtime(&rawTime);
}
int InfoUser::titleGame() {
  int y = Red, n = White;//y is select, n is no select
  int select = 1;//1 is start game, 2 is howToPlay, 3 is exit

  CommonFunction::textColor(Green);
  puts(TEXT_TITLE);
  while (1) {
    switch (select) {
      case 1: menu(TEXT_START, TEXT_HOWTOGAME, TEXT_EXIT, y, n, n); break;
      case 2: menu(TEXT_START, TEXT_HOWTOGAME, TEXT_EXIT, n, y, n); break;
      case 3: menu(TEXT_START, TEXT_HOWTOGAME, TEXT_EXIT, n, n, y); break;
    }

    if (kbhit()) { // press keysboard
      char key = _getch();
      if (key == 'w' || key == 'W' || key == 56 || key == 72) {
        select--;
        if (select<1) {
          select = 3;
        }
      }else if (key == 's' || key == 'S' || key == 50 || key == 80) {
        select++;
        if (select>3) {
          select = 1;
        }
      }else if (key == 13) {
        return select;
      }
    }
  }
}
void InfoUser::menu(char *start, char *help, char *e, int a, int b, int c){
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(start))/2, CONSOLE_HEIGHT/2-3);
  CommonFunction::textColor(a);
  puts(start);
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(help))/2, CONSOLE_HEIGHT/2+2-3);
  CommonFunction::textColor(b);
  puts(help);
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(e))/2, CONSOLE_HEIGHT/2+4-3);
  CommonFunction::textColor(c);
  puts(e);
}
void InfoUser::boardInfoUser() {
  CommonFunction::textColor(Green);
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(TITLE))/2, HEIGHT_BOARD_INFO/3);
  puts(TITLE);
  CommonFunction::textColor(White);
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(user_name_)-4)/2, HEIGHT_BOARD_INFO/2);
  std::cout << "Hi, " << GetName();
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-8)/2, HEIGHT_BOARD_INFO-HEIGHT_BOARD_INFO/4);
  std::cout << "Score: " << score_;
}
void InfoUser::inputUserName() {
  CommonFunction::cls();
  char name[50];
  char label[] = "User name: ";
  CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(label))/2, CONSOLE_HEIGHT/2);
  std::cout << label;
  SetName(gets(name));
}
