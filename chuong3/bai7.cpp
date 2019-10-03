#include<stdio.h>
#include<conio.h>

void main(){
  int a, b;
  float x;
  printf("Nhap a, b: ");
  scanf("%d%d", &a, &b);
  x= -(float)b/a;
  printf("Nghiem cua pt bac nhat la: %.2f", x);
  
  getch();
}
