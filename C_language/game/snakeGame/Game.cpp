#include "Game.h"
Game::Game() {
  score_ =0;
  is_run = true;
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
void Game::StartGame(Snake snake, Food food, bool mod) {
  CommonFunction::cls();
  DrawTopBar();
  snake.Setup();
  food.Setup();
  food.DrawFood();
  while (snake.is_move_) {
    Score(snake);
    snake.Update();
    snake.Draw();
    snake.HandleCollision(food);
    Sleep(100);
  }
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
        break;
      }
    }
  }
}
