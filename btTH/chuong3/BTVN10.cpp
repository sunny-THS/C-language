#include<stdio.h>
#include<conio.h>

void main(){
  int n, x;
  int kq=0;
  printf("Nhap x: ");
  scanf("%d", &x);
  printf("Nhap n: ");
  scanf("%d", &n);
  
  for(int i=1; i<=n; i++){
   kq+=x;
   x*=x;
  }
  printf("Ket qua x+x^2+...+x^(n): %d", kq);
  getch();
}
