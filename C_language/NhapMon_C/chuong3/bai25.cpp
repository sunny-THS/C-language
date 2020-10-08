#include<stdio.h>
#include<conio.h>

void main() {
  int sum=0,n;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(int i=0;i<n;i+=2){
    sum+=i;
  }
  printf("Tong so chan nho hon n: %d", sum);
  
  getch();
}
