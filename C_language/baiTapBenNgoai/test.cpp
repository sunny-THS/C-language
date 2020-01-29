#include<stdio.h>
#include<windows.h>
#include<string.h>
typedef struct animation{
  char text[30];
  int x, y, speed;
}A;
void gotoxy(int, int);

int main(){
  A e;
  e.x=0;
  e.y=0;
  e.speed = 100;
  strcpy(e.text, "hello word");
  while(1){
    system("cls");
    gotoxy(e.x, e.y++);
    printf("%s", e.text);
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
