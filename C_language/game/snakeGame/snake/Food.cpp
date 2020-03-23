#include "Food.h"

Food::Food() {
  for (int i = 0; i < AMOUNT_FOOD; i++) {
    fruit_[i].x = CommonFunction::random(CONSOLE_WIDTH-SCROLL_WIDTH);
    fruit_[i].y = CommonFunction::random(CONSOLE_HEIGHT);
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
