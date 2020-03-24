#include "CommonFunction.h"
#include "Snake.h"
#include "InfoUser.h"

int main() {
  srand(time(0));
  char label[] = "User name: ";
  char name[50];
  Snake snake;
  InfoUser info;
  switch (info.titleGame()) {
    case 1: {
      CommonFunction::cls();
      CommonFunction::gotoxy((CONSOLE_WIDTH-strlen(label))/2, CONSOLE_HEIGHT/2);
      std::cout << label;
      info.SetName(gets(name));
      // std::cout<<info.GetName();
      // _getch();
      snake.Init();
      snake.draw();
    }
  }

  // CommonFunction::pause();
  return 0;
}
