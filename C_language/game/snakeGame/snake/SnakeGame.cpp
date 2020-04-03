#include "SnakeGame.h"

SnakeGame::SnakeGame() {}
SnakeGame::~SnakeGame() {
  dot_.clear();
}
// initialization SnakeGame
void SnakeGame::Init() {
  speed_ = 200; // speed is value from 100 to 200
  is_move_ = true;
  is_pause_ = false;
  snakeLen_ = 3; // setup SnakeGame
  oxy_.x = 0;
  oxy_.y = 0;

  for (int i = 0; i < snakeLen_; i++) {
    dot_.push_back(oxy_);
  }
  dot_[0].x = CommonFunction::random(LIMIT_BOARD_GAME-1);
  dot_[0].y = CommonFunction::random(CONSOLE_HEIGHT-1);
  for (int i = 1; i < snakeLen_; i++) {
    dot_[i].x = dot_[0].x-i;
    dot_[i].y = dot_[0].y;
  }
  if (dot_[0].x>(LIMIT_BOARD_GAME)/2) {
    if (dot_[0].y>CENTER_CONSOLE_HEIGHT) {
      tt_ = UP;
    }else {
      tt_ = DOWN;
    }
  }else {
    tt_ = RIGHT;
  }
  setup(); // initialization food
}
void SnakeGame::draw() {
  while (strcmp(info.GetName(),"")==0 || strcmp(info.GetName()," ")==0) {
    info.inputUserName();
  }
  while (is_move_) {
    CommonFunction::cls();
    // test speed of snake
    // CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-8)/2, HEIGHT_BOARD_INFO-HEIGHT_BOARD_INFO/3);
    // std::cout << speed_;
    drawFood();
    info.boardInfoUser();
    drawBoardGame();
    drawBodySnake();
    drawBoardInfo();
    if (boardSelect()) // when is_pause_ = true, it will appear
      // if select exit return 1
      break;
    Sleep(speed_);
    HandleInputAction();
    updateSnake();
    HandleCollision();
    GameOver();
  }
}
void SnakeGame::updateSnake() {
  for (int i = dot_.size() - 1; i > 0; i--)
    dot_[i] = dot_[i-1];
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
void SnakeGame::HandleInputAction() {
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
    }else if (key == Space_Key) {
      is_pause_ = true;
    }
  }
}
void SnakeGame::HandleCollision() {
  if (dot_[0].x>LIMIT_BOARD_GAME-1 || dot_[0].x<0 || dot_[0].y<0 || dot_[0].y>CONSOLE_HEIGHT-1) {
    is_move_ = false;
    // CommonFunction::pause();
  }
  for (int iSnake=1; iSnake<dot_.size(); iSnake++) {
    if (dot_[0].x==dot_[iSnake].x && dot_[0].y==dot_[iSnake].y) {
      is_move_ = false;
      // CommonFunction::pause();
    }
  }
  for (int iFruit = 0; iFruit < AMOUNT_FOOD; iFruit++) {
    if (dot_[0].x==fruit_[iFruit].x && dot_[0].y==fruit_[iFruit].y) {
      HandleScore(iFruit);
    }
  }
}
void SnakeGame::HandleScore(int index) {
  dot_.push_back(oxy_);
  updateFruit(GetIX(), GetIY(), index);
  info.SetScore(dot_.size()-snakeLen_);
  speed_ -= 2;
  if (speed_<LIMIT_SPEED) {
    speed_ = LIMIT_SPEED;
  }
}
void SnakeGame::drawBoardGame() {
  for (int i = 0; i < CONSOLE_HEIGHT; i++) {
    CommonFunction::textColor(White);
    CommonFunction::gotoxy(LIMIT_BOARD_GAME, i);
    putchar(186);
  }
}
void SnakeGame::drawBoardInfo() {
  for (int i = 0; i < LIMIT_BOARD_INFO; i++) {
    CommonFunction::textColor(White);
    CommonFunction::gotoxy(WIDTH_BOARD_INFO+i, HEIGHT_BOARD_INFO);
    putchar(205);
  }
}
void SnakeGame::drawBodySnake() {
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
int SnakeGame::boardSelect() {
  int y = CadetBlue, n = White;//y is select, n is no select
  int select = 1;//1 is resume game, 2 is start game, 3 is howToPlay, 4 is end game
  while (is_pause_) {
    switch (select) {
      case 1: titleSelect(n, n, n, y); break;
      case 2: titleSelect(y, n, n); break;
      case 3: titleSelect(n, y, n); break;
      case 4: titleSelect(n, n, y); break;
    }

    if (kbhit()) { // press keysboard
      char key = _getch();
      if (key == 'w' || key == 'W' || key == Up_Arrow || key == Numpad_8) {
        select--;
        if (select<1) {
          select = 4;
        }
      }else if (key == 's' || key == 'S' || key == Down_Arrow || key == Numpad_2) {
        select++;
        if (select>4) {
          select = 1;
        }
      }else if (key == Enter_Key) {
        switch(select) {
          case 1: {
            is_pause_ = false;
          }break;
          case 2: {
            is_pause_ = false;
            info.SetName("");
            info.SetScore(0);
            dot_.clear();
            while (strcmp(info.GetName(),"")==0 || strcmp(info.GetName()," ")==0) {
              info.inputUserName();
            }
            Init();
          }break;
          case 3: {
            is_pause_ = false;
            info.SetScore(0);
            dot_.clear();
            Init();
          }break;
          case 4: dot_.clear(); return 1;
        }
      }
    }
  }
  return 0;
}
void SnakeGame::titleSelect(const int& a, const int& b, const int& c, const int& d) {
  if (is_pause_) {
    CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(TEXT_RESUME))/2, HEIGHT_BOARD_INFO+(CONSOLE_HEIGHT-HEIGHT_BOARD_INFO)/2-2);
    CommonFunction::textColor(d);
    puts(TEXT_RESUME);
  }
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(TEXT_NEWGAME))/2, HEIGHT_BOARD_INFO+(CONSOLE_HEIGHT-HEIGHT_BOARD_INFO)/2-1);
  CommonFunction::textColor(a);
  puts(TEXT_NEWGAME);
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(TEXT_RESTART))/2, HEIGHT_BOARD_INFO+(CONSOLE_HEIGHT-HEIGHT_BOARD_INFO)/2);
  CommonFunction::textColor(b);
  puts(TEXT_RESTART);
  CommonFunction::gotoxy(LIMIT_BOARD_GAME+(LIMIT_BOARD_INFO+1+SCROLL_WIDTH-strlen(TEXT_EXIT))/2, HEIGHT_BOARD_INFO+(CONSOLE_HEIGHT-HEIGHT_BOARD_INFO)/2+1);
  CommonFunction::textColor(c);
  puts(TEXT_EXIT);
}
void SnakeGame::GameOver() {
  int y = CadetBlue, n = White;//y is select, n is no select
  int select = 1;//1 is start game, 2 is howToPlay, 3 is exit
  if (!is_move_) {
    info.saveInfo();
  }
  while (!is_move_) {
    CommonFunction::gotoxy((LIMIT_BOARD_GAME-strlen(TEXT_GAMEOVER))/2, CENTER_CONSOLE_HEIGHT);
    CommonFunction::textColor(Red);
    puts(TEXT_GAMEOVER);
    switch (select) {
      case 1: titleSelect(y, n, n); break;
      case 2: titleSelect(n, y, n); break;
      case 3: titleSelect(n, n, y); break;
    }

    if (kbhit()) { // press keysboard
      char key = _getch();
      if (key == 'w' || key == 'W' || key == Up_Arrow || key == Numpad_8) {
        select--;
        if (select<1) {
          select = 3;
        }
      }else if (key == 's' || key == 'S' || key == Down_Arrow || key == Numpad_2) {
        select++;
        if (select>3) {
          select = 1;
        }
      }else if (key == Enter_Key) {
        switch(select) {
          case 1: {
            is_move_ = true;
            info.SetName("");
            info.SetScore(0);
            dot_.clear();
            while (strcmp(info.GetName(),"")==0 || strcmp(info.GetName()," ")==0) {
              info.inputUserName();
            }
            Init();
          }break;
          case 2: {
            is_move_ = true;
            info.SetScore(0);
            dot_.clear();
            Init();
          }break;
          case 3: dot_.clear(); return;
        }
      }
    }
  }
}
