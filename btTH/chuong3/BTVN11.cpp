#include<stdio.h>
#include<conio.h>

void main(){
  int n, x;
  int kq=0;
  printf("Nhap x: ");
  scanf("%d", &x);
  printf("Nhap n: ");
  scanf("%d", &n);
  int a=x;
  
  for(int i=1; i<=n; i++){
   kq+=(-x);
   x*=(-a);
  }
  printf("Ket qua -x+x^2+...+(-1)^(n)*x^(n): %d", kq);
}
