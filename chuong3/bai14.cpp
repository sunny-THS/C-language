#include<stdio.h>
#include<conio.h>

void main(){
  int tong = 0;
  for(int i=1;i>=20;i++){
    tong+=i;
  }
  printf("1 + 2 + 3 + ... + 20 = %d", tong);
  getch();
}
