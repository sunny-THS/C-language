#include "Game.h"
Game::Game() {
  score_ =0;
  is_work = true;
  rect_.x = 0;
  rect_.y = 0;
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
void Game::MenuGame(int a, int b, int c, int d, int slt) {
  CommonFunction::SetColor(CadetBlue);
  DrawBoard(WIDTH_BOARD+strlen(TEXT_HOWTOGAME), HEIGHT_BOARD, slt);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_START))/2, HEIGHT/2);
  CommonFunction::SetColor(a);
  puts(TEXT_START);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_GAMEMODE))/2, HEIGHT/2+2);
  CommonFunction::SetColor(b);
  puts(TEXT_GAMEMODE);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_HOWTOGAME))/2, HEIGHT/2+4);
  CommonFunction::SetColor(c);
  puts(TEXT_HOWTOGAME);
  CommonFunction::GotoXY((WIDTH-strlen(TEXT_EXIT))/2, HEIGHT/2+6);
  CommonFunction::SetColor(d);
  puts(TEXT_EXIT);
}
int Game::SelectMenu() {
  static int select = 1;
  int t = 2;
  int y = CadetBlue, n = White;
  if (kbhit()) {
    char key = _getch();
    if (key==Up_Arrow) {
      DelBoard(WIDTH_BOARD+strlen(TEXT_HOWTOGAME), HEIGHT_BOARD, select);
      select-=t;
      if (select<1) {
        select = 7;
      }
    }
    if (key==Down_Arrow) {
      DelBoard(WIDTH_BOARD+strlen(TEXT_HOWTOGAME), HEIGHT_BOARD, select);
      select+=t;
      if (select>7) {
        select = 1;
      }
    }
    if (key==Enter_Key) {
      return select;
    }
  }
  switch (select) {
    case 1: MenuGame();
    break;
    case 3: MenuGame(n, y, n, n, select);
    break;
    case 5: MenuGame(n, n, y, n, select);
    break;
    case 7: MenuGame(n, n, n, y, select);
    break;
  }
  return 0;
}
void Game::DrawBoard(int w, int h, int index) {
  rect_.x = (WIDTH-w)/2;
  rect_.y = (HEIGHT-h)/2 + index;
  for (size_t i = rect_.y; i < h+rect_.y; i++) {
    for (size_t j = rect_.x; j < w+rect_.x; j++) {
      if ((i==rect_.y||i==h+rect_.y-1)||(j==rect_.x||j==w+rect_.x-1)) {
        CommonFunction::GotoXY(j, i);
        putchar(42);
      }
    }
  }
}
void Game::DelBoard(int w, int h, int index) {
  rect_.x = (WIDTH-w)/2;
  rect_.y = (HEIGHT-h)/2 + index;
  for (size_t i = rect_.y; i < h+rect_.y; i++) {
    for (size_t j = rect_.x; j < w+rect_.x; j++) {
      if ((i==rect_.y||i==h+rect_.y-1)||(j==rect_.x||j==w+rect_.x-1)) {
        CommonFunction::GotoXY(j, i);
        putchar(32);
      }
    }
  }
}
