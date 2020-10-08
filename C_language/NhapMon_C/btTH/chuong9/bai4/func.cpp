#include<stdio.h>
#include<string.h>
#define YEAR_NOW 2019
struct NV{
  char ms[5];
  char hoTen[50];
  int namSinh;
};
void swap(char &a, char &b){
  char t = a;
  a = b;
  b = t;
}
void xoaKhongChan(char *text, int n){
  int b=0;
  for (int i = 0; i < n; i++) {
    //32 la khoang chan
    if (text[i]!=32  || text[i]==32&&text[i+1]!=32&&text[0]!=32) {
      swap(text[b++],text[i]);
    }
  }
}
void layDLFile(NV *a, int &b){
  FILE* f;
  f= fopen("input.txt","rt");
  int d=0;
  fscanf(f,"%d", &b);
  char c;
  fscanf(f, "%c", &c);
  for (int i = 0; i < b; i++) {
    fscanf(f, "%c", &c);
    while (c!='-') {
      a[i].ms[d++] = c;
      fscanf(f, "%c", &c);
    }//lay ma so
    a[i].ms[d] = '\0';
    xoaKhongChan(a[i].ms,d);
    d=0;
    fscanf(f, "%c", &c);
    while (c!='-') {
      a[i].hoTen[d++] = c;
      fscanf(f, "%c", &c);
    }//lay ho va ten
    a[i].hoTen[d] = '\0';
    xoaKhongChan(a[i].hoTen,d);
    d=0;
    fscanf(f, "%d", &a[i].namSinh);
    fscanf(f, "%c", &c);
  }
  fclose(f);
}
int tinhTuoi(NV *a, int i){
  return YEAR_NOW - a[i].namSinh;
}

void xuatTT(NV *a){
  int n;
  layDLFile(a,n);
  printf("MS\tHo ten\t\tnam sinh\tTuoi\n");
  for (int i = 0; i < n; i++) {
    printf("%s\t%s\t%d\t\t%d\n", a[i].ms,a[i].hoTen,a[i].namSinh, tinhTuoi(a,i));
  }
}
