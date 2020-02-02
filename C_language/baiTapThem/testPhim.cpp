#include<stdio.h>
#include<conio.h>

int main(){
  while (1) {
    if (kbhit()) {
      char key = _getch();
      printf("%c %d\n", key, key);
    }
  }


  return 0;
}
