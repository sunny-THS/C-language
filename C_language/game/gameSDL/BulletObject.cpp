#include "BulletObject.h"

//contructor
BulletObject::BulletObject() {
  rect_.x = 0;
  rect_.y = 0;
  x_val_ = 0;
  y_val_ = 0;
  is_move_ = false;
  bullet_type_ = NONE;
}

//destructor
BulletObject::~BulletObject() {}

void BulletObject::HandleMove(const int& x_border, const int& y_border) {
  rect_.x += 10;// speed of bullet
  if (rect_.x > x_border) {
    is_move_ = false;
  }
}

void BulletObject::HandleMoveRightToLeft() {
  // speed of bullet
  rect_.x -= 10;
  // khi cham bien phai
  if (rect_.x < 0) {
    set_is_move(false);
  }
}

void BulletObject::HandleInputAction(SDL_Event events) {}
