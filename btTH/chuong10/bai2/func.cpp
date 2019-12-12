#include<stdio.h>
#include<string.h>
#include<math.h>
#define TIENTHUONG 50
#define GD "Giam doc"
#define PGD "Pho giam doc"
#define TP "Truong phong"
#define PP "Pho phong"

typedef struct NhanVien{
  char msnv[10];
  char tenNv[50];
  int soNgayCong;
  float luong1Ngay;
  char chucVu[50];
}NV;
void nhapTT_NV(NV &a);
float tinhTienLuong(NV a);
int tinhTienThuong(NV a);
int tinhTienPhuCap(NV a);
char* xoaKhoangChan(char*a);
void swap(char *a, char *b);
char* inHoaKiTuDau(char *a);
int nhapChucVu_True(char*a);
float tinhTienThuc(NV a);

int nhapChucVu_True(char*a){
  char *tempA = inHoaKiTuDau(xoaKhoangChan(a));
  if (strcmp(tempA, GD)==0||strcmp(tempA, PGD)==0||strcmp(tempA, TP)==0||strcmp(tempA, PP)==0) {
    return 1;
  }
  return 0;
}
void nhapTT_NV(NV &a){
  printf("msnv: ");
  gets(a.msnv);
  printf("Ho va ten: ");
  gets(a.tenNv);
  do {
    printf("So ngay cong: ");
    scanf("%d", &a.soNgayCong);
    if (a.soNgayCong<1) {
      printf("\nMoi ban nhap lai\n");
    }
  } while(a.soNgayCong<1);
  printf("Luong 1 ngay: ");
  scanf("%f", &a.luong1Ngay);
  do {
    printf("Chuc vu: ");
    gets(a.chucVu);
    if (!nhapChucVu_True(a.chucVu)) {
      printf("\nChuc vu khong dung. Moi nhap lai\n");
    }
  } while(!nhapChucVu_True(a.chucVu));
}
float tinhTienLuong(NV a){
  return a.soNgayCong*a.luong1Ngay;
}
int tinhTienThuong(NV a){
  const int NgayThuong=24;
  if (a.soNgayCong>NgayThuong) {
    return TIENTHUONG;
  }
  return 0;
}
int tinhTienPhuCap(NV a){
  const int _GD=100, P_GD=80, T_P=40, P_P=20;

  if (strcmp(a.chucVu, GD)==0) {
    return 100;
  }else if (strcmp(a.chucVu, PGD)==0) {
    return 80;
  }else if (strcmp(a.chucVu, TP)==0) {
    return 40;
  }else{
    return 20;
  }
}
void swap(char &a, char &b){
  char t = a;
  a = b;
  b = t;
}
char* xoaKhoangChan(char*a){
  int d=0;
  int len = strlen(a);
  for (int i = 0; i < len; i++) {
    if (a[i]!=32||a[i]==32&&a[i+1]!=32&&a[0]!=32) {
      swap(a[d++],a[i]);
    }
  }
  a[d]='\0';
  return a;
}
char* inHoaKiTuDau(char *a){
  int len = strlen(a);
  //trong ascii a -> 97  A -> 65
  if (a[0]>97) {
    a[0]-=32;
  }
  for (int i = 1; i < len; i++) {
    if (a[i]==32) {
      continue;
    }else if(a[i]>=65||a[i]<=90){
      a[i]+=32;
    }
  }
  return a;
}
float tinhTienThuc(NV a){
  float luong= tinhTienLuong(a)+tinhTienThuong(a)+tinhTienPhuCap(a);
  return luong;
}
