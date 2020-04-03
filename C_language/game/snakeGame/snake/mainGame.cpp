#include "CommonFunction.h"
#include "SnakeGame.h"
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
        SnakeGame snakeGame;
        snakeGame.Init();
        snakeGame.draw();
      }break;
      case 2: info.printf_Howtogame();break; // how to play
      case 3: info.printf_Rank();break; // rank
      case 4: is_move = false; break; // end game
    }
  }

  // CommonFunction::pause();
  return 0;
}
