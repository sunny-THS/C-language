#include "Snake.h"

// initialization snake
Snake::Snake() {
  is_move_ = true;
  speed_ = 100;
  snakeLen_ = 3;
  oxy_.x = 0;
  oxy_.y = 0;
  for (int i = 0; i < snakeLen_; i++) {
    dot_.push_back(oxy_);
  }
  dot_[0].x = 5;
  dot_[0].y = 3;
  for (int i = 1; i < snakeLen_; i++) {
    dot_[i].x = dot_[0].x-i;
    dot_[i].y = dot_[0].y;
  }
  tt_ = RIGHT;
}
Snake::~Snake() {

}
void Snake::drawSnake() {
  CommonFunction::cls();
  for (int i = 0; i < this->dot_.size(); i++) {
    CommonFunction::gotoxy(dot_[i].x, dot_[i].y);
    putchar(248);
  }
  Sleep(speed_);
  update();
}
void Snake::update() {
  if (is_move_) {
    for (int i = snakeLen_ - 1; i > 0; i--)
    dot_[i] = dot_[i-1];
    control();
  }
  drawSnake();
}
void Snake::control() {
  if (kbhit()) { // Press keyboard
    char key = _getch();
    if ((key == 'a' || key == 'A' || key == 52) && tt_ != RIGHT) {
      tt_ = LEFT;
    }else if ((key == 'd' || key == 'D' || key == 54) && tt_ != LEFT) {
      tt_ = RIGHT;
    }else if ((key == 'w' || key == 'W' || key == 56) && tt_ != DOWN) {
      tt_ = UP;
    }else if ((key == 's' || key == 'S' || key == 50) && tt_ != UP) {
      tt_ = DOWN;
    }else if (key == 32) {
      CommonFunction::pause();
    }
  }

  // move
  if (tt_ == UP) {
    dot_[0].y--;
  }else if (tt_ == DOWN) {
    dot_[0].y++;
  }else if (tt_ == LEFT) {
    dot_[0].x--;
  }else if (tt_ == RIGHT) {
    dot_[0].x++;
  }
}
