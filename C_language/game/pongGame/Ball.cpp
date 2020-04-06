#include "Ball.h"
Ball::Ball() {
  x_ = CONSOLE_WIDTH/2;
  y_ = CONSOLE_HEIGHT/2;
  speed_x_ = 2;
  speed_y_ = 1;
}
Ball::Ball(float x, float y) {
  x_ = CONSOLE_WIDTH/3+x;
  y_ = CONSOLE_HEIGHT/3+y;
  speed_x_ = 1;
  speed_y_ = 3;
}
void Ball::Draw() {
  CommonFunction::gotoXY(x_, y_);
  putchar(111); // o key
}
void Ball::Update() {
  x_ += speed_x_;
  y_ += speed_y_;
}
void Ball::edgesCollision() {
  if (y_<CONSOLE_HEIGHT/5+1||y_>GAME_HEIGHT+CONSOLE_HEIGHT/5-1) {
    speed_y_*=-1;
  }
  if (x_<CONSOLE_WIDTH/5+1||x_>GAME_WIDTH+CONSOLE_WIDTH/5-1) {
    reset();
  }
}
void Ball::reset() {
  x_ = CONSOLE_WIDTH/2;
  y_ = CONSOLE_HEIGHT/2;
}
