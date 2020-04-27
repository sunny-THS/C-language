#include "Game.h"
Game::Game() {
  score_ =0;
  is_run_ = true;
  is_pause_ = !is_run_;
  rect_.x = 0;
  rect_.y = 0;
  snake_ = new Snake();
  speed_ = 150;
}
void Game::DrawTopBar() {
  for (size_t i = 0; i < WIDTH; i++) {
    CommonFunction::GotoXY(i, 0);
    CommonFunction::SetColor(Green);
    putchar(95);
  }
}
void Game::Score(Snake snake) {
  score_ = snake.dot_.size() - snake.len_start_;
  char *scoreText = "SCORE: ";
  CommonFunction::SetColor(Green);
  CommonFunction::GotoXY((WIDTH-3-strlen(scoreText))/2, 0);
  std::cout << scoreText << score_;
}
void Game::Setup() {
  CommonFunction::SetColor(Blue);
  std::cout << TEXT_TITLEGAME;
  for (size_t i = 1; i <= 7; i+=3) {
    DrawBoard(WIDTH_BOARD+strlen(TEXT_HOWTOGAME), HEIGHT_BOARD, i, Red);
  }
}
void Game::MenuGame(int a, int b, int c, int slt) {
  DrawBoard(WIDTH_BOARD+strlen(TEXT_HOWTOGAME), HEIGHT_BOARD, slt, Yellow);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_START))/2, HEIGHT/2);
  CommonFunction::SetColor(a);
  puts(TEXT_START);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_HOWTOGAME))/2, HEIGHT/2+3);
  CommonFunction::SetColor(b);
  puts(TEXT_HOWTOGAME);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_EXIT))/2, HEIGHT/2+6);
  CommonFunction::SetColor(c);
  puts(TEXT_EXIT);
}
int Game::SelectMenu() {
  static int select = 1;
  int t = 3;
  int mxSelect = 7, mnSelect = 1;
  int y = Red, n = Yellow;
  if (kbhit()) {
    char key = _getch();
    if (key==Up_Arrow) {
      DelBoard(WIDTH_BOARD+strlen(TEXT_HOWTOGAME), HEIGHT_BOARD, select, Red);
      select-=t;
      if (select<mnSelect) {
        select = mxSelect;
      }
    }
    if (key==Down_Arrow) {
      DelBoard(WIDTH_BOARD+strlen(TEXT_HOWTOGAME), HEIGHT_BOARD, select, Red);
      select+=t;
      if (select>mxSelect) {
        select = mnSelect;
      }
    }
    if (key==Enter_Key) {
      return select;
    }
  }
  switch (select) {
    case 1: MenuGame();
    break;
    case 4: MenuGame(n, y, n, select);
    break;
    case 7: MenuGame(n, n, y, select);
    break;
  }
  return 0;
}
void Game::DrawBoard(int w, int h, int index, int color) {
  rect_.x = (WIDTH-w)/2;
  rect_.y = (HEIGHT-h)/2 + index;
  CommonFunction::SetColor(color);
  for (size_t i = rect_.y; i < h+rect_.y; i++) {
    for (size_t j = rect_.x; j < w+rect_.x; j++) {
      if (!(i==rect_.y||i==h+rect_.y-1)&&(j==rect_.x||j==w+rect_.x-1)) {
        CommonFunction::GotoXY(j, i);
        putchar(42);
      }
    }
  }
}
void Game::DelBoard(int w, int h, int index, int color) {
  rect_.x = (WIDTH-w)/2;
  rect_.y = (HEIGHT-h)/2 + index;
  CommonFunction::SetColor(color);
  for (size_t i = rect_.y; i < h+rect_.y; i++) {
    for (size_t j = rect_.x; j < w+rect_.x; j++) {
      if (!(i==rect_.y||i==h+rect_.y-1)&&(j==rect_.x||j==w+rect_.x-1)) {
        CommonFunction::GotoXY(j, i);
        putchar(42);
      }
    }
  }
}
void Game::StartGame(bool mode) {
  CommonFunction::cls();
  DrawTopBar();
  snake_->Setup();
  food_.Setup();
  food_.DrawFood();
  while (snake_->is_move_) {
    int tspeed = speed_-snake_->dot_.size();
    if (tspeed<20) {
      tspeed = 20;
    }
    Score(*snake_);
    snake_->Update();
    snake_->Draw();
    snake_->HandleCollision(food_);
    Sleep(tspeed);
    if (!snake_->is_move_) {
      GameOver();
    }
    if (snake_->HandleInputAction()) {
      PauseGame();
    }
  }
  delete snake_;
  snake_ = new Snake();
}
void Game::HowToGame() {
  CommonFunction::cls();
  while (1) {
    CommonFunction::GotoXY((WIDTH-strlen(HOWTOPLAY))/2, HEIGHT/2);
    CommonFunction::SetColor(Green);
    puts(HOWTOPLAY);
    if (kbhit()) {
      char key = _getch();
      if (key == Esc_Key) {
        CommonFunction::cls();
        break;
      }
    }
  }
}
void Game::GameOver() {
  int select = 1;
  int mnSelect = 1, mxSelect = 2;
  int y=Yellow, n=White;
  is_pause_ = !is_pause_;
  // create frame
  DrawFrame();
  // create Menu
  MenuGameOver();
  while (is_pause_) {
    switch (select) {
      case 1: MenuGameOver(y, n);break;
      case 2: MenuGameOver(n, y);break;
    }
    // Handle press keyboard
    if (kbhit()) {
      char key = _getch();
      if (key==Up_Arrow) {
        select--;
        if (select<mnSelect) {
          select = mxSelect;
        }
      }else if (key==Down_Arrow) {
        select++;
        if (select>mxSelect) {
          select = mnSelect;
        }
      }else if (key==Enter_Key) {
        switch (select) {
          case 1: {
            delete snake_;
            snake_ = new Snake();
            is_pause_=!is_pause_;
            CommonFunction::cls();
            DrawTopBar();
            snake_->Setup();
            food_.Setup();
            food_.DrawFood();
          }break;
          case 2: {
            is_pause_=!is_pause_;
            CommonFunction::cls();
          }break;
        }
      }
    }
  }
}
void Game::MenuGameOver(int a, int b) {
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_GAMEOVER))/2+1, (HEIGHT-4)/2);
  CommonFunction::SetColor(Red);
  puts(TEXT_GAMEOVER);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_RESTART))/2, (HEIGHT)/2);
  CommonFunction::SetColor(a);
  puts(TEXT_RESTART);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_EXIT))/2, (HEIGHT+2)/2);
  CommonFunction::SetColor(b);
  puts(TEXT_EXIT);
}
void Game::PauseGame() {
  int select = 1;
  int mnSelect = 1, mxSelect = 3;
  int y=Red, n=White;
  is_pause_ = !is_pause_;
  // create frame
  DrawFrame();
  // create Menu
  MenuPause();
  while (is_pause_) {
    switch (select) {
      case 1: MenuPause(y, n, n);break;
      case 2: MenuPause(n, y, n);break;
      case 3: MenuPause(n, n, y);break;
    }
    // Handle press keyboard
    if (kbhit()) {
      char key = _getch();
      if (key==Up_Arrow) {
        select--;
        if (select<mnSelect) {
          select = mxSelect;
        }
      }else if (key==Down_Arrow) {
        select++;
        if (select>mxSelect) {
          select = mnSelect;
        }
      }else if (key==Enter_Key) {
        switch (select) {
          case 1: {
            is_pause_=!is_pause_;
            CommonFunction::cls();
            food_.DrawFood();
            DrawTopBar();
          }break;
          case 2: {
            delete snake_;
            snake_ = new Snake();
            is_pause_=!is_pause_;
            CommonFunction::cls();
            DrawTopBar();
            snake_->Setup();
            food_.Setup();
            food_.DrawFood();
          }break;
          case 3: {
            is_pause_=!is_pause_;
            snake_->is_move_ = !snake_->is_move_;
            CommonFunction::cls();
          }break;
        }
      }
    }
  }
}
void Game::DrawFrame() {
  CommonFunction::SetColor(190);
  for (size_t i = 0; i < HEIGHT_PAUSE; i++) {
    for (size_t j = 0; j < WIDTH_PAUSE; j++) {
      CommonFunction::GotoXY((WIDTH-WIDTH_PAUSE)/2+j, (HEIGHT-HEIGHT_PAUSE)/2+i);
      if (i==0||i==HEIGHT_PAUSE-1) {
        std::cout << " ";
      }else if ((j==0||j==WIDTH_PAUSE-1)) {
        std::cout << " ";
      }
    }
  }
}
void Game::MenuPause(int a, int b, int c) {
  CommonFunction::GotoXY((WIDTH-strlen(TITLE))/2, (HEIGHT-6)/2);
  CommonFunction::SetColor(CadetBlue);
  puts(TITLE);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_RESUME))/2, (HEIGHT-2)/2);
  CommonFunction::SetColor(a);
  puts(TEXT_RESUME);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_RESTART))/2, (HEIGHT)/2);
  CommonFunction::SetColor(b);
  puts(TEXT_RESTART);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_EXIT))/2, (HEIGHT+2)/2);
  CommonFunction::SetColor(c);
  puts(TEXT_EXIT);
}
void Game::SetTime() {
  time(&rawTime_);
  localTime_ = localtime(&rawTime_);
  localTime_->tm_year+=1900;
  localTime_->tm_mon++;
}
