#include "Snake.h"
Snake::Snake() {}
Snake::~Snake() {
  dot_.clear();
}
void Snake::Setup() {
  is_move_ = true;
  is_pause_ = false;
  rect_.x = WIDTH;
  rect_.y = HEIGHT;
  len_start_ = 3;
  for (size_t i = 0; i < len_start_; i++) {
    dot_.push_back(GetRect());
  }
  dot_[0].x = CommonFunction::random(WIDTH/2);
  dot_[0].y = CommonFunction::random(HEIGHT/2);
  for (size_t i = 1; i < len_start_; i++) {
    dot_[i].x = dot_[i].x-1;
    dot_[i].y = dot_[i].y;
  }
  tt_ = RIGHT;
}
void Snake::Draw() {
  for (size_t i = 0; i < dot_.size(); i++) {
    CommonFunction::GotoXY(dot_[i].x, dot_[i].y);
    if (i==0) {
      CommonFunction::SetColor(Green);
      putchar(248);
    }else {
      CommonFunction::SetColor(White);
      putchar(248);
    }
  }
}
void Snake::Update() {
  for (int i = dot_.size() - 1; i > 0; i--) {
    CommonFunction::GotoXY(dot_[i].x, dot_[i].y);
    putchar(32);
    dot_[i] = dot_[i-1];
  }
  HandleInputAction();
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
void Snake::HandleInputAction() {
  if (kbhit()) { // Press keyboard
    char key = _getch();
    if ((key=='a'||key=='A'||key==Numpad_4)&&tt_!=RIGHT&&!is_pause_) {
      tt_ = LEFT;
    }else if ((key=='d'||key=='D'||key==Numpad_6)&&tt_!=LEFT&&!is_pause_) {
      tt_ = RIGHT;
    }else if ((key=='w'||key=='W'||key==Numpad_8)&&tt_!=DOWN&&!is_pause_) {
      tt_ = UP;
    }else if ((key=='s'||key=='S'||key==Numpad_2)&&tt_!=UP&&!is_pause_) {
      tt_ = DOWN;
    }else if (key==Space_Key) {
      is_pause_ = true; // pause game
    }
  }
}
void Snake::HandleCollision(Food &food) {
  if (dot_[0].x>WIDTH-2 || dot_[0].x<1 || dot_[0].y<1 || dot_[0].y>HEIGHT-1) {
    is_move_ = false;
    system("pause>nul");

    // CommonFunction::pause();
  }
  for (int iSnake=1; iSnake<dot_.size(); iSnake++) {
    if (dot_[0].x==dot_[iSnake].x && dot_[0].y==dot_[iSnake].y) {
      is_move_ = false;
      system("pause>nul");

      // CommonFunction::pause();
    }
  }
  for (int iFruit = 0; iFruit < AMOUNT_FOOD; iFruit++) {
    if (dot_[0].x==food.fruit_[iFruit].x && dot_[0].y==food.fruit_[iFruit].y) {
      food.UpdateFruit(food.GetIX(), food.GetIY(), iFruit);
      food.DrawOneFood(iFruit);
      dot_.push_back(rect_);
    }
  }
}
