#include "Game.h"
Game::Game() {
  score_ =0;
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
