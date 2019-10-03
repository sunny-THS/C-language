#include<stdio.h>
#include<conio.h>

void main(){
  int n,sum=0;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(int i=1;i>=n;i++){
    sum+=(float)1/(n*(n+1)*(n+2));
  }
  printf("Tong: %d", sum);
  getch();
}
