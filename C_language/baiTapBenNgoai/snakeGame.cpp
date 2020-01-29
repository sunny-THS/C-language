#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

//tuy vao cua so console
#define consoleHeight 30 //chieu cao cua console
#define consoleWidth 120 // chieu dai cua console

//gia tri cua chieu dai, chieu rong cua khung game
enum KHUNGGAME {
  // xy va yx tuong duong voi toa do x
  // xx va yy tuong duong vơi toa do y
  xy = 2,
  xx = consoleWidth/2,
  yx = 1,
  yy = consoleHeight-consoleHeight/5
};

enum TrangThai {UP, DOWN, LEFT, RIGHT};

typedef struct animation{
  char text[30];
  int x, y, speed;
  TrangThai tt;
}A;

void draw(int, int, int, int);
void gotoxy(int, int);
void cls();
void textColor(int);

int main(){
  A e;
  e.text[0] = 220;
  e.text[1] = '\0';
  int slen = strlen(e.text);
  e.x=(xx-slen)/2;
  e.y=yx;
  e.speed = 100;

  while (1) {
    cls();//xoa man hinh moi vong lap
    draw(xx, xy, yx, yy);
    gotoxy(e.x, e.y); // diem xuat phat
    textColor(14); //text color
    printf("%s", e.text);

    //xu ly cham bien
    if (e.y < yx) {
      e.tt = DOWN;
    }else if (e.y > yy) {
      e.tt = UP;
    }else if (e.x < xy) {
      e.tt = RIGHT;
    }else if (e.x > xx) {
      e.tt = LEFT;
    }

    //dieu khien nut
    if (kbhit()) {
      char key = getch();
      if (key == 'A' || key == 'a') {
        e.tt = LEFT;
      }else if (key =='D' || key=='d') {
        e.tt = RIGHT;
      }else if (key =='W' || key=='w') {
        e.tt = UP;
      }else if (key =='S' || key=='s') {
        e.tt = DOWN;
      }
    }

    //auto di chuyen
    if (e.tt == DOWN) {
      e.y++;
    }else if (e.tt == UP) {
      e.y--;
    }else if (e.tt == RIGHT) {
      e.x++;
    }else if (e.tt == LEFT) {
      e.x--;
    }

    Sleep(e.speed); //toc do game
  }
  return 0;
}

void gotoxy(int x, int y){
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h, c);
}
void cls(){
  system("cls");
}
//tao mau chu
void textColor(int x){
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, x);
}

//ve khung hinh
void draw(int xx, int xy, int yx, int yy){
  for (int i = xy; i <= xx; i++) {
    for (int j = yx; j <= yy; j++) {
      if (i==xx || i==xy) {
        gotoxy(i, j);
        printf("%c", 179);
      }else if (j==yy) {
        gotoxy(i, j);
        printf("%c", 95);
      }else if (j==yx) {
        gotoxy(i, j);
        printf("%c", 196);
      }
    }
  }
}
