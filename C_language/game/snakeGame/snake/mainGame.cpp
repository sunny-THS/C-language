#include "CommonFunction.h"
#include "Snake.h"
#include "InfoUser.h"

int main() {
  srand(time(0));
  system("title SnakeGame");
  // Snake snake;
  // snake.Init();
  // snake.draw();
  InfoUser info;
  switch (info.titleGame()) {
    case 1: {
      Snake snake;
      snake.Init();
      snake.draw();
    }
  }

  // CommonFunction::pause();
  return 0;
}
