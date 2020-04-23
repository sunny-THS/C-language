#include "CommonFunction.h"
#include "BaseObject.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"

int main() {
  srand(time(0));

  CommonFunction::SetConsole(WIDTH, HEIGHT, "Snake Game", false, false);

  Snake snake;
  Food food;
  Game game;
  CommonFunction::SetColor(Green);
  std::cout << TEXT_TITLEGAME;
  game.MenuGame();
  while (game.is_run) {
    switch (game.SelectMenu()) {
      case 1:
      break;
      case 3:
      break;
      case 5:
      break;
      case 7:
      break;
      default: break;
    }
  }
  return 0;
}
