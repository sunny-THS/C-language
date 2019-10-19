#include<stdio.h>
#include<conio.h>

void main(){
  int n;
  float kq=0;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(int i=0; i<=n; i++){
    kq+=(float)1/(2*i+1);
  }
  printf("Ket qua: %.2f", kq);
  getch();
}
