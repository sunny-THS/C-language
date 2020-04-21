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
    DrawOneFood(i);
  }
}
void Food::DrawOneFood(int index) {
  CommonFunction::SetColor(Red);
  CommonFunction::GotoXY(fruit_[index].x, fruit_[index].y);
  putchar(167);
}
void Food::UpdateFruit (int x, int y, int i) {
  fruit_[i].x = x;
  fruit_[i].y = y;
}
