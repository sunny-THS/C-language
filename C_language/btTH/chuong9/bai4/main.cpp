#include<stdio.h>
#include<conio.h>
struct NV{
  char ms[5];
  char hoTen[50];
  int namSinh;
};
void xuatTT(NV *a);
void main() {
  struct NV a[10];
  xuatTT(a);
  getch();
}
