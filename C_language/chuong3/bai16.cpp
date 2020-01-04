#include<stdio.h>
#include<conio.h>

void main(){
  int tong=0;
  for(int i=2;i<=20;i+=2){
    tong+=i;
  }
  printf("2+4+6+8+...+20= %d", tong);
  getch();
}
