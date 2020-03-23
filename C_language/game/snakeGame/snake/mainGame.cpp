#include "CommonFunction.h"
#include "Snake.h"
#include "Game.h"

int main() {
  srand(time(0));
  Game game;
  Snake snake;
  snake.drawSnake();
  // CommonFunction::pause();
  return 0;
}
