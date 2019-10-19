#include<stdio.h>
#include<conio.h>

void main(){
  int n;
  float kq=0;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    kq+=(float)i/(i+1);
  }
  printf("Ket qua: %.2f", kq);
  getch();
}
