#include<stdio.h>
#include<conio.h>
struct NV{
  char ms[5];
  char hoTen[50];
  float heSoLuong;
};
void layDLFile(NV *a, int &b);
void xuatTT(NV *a);
void xoaKhongChan(char *text, int n);
void swap(char &a, char &b);
void main() {
  struct NV a[10];
  xuatTT(a);
  getch();
}
