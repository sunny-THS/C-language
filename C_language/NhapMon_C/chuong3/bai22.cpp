#include<stdio.h>
#include<conio.h>

void main(){
  int n; 
  printf("Nhap n: ");
  scanf("%d", &n);
  printf("Bang cuu chuong so %d", n);
  for(int i=1;i<=10;i++){
    printf("\n%d*%d=%d", n, i, i*n);
  }
  getch();
}
