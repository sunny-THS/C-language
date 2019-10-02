#include<stdio.h>
#include<conio.h>

void main() {
  int a;
  printf("Nhap so nguyen: ");
  scanf("%d", &a);
  if(a>0){
    printf("Do la so nguyen duong");
  }else{
    printf("Do la so nguyen am");
  }
  
  getch();
}
