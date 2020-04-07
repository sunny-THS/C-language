#include "CommonFunction.h"
#include "Ball.h"
#include "InterfaceGame.h"
#include "Paddle.h"
int main() {
  srand(time(0));
  InterfaceGame interfaceGame;
  Paddle player1;
  Paddle player2(false);
  Ball ball;
  bool is_run = true;
  while (is_run) {
    if (kbhit()) {
      char key=_getch();
      if (key=='W'||key=='w') {
        player1.move(-1);
      }else if (key=='S'||key=='s') {
        player1.move(1);
      }
      if (key==Numpad_8||key==Numpad_8) {
        player2.move(-1);
      }else if (key==Numpad_2||key==Numpad_2) {
        player2.move(1);
      }
    }
    interfaceGame.DrawFrameGame();
    player1.Draw();
    player2.Draw();
    ball.Update();
    ball.edgesCollision();
    ball.Draw();
    CommonFunction::delay(100);
  }
  return 0;
}
