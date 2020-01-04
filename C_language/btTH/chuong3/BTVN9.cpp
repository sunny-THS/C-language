#include<stdio.h>
#include<conio.h>

void main(){
  int n, x;
  int kq=1;
  printf("Nhap x: ");
  scanf("%d", &x);
  printf("Nhap n: ");
  scanf("%d", &n);
  
  for(int i=1; i<=n; i++){
   kq*=x;
  }
  printf("Ket qua %d^%d: %d", x, n, kq);
  getch();
}
