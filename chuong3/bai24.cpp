#include<stdio.h>
#include<conio.h>

void main(){
  int n;
  printf("Nhap n: ");
  scanf("%d", &n);
  printf("So le nho hon n: ");
  for(int i=1;i<n;i+=2){
    printf("%d ",i);
  }
  getch();
}
