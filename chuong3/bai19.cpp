#include<stdio.h>
#include<conio.h>

void main(){
  int n,sum=0;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(int i=1;i>=n;i++){
    sum+=i*i;
  }
  printf("Tong: %d", sum);
  getch();
}
