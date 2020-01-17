#include<stdio.h>

int main(){
  int nam;
  printf("Nhap 1 nam: ");
  scanf("%d", &nam);
  if(nam%400==0 || nam%4==0 && nam%100!=0){
    printf("Do la nam nhuan");
  }else{
    printf("Do khong phai la nam nhuan");
  }
  return 0;
}
