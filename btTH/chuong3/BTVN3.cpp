#include<stdio.h>
#include<conio.h>

void main(){
  int n,t=1,tong=0;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    tong+=t*i;
    t*=-1;
  }
  printf("%d", tong);
  getch();
}
