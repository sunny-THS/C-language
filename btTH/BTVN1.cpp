#include<stdio.h>
#include<conio.h>

void main(){
  int phanNguyen, phanThuc, tong;
  float a;
  printf("Nhap moi nhap 1 so thuc: ");
  scanf("%f", &a);
  phanNguyen = (int)a;
  phanThuc = (a - phanNguyen)*100;
  tong = phanNguyen + phanThuc;
  printf("Phan nguyen: %d\n", phanNguyen);
  printf("So thuc voi 2 so thap phan: %.2f\n", a);
  printf("2 so thap phan cua so thuc: %d\n", phanThuc);
  printf("Tong: %d", tong);
  
  getch();
}
