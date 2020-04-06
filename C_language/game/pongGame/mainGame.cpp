#include "CommonFunction.h"
#include "Ball.h"
#include "InterfaceGame.h"
int main() {
  InterfaceGame interfaceGame;
  Ball ball;
  bool is_run = true;
  while (is_run) {
    interfaceGame.DrawFrameGame();
    ball.Update();
    ball.edgesCollision();
    ball.Draw();

    CommonFunction::delay(200);
  }
  return 0;
}
