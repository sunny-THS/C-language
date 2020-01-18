#include<stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
void rectangle_full(int, int);
void rectangle(int, int);
void tamGiac1(int);
void tamGiac2(int);
void tamGiac3(int);
void tamGiac4(int);

int main() {
  int a= 5;
  int b= 8;
  rectangle_full(a, b);
  printf("\n");
  rectangle(a, b);
  printf("\n");
  tamGiac1(a);
  printf("\n");
  tamGiac2(a);
  printf("\n");
  tamGiac3(a);
  printf("\n");
  tamGiac4(a);

  return 0;
}

void rectangle_full(int a, int b) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      printf("* ");
    }
    printf("\n");
  }
}
void rectangle(int a, int b) {
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (i==0||i==a-1) {
          printf("* ");
        }else if (j==0||j==b-1) {
          printf("* ");
        }else {
          printf("  ");
        }
      }
      printf("\n");
    }
}

void tamGiac1(int a) {
  for (int i = 1; i <= a; i++) {
    for (int j = 0; j < i; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

void tamGiac2(int a) {
  for (int i = a; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

void tamGiac3(int a) {
  for (int i = 1; i <= a; i++) {
    for (int j = 0; j < a; j++) {
      if (i+j>a-1) {
        printf("* ");
      }else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void tamGiac4(int a) {
  for (int i = 0; i < a; i++) {
    for (int j = 1; j <= a; j++) {
      if (j>i) {
        printf("* ");
      }else {
        printf("  ");
      }
    }
    printf("\n");
  }
}
