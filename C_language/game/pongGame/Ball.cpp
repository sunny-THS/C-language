#include "Ball.h"
Ball::Ball() {
  rect_.x = CONSOLE_WIDTH/2;
  rect_.y = CONSOLE_HEIGHT/2;
  speed_x_ = CommonFunction::random(3, 1);
  speed_y_ = 1;
}
Ball::Ball(float x, float y) {
  rect_.x = CONSOLE_WIDTH/5+x;
  rect_.y = CONSOLE_HEIGHT/5+y;
  speed_x_ = CommonFunction::random(3, 1);
  speed_y_ = 1;
}
void Ball::Draw() {
  CommonFunction::gotoXY(Get_X(), Get_Y());
  putchar(111); // o key
}
void Ball::Update() {
  rect_.x += speed_x_;
  rect_.y += speed_y_;
}
void Ball::edgesCollision() {
  if (Get_Y()<CONSOLE_HEIGHT/5+1||Get_Y()>GAME_HEIGHT+CONSOLE_HEIGHT/5-1) {
    speed_y_*=-1;
    Set_speedX(CommonFunction::random(3, 1));
  }
  if (Get_X()<CONSOLE_WIDTH/5+1||Get_X()>GAME_WIDTH+CONSOLE_WIDTH/5-1) {
    reset();
  }
}
void Ball::reset() {
  rect_.x = CONSOLE_WIDTH/2;
  rect_.y = CONSOLE_HEIGHT/2;
}
