#include<stdio.h>
#include<windows.h>

int main(){
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  for (int i = 0; i <= 255; i++) {
    SetConsoleTextAttribute(color, i);
    printf("%d Change color\t", i);
    if (i%3==0) {
      printf("\n");
    }
  }
  return 0;
}
