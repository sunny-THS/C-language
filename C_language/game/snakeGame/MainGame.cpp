#include "CommonFunction.h"
#include "BaseObject.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"

int main() {
  srand(time(0));

  CommonFunction::SetConsole(WIDTH, HEIGHT, "Snake Game");
  CommonFunction::ShowCur(false);

  Snake snake;
  Food food;
  Game game;
  food.Setup();
  snake.Setup();
  // food.DrawFood();
  // game.DrawTopBar();
  game.MenuGame();
  while (true) {
    game.SelectMenu();
    // game.Score(snake);
    // snake.HandleCollision(food);
    // snake.Update();
    // snake.Draw();
    Sleep(100);
  }
  return 0;
}
