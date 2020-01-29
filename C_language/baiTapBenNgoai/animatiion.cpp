#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define consoleHeight 30
#define consoleWidth 120

enum TrangThai {UP, DOWN, LEFT, RIGHT};

typedef struct animation{
  char text[30];
  int x, y, speed;
  TrangThai tt;
}A;

void gotoxy(int, int);
void cls();
void textColor(int);
int random(int, int);

int main(){
  srand(time(NULL)); //phat sinh mau ngau nhien

  A e;
  strcpy(e.text, "hello word");
  int slen = strlen(e.text);
  e.x=(consoleWidth-slen)/2;
  e.y=0;
  e.speed = 100;
  while(1){
    cls();
    gotoxy(e.x, e.y);
    textColor(random(0,15));
    printf("%s", e.text);

    //xu ly cham bien
    if (e.y <= 0) {
      e.tt = DOWN;
    }else if (e.y >= consoleHeight-1) {
      e.tt = UP;
    }else if (e.x <=0) {
      e.tt = RIGHT;
    }else if (e.x >= consoleWidth-slen) {
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

    if (e.tt == DOWN) {
      e.y++;
    }else if (e.tt == UP) {
      e.y--;
    }else if (e.tt == RIGHT) {
      e.x++;
    }else{
      e.x--;
    }

    Sleep(e.speed);
  }
  return 0;
}

void gotoxy(int x, int y){
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
void cls(){
  system("cls");
}
void textColor(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
int random(int min, int max){
  return min + rand()%(max+1-min);
}
