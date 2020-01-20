#include<stdio.h>
#include <windows.h>

enum KHOANGCACH {
  LENGHT_TOP = 10,
  LENGHT_LEFT = 2
};

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
void tamGiac1_1(int);
void tamGiac2(int);
void tamGiac2_2(int);
void tamGiac3(int);
void tamGiac3_3(int);
void tamGiac4(int);
void tamGiac4_4(int);
void tamGiacCan(int);

int main() {
  int a= 5;
  int b= 8;
  rectangle_full(a, b);
  rectangle(a, b);
  tamGiac1(a);
  tamGiac1_1(a);
  tamGiac2(a);
  tamGiac2_2(a);
  tamGiac3(a);
  //tamGiac3_3(a);
  tamGiac4(a);
  //tamGiac4_(a);
  tamGiacCan(a);


  return 0;
}

void rectangle_full(int a, int b) {
  for (int i = 0; i < a; i++) {
    gotoxy(0+LENGHT_LEFT, i+LENGHT_TOP);
    for (int j = 0; j < b; j++) {
      printf("* ");
    }
    printf("\n");
  }
}
void rectangle(int a, int b) {
    for (int i = 0; i < a; i++) {
      gotoxy(LENGHT_LEFT,i+LENGHT_TOP-8);
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
    gotoxy(20+LENGHT_LEFT,i-1+LENGHT_TOP);
    for (int j = 0; j < i; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

void tamGiac2(int a) {
  for (int i = a; i > 0; i--) {
    gotoxy(35+LENGHT_LEFT,a-i+LENGHT_TOP);
    for (int j = 0; j < i; j++) {
      printf("* ");
    }
    printf("\n");
  }
}

void tamGiac3(int a) {
  for (int i = 1; i <= a; i++) {
    gotoxy(45+LENGHT_LEFT,i-1+LENGHT_TOP);
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
    gotoxy(60+LENGHT_LEFT,i+LENGHT_TOP);
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

void tamGiacCan(int a){
  for (int i = 1; i <= a; i++) {
    gotoxy(75+LENGHT_LEFT, i-1+LENGHT_TOP);
    for (int j = 1; j <= 2*a-1; j++) {
      if (j<=a+(i-1) && j>=a-(i-1)) {
        printf("* ");
      }else{
        printf("  ");
      }
    }
    printf("\n");
  }
}

void tamGiac1_1(int a) {
  for (int i = 1; i <= a; i++) {
    gotoxy(20+LENGHT_LEFT,i-1+LENGHT_TOP-8);
    for (int j = 0; j < i; j++) {
      if (i>2 && i<a && j!=0 && j!=i-1) {
        printf("  ");
      }else {
        printf("* ");
      }
    }
    printf("\n");
  }
}

void tamGiac2_2(int a) {
  for (int i = a; i > 0; i--) {
    gotoxy(35+LENGHT_LEFT,a-i+LENGHT_TOP-8);
    for (int j = 0; j < i; j++) {
      if (i>2 && i<a && j!=0 && j!=i-1) {
        printf("  ");
      }else {
        printf("* ");
      }
    }
    printf("\n");
  }
}

void tamGiac3_3(int a) {
  for (int i = 1; i <= a; i++) {
    gotoxy(45+LENGHT_LEFT,i-1+LENGHT_TOP-8);
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
