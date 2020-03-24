#include "InfoUser.h"

InfoUser::InfoUser() {
  score_ = 0;
  strcat(user_name_, " ");
}
void InfoUser::SetTime() {
  time(&rawTime);
  localTime = localtime(&rawTime);
}
int InfoUser::titleGame() {
  int y = 4, n = 15;//y is select, n is no select
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
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1-strlen(TITLE))/2, HEIGHT_BOARD_INFO/3);
  puts(TITLE);
  // CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO-strlen(user_name_))/2, HEIGHT_BOARD_INFO/2);
  // std::cout << GetName();
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO-8)/2, HEIGHT_BOARD_INFO-HEIGHT_BOARD_INFO/4);
  std::cout << "Score: " << score_;
}
