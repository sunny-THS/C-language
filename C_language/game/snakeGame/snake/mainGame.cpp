#include "CommonFunction.h"
#include "Snake.h"
#include "InfoUser.h"

int main() {
  srand(time(0));
  bool is_move = true;
  system("title SnakeGame"); // title on title bar

  InfoUser info;
  while (is_move) {
    CommonFunction::cls();
    switch (info.titleGame()) {
      case 1: { // start game
        Snake snake;
        snake.Init();
        snake.draw();
      }break;
      case 3: info.printf_Rank();break; // how to game
      case 4: is_move = false; break; // end game
    }
  }

  // CommonFunction::pause();
  return 0;
}
