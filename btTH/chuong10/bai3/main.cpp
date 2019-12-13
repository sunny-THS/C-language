#include<stdio.h>
#include<conio.h>
typedef struct SinhVien{
  char mssv[11];
  char tenSv[50];
  float diemT;
  float diemL;
  float diemH;
}SV;
void nhapTT_SV(SV &a);
void xuatTT_SV(SV a);
float tinhDTB(SV a);
void xepLoai(SV a);

void main() {
  SV a;
  nhapTT_SV(a);
  xuatTT_SV(a);
  printf("\n diem trung binh: %f\n",tinhDTB(a));
  xepLoai(a);
  getch();
}
