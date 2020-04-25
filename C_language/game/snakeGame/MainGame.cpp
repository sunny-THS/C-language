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
  game.Setup();
  game.MenuGame();
  while (game.is_run) {
    switch (game.SelectMenu()) {
      case 1: game.StartGame(snake, food);
      break;
      case 4: game.HowToGame();
      break;
      case 7:
      break;
      default: break;
    }
  }
  return 0;
}
