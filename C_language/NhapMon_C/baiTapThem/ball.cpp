#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#define CONSOLE_HEIGHT 30
#define CONSOLE_WIDTH 120-2

class Ball {
  private:
    int x, y, x_s, y_s;
  public:
    Ball(int x, int y){
      x_s=1;
      y_s=1;
      this->x = x;
      this->y = y;
    }
    void draw();
    void update();
    void HandleCollision();
};
void textColor(int x);
void gotoxy(short int x, short int y);
int random(int max, int min = 0) {
  return min - rand()%(max-min+1);
}

int main() {
  srand(time(0));
  Ball ball(random(CONSOLE_WIDTH), random(CONSOLE_HEIGHT));
  ball.draw();
  return 0;
}
void textColor(int x) {
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, x);
}
void gotoxy(short int x, short int y) {
  static HANDLE h = NULL;
  if (!h) {
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  }
  COORD c = { x, y };
  SetConsoleCursorPosition(h, c);
}
void Ball::draw() {
  while (1) {
    system("cls");
    gotoxy(x, y);
    putchar(248);
    Sleep(100);
    update();
    if (kbhit()) {
      char key = _getch();
      if (key == 27) {
        break;
      }
    }
  }
}
void Ball::update() {
  HandleCollision();
  x+=x_s;
  y+=y_s;
}
void Ball::HandleCollision() {
  if (x>CONSOLE_WIDTH) {
    x_s = -1;
  }else if (x<0) {
    x_s = 1;
  }

  if (y>CONSOLE_HEIGHT-1) {
    y_s = -1;
  }else if (y<0) {
    y_s = 1;
  }
}
