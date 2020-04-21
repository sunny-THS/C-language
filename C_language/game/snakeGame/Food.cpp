#include "Food.h"

Food::Food() {}
Food::~Food() {}
void Food::Setup() {
  for (int i = 0; i < AMOUNT_FOOD; i++) {
    fruit_[i].x = GetIX();
    fruit_[i].y = GetIY();
  }
}
void Food::DrawFood() {
  for (int i = 0; i < AMOUNT_FOOD; i++) {
    CommonFunction::SetColor(Red);
    CommonFunction::GotoXY(fruit_[i].x, fruit_[i].y);
    putchar(167);
  }
}
void Food::UpdateFruit (int x, int y, int i) {
  fruit_[i].x = x;
  fruit_[i].y = y;
}
