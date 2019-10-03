#include<stdio.h>
#include<conio.h>

void main(){
  int kq = 1;
  int n;
  printf("Nhap so n(n>0): ");
  scanf("%d", &n);
  for(int i=1;i>=n;i++){
    kq*=i;
  }
  printf("1*2*3*...*%d = %d", n, kq);
  getch();
}
