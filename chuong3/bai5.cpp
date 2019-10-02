#include<stdio.h>
#include<conio.h>

void main(){
 int a, b;
 printf("Nhap a, b: ");
 scanf("%d%d", a, b);
 if(a%b==0)
  printf("a la boi cua b");
 else
  printf("a khong phai la boi cua b");
 
 getch();
}
