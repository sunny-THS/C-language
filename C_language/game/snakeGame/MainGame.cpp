#include "CommonFunction.h"
#include "BaseObject.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"

int main() {
  srand(time(0));

  CommonFunction::SetVideoMode(WIDTH, HEIGHT, "Snake Game");

  CommonFunction::ShowCur(false);
  Snake snake;
  Food food;
  Game game;
  food.Setup();
  snake.Setup();
  food.DrawFood();
  game.DrawTopBar();
  while (true) {
    snake.Update();
    snake.Draw();
    snake.Collision();
    Sleep(100);
  }
  return 0;
}
