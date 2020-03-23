#include "Snake.h"

// initialization snake
Snake::Snake() {
  is_move_ = true;
  speed_ = 100;
  snakeLen_ = 3;
  tmp = snakeLen_;
  oxy_.x = 0;
  oxy_.y = 0;
  for (int i = 0; i < snakeLen_; i++) {
    dot_.push_back(oxy_);
  }
  dot_[0].x = CommonFunction::random(CONSOLE_WIDTH);
  dot_[0].y = CommonFunction::random(CONSOLE_HEIGHT);
  for (int i = 1; i < snakeLen_; i++) {
    dot_[i].x = dot_[0].x-i;
    dot_[i].y = dot_[0].y;
  }
  if (dot_[0].x>CONSOLE_WIDTH/2) {
    if (dot_[0].y>CONSOLE_HEIGHT/2) {
      tt_ = UP;
    }else {
      tt_ = DOWN;
    }
  }else {
    tt_ = RIGHT;
  }
}
Snake::~Snake() {
  dot_.clear();
}
void Snake::drawSnake() {
  CommonFunction::cls();
  drawFood();
  for (int i = 0; i < this->dot_.size(); i++) {
    CommonFunction::gotoxy(dot_[i].x, dot_[i].y);
    putchar(248);
  }
  Sleep(speed_);
  updateSnake();
}
void Snake::updateSnake() {
  if (is_move_) {
    for (int i = snakeLen_ - 1; i > 0; i--)
      dot_[i] = dot_[i-1];
    HandleInputAction();
    HandleCollision();
  }
  drawSnake();
}
void Snake::HandleInputAction() {
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
void Snake::HandleCollision() {
  if (dot_[0].x>CONSOLE_WIDTH-SCROLL_WIDTH || dot_[0].x<0 || dot_[0].y<0 || dot_[0].y>CONSOLE_HEIGHT) {
    CommonFunction::pause();
  }
  for (int iSnake=1; iSnake<snakeLen_; iSnake++) {
    if (dot_[0].x==dot_[iSnake].x && dot_[0].y==dot_[iSnake].y) {
      CommonFunction::pause();
    }
  }
  for (int iFruit = 0; iFruit < AMOUNT_FOOD; iFruit++) {
    if (dot_[0].x==fruit_[iFruit].x && dot_[0].y==fruit_[iFruit].y) {
      CommonFunction::pause();
    }
  }
}
