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
  while (game.is_run_) {
    CommonFunction::SetColor(Blue);
    CommonFunction::GotoXY(0, 0);
    std::cout << TEXT_TITLEGAME;
    switch (game.SelectMenu()) {
      case 1: game.StartGame(snake, food);
      break;
      case 4: {
        game.HowToGame();
        CommonFunction::cls();
      }break;
      case 7: game.is_run_ = !game.is_run_;
      break;
      default: break;
    }
  }
  return 0;
}
