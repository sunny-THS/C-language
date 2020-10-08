#include<stdio.h>
#include<conio.h>
typedef struct NhanVien{
  char msnv[10];
  char tenNv[50];
  int soNgayCong;
  float luong1Ngay;
  char chucVu[50];
}NV;
void nhapTT_NV(NV &a);
float tinhTienThuc(NV a);

void main() {
  NV a;
  nhapTT_NV(a);
  printf("Tien luong: %.0f\n", tinhTienThuc(a));
  getch();
}
