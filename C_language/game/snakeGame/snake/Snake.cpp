#include "Snake.h"

// initialization snake
Snake::Snake() {
  is_move_ = true;
  speed_ = 200; // speed is value from 100 to 200
  snakeLen_ = 70; // setup snake
  oxy_.x = 0;
  oxy_.y = 0;
}
Snake::~Snake() {
  dot_.clear();
}
void Snake::Init() {
  for (int i = 0; i < snakeLen_; i++) {
    dot_.push_back(oxy_);
  }
  dot_[0].x = CommonFunction::random(LIMIT_BOARD_GAME-1);
  dot_[0].y = CommonFunction::random(CONSOLE_HEIGHT);
  for (int i = 1; i < snakeLen_; i++) {
    dot_[i].x = dot_[0].x-i;
    dot_[i].y = dot_[0].y;
  }
  if (dot_[0].x>(LIMIT_BOARD_GAME)/2) {
    if (dot_[0].y>CONSOLE_HEIGHT/2) {
      tt_ = UP;
    }else {
      tt_ = DOWN;
    }
  }else {
    tt_ = RIGHT;
  }
}
void Snake::draw() {
  while (strcmp(info.GetName(),"")==0 || strcmp(info.GetName()," ")==0) {
    info.inputUserName();
  }
  CommonFunction::cls();
  drawFood();
  info.boardInfoUser();
  drawBoardGame();
  drawBodySnake();
  drawBoardInfo();
  Sleep(speed_);
  updateSnake();
}
void Snake::updateSnake() {
  if (is_move_) {
    for (int i = dot_.size() - 1; i > 0; i--)
      dot_[i] = dot_[i-1];
    HandleInputAction();
    HandleCollision();
  }
  draw();
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
  if (dot_[0].x>LIMIT_BOARD_GAME-1 || dot_[0].x<0 || dot_[0].y<0 || dot_[0].y>CONSOLE_HEIGHT-1) {
    is_move_ = false;
    CommonFunction::pause();
  }
  for (int iSnake=1; iSnake<dot_.size(); iSnake++) {
    if (dot_[0].x==dot_[iSnake].x && dot_[0].y==dot_[iSnake].y) {
      is_move_ = false;
      CommonFunction::pause();
    }
  }
  for (int iFruit = 0; iFruit < AMOUNT_FOOD; iFruit++) {
    if (dot_[0].x==fruit_[iFruit].x && dot_[0].y==fruit_[iFruit].y) {
      HandleScore(iFruit);
    }
  }
}
void Snake::HandleScore(int index) {
  dot_.push_back(oxy_);
  SetRectFruit(CommonFunction::random(LIMIT_BOARD_GAME-1), CommonFunction::random(CONSOLE_HEIGHT-1), index);
  info.SetScore(dot_.size()-snakeLen_);
  speed_ -= 2;
  if (speed_<100) {
    speed_ = LIMIT_SPEED;
  }
}
void Snake::drawBoardGame() {
  for (int i = 0; i < CONSOLE_HEIGHT; i++) {
    CommonFunction::textColor(White);
    CommonFunction::gotoxy(LIMIT_BOARD_GAME, i);
    putchar(186);
  }
}
void Snake::drawBoardInfo() {
  for (size_t i = 0; i < LIMIT_BOARD_INFO; i++) {
    CommonFunction::textColor(White);
    CommonFunction::gotoxy(WIDTH_BOARD_INFO+i, HEIGHT_BOARD_INFO);
    putchar(205);
  }
}
void Snake::drawBodySnake() {
  for (int i = 0; i < this->dot_.size(); i++) {
    if (i==0) { // head snake
      CommonFunction::textColor(Blue);
      CommonFunction::gotoxy(dot_[i].x, dot_[i].y);
      putchar(248);
    }else {
      CommonFunction::textColor(Green);
      CommonFunction::gotoxy(dot_[i].x, dot_[i].y);
      putchar(248);
    }
  }
}
