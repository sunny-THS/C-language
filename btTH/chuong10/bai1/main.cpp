#include<stdio.h>
#include<conio.h>
typedef struct PhanSo{
  int tu;
  int mau;
}PS;
void nhapPS(PS &a);
void xuatPS(PS a);
void ssVoi1(PS a);
void nhapN_PS(PS *a, int &n);
void xuatN_PS(PS *a, int b);
void toiGian(PS &a);
PS tinhTongPS(PS *a, int n);
PS tinhHieuPS(PS *a, int n);
PS tinhTichPS(PS *a, int n);
PS tinhThuongPS(PS *a, int n);

void main() {
  PS a[50];
  int n;
  nhapN_PS(a, n);
  printf("\nPhep cong\n");
  xuatPS(tinhTongPS(a,n));
  printf("\nphep tru\n");
  xuatPS(tinhHieuPS(a,n));
  printf("\nPhep nhan\n");
  xuatPS(tinhTichPS(a,n));
  printf("\nPhep chia\n");
  xuatPS(tinhThuongPS(a,n));
  getch();
}
