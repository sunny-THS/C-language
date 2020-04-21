#include "Game.h"
void Game::DrawTopBar() {
  CommonFunction::SetColor(240);
  for (size_t i = 0; i < WIDTH-2; i++) {
    CommonFunction::GotoXY(i, 0);
    putchar(32);
  }
}
void Game::HandleCollision() {
  if (snake_.Collision()==-1) {
    system("pause>nul");
  }
  if (snake_.Collision()) {
    system("pause>nul");
  }
}
