#include "Paddle.h"
Paddle::Paddle(bool left) {
  w_ = 2;
  h_ = 3;
  rect_.y = CONSOLE_HEIGHT/2;
  if (left) {
    rect_.x = CONSOLE_WIDTH/5+w_;
    shape_ = 221;
  }else {
    rect_.x = CONSOLE_WIDTH/5+GAME_WIDTH-w_;
    shape_ = 222;
  }
}
void Paddle::Draw() {
  for (size_t i = 0; i < h_; i++) {
    CommonFunction::gotoXY(Get_X(), Get_Y()+i);
    putchar(shape_);
  }
}
void Paddle::move(float step) {
  rect_.y += step;
  if (rect_.y<CONSOLE_HEIGHT/5-1) {
    rect_.y = CONSOLE_HEIGHT/5-1;
  }
}
