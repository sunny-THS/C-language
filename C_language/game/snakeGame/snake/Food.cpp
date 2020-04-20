#include "Food.h"

Food::Food() {}
Food::~Food() {}
void Food::setup() {
  for (int i = 0; i < AMOUNT_FOOD; i++) {
    fruit_[i].x = CommonFunction::random(LIMIT_BOARD_GAME-1);
    fruit_[i].y = CommonFunction::random(CONSOLE_HEIGHT-1);
  }
}
void Food::drawFood() {
  for (int i = 0; i < AMOUNT_FOOD; i++) {
    CommonFunction::textColor(Red);
    CommonFunction::gotoxy(fruit_[i].x, fruit_[i].y);
    putchar(167);
  }
}
void Food::updateFruit (int x, int y, int i) {
  fruit_[i].x = x;
  fruit_[i].y = y;
}
