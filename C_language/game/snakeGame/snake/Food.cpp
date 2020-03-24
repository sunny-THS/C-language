#include "Food.h"

Food::Food() {
  for (int i = 0; i < AMOUNT_FOOD; i++) {
    fruit_[i].x = CommonFunction::random(LIMIT_BOARD_GAME-1);
    fruit_[i].y = CommonFunction::random(CONSOLE_HEIGHT-1);
  }
}
Food::~Food() {}
void Food::drawFood() {
  for (int i = 0; i < AMOUNT_FOOD; i++) {
    CommonFunction::gotoxy(fruit_[i].x, fruit_[i].y);
    putchar(42);
  }
}
void Food::updateFruit() {}

void Food::SetRectFruit (int x, int y, int i) {
  fruit_[i].x = x;
  fruit_[i].y = y;
}
