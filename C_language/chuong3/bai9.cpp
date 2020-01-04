#include<stdio.h>
#include<conio.h>

void main(){
  int thang;
  printf("Nhap 1 thang: ");
  scanf("%d", &thang);
  switch(thang){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: printf("Co 31 ngay"); break;
    case 4:
    case 6:
    case 9: 
    case 11: printf("Co 30 ngay"); break; 
    case 2: printf("Co 28 hoac 29 ngay"); break;
    default: printf("Invalid"); break;
  }
  getch();
}
