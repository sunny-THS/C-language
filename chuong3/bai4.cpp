#include<stdio.h>
#include<conio.h>

void main(){
 int a, b;
 printf("Nhap 2 so: ");
 scanf("%d%d", &a, &b);
 if(a!=b){
  if(a>b){
    printf("%d > %d", a, b);
  }else{
    printf("%d < %d", a, b);
  }
 }else{
  printf("%d = %d", a, b);
 }
 
 getch();
}
