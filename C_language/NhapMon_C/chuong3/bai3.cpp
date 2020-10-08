#include<stdio.h>
#include<conio.h>

void main() {
  int a;
  printf("Nhap mot so nguyen: ");
  scanf("%d", &a);
  if(a%2==0){
    printf("Do la so chan");
  }else{
    printf("Do la so le");
  }
  
  getch();
}
