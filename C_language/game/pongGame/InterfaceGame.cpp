#include "InterfaceGame.h"
void InterfaceGame::DrawFrameGame() {
  for (size_t y = 0; y <= GAME_HEIGHT; y++) {
    for (size_t x = 0; x <= GAME_WIDTH; x++) {
      CommonFunction::gotoXY(CONSOLE_WIDTH/5+x, CONSOLE_HEIGHT/5+y);
      if ((y>0&&y<GAME_HEIGHT)&&(x>0&&x<GAME_WIDTH)) {
        putchar(32); // space key
      }else {
        if (y==0||y==GAME_HEIGHT) {
          putchar(205); // equal
        }
        if ((x==0||x==GAME_WIDTH)&&(y!=0&&y!=GAME_HEIGHT)) {
          putchar(186); // double bar
        }
      }
    }
  }
}
