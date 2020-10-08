#include<stdio.h>
#include<string.h>
#include<math.h>
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
int ucln(int, int);
void quyDongPS(PS &a, int msc);
PS tinhTongPS(PS *a, int n);
PS tinhHieuPS(PS *a, int n);
PS tinhTichPS(PS *a, int n);
PS tinhThuongPS(PS *a, int n);

void quyDongPS(PS &a, int msc){
  if (a.mau<0) {
    a.tu*=-1;
    a.mau*=-1;
  }
  msc/=a.mau;
  a.tu*=msc;
}

PS tinhTongPS(PS *a, int n){
  PS ds, temp[50];
  for (int i = 0; i < n; i++) {
    temp[i].tu=a[i].tu;
    temp[i].mau=a[i].mau;
  }
  ds.tu = 0;
  ds.mau = 1;
  for (int i = 0; i < n; i++) {
    ds.mau*=temp[i].mau;
  }
  for (int i = 0; i < n; i++) {
    quyDongPS(temp[i],ds.mau);
  }
  for (int i = 0; i < n; i++) {
    ds.tu += temp[i].tu;
  }
  toiGian(ds);
  return ds;
}
PS tinhHieuPS(PS *a, int n){
  PS ds, temp[50];
  for (int i = 0; i < n; i++) {
    temp[i].tu=a[i].tu;
    temp[i].mau=a[i].mau;
  }
  ds.mau = 1;
  for (int i = 0; i < n; i++) {
    ds.mau*=abs(temp[i].mau);
  }
  for (int i = 0; i < n; i++) {
    quyDongPS(temp[i],ds.mau);
  }
  ds.tu = temp[0].tu;
  for (int i = 1; i < n; i++) {
    ds.tu -= temp[i].tu;
  }
  toiGian(ds);
  return ds;
}
PS tinhTichPS(PS *a, int n){
  PS ds;
  ds.tu = 1;
  ds.mau = 1;
  for (int i = 0; i < n; i++) {
    ds.tu*=a[i].tu;
    ds.mau*=a[i].mau;
  }
  toiGian(ds);
  return ds;
}
PS tinhThuongPS(PS *a, int n){
  PS ds;
  ds.tu = a[0].tu;
  ds.mau = a[0].mau;
  for (int i = 1; i < n; i++) {
    ds.tu*=a[i].mau;
    ds.mau*=a[i].tu;
  }
  toiGian(ds);
  return ds;
}

int ucln(int a, int b){
  if (a==b) {
    return a;
  }
  if (a<b) {
    return ucln(a,b-a);
  }else {
    return ucln(a-b,b);
  }
}
void toiGian(PS &a) {
  int tempTu=abs(a.tu), tempMau=abs(a.mau), k;
  k=ucln(tempTu, tempMau);
  a.tu/=k;
  a.mau/=k;
}

void xuatN_PS(PS *a, int b) {
  for (int i = 0; i < b; i++) {
    xuatPS(a[i]);
  }
}
void nhapN_PS(PS *a, int &n){
  do {
    printf("Nhap so phan so: ");
    scanf("%d", &n);
  } while(n<=1);
  for (int i = 0; i < n; i++) {
    printf("\nPhan so %d\n", i+1);
    nhapPS(a[i]);
    fflush(stdin);
  }
}

void nhapPS(PS &a){
  printf("Nhap tu: ");
  scanf("%d", &a.tu);
  do {
    printf("Nhap mau: ");
    scanf("%d", &a.mau);
  } while(a.mau==0);
}
void xuatPS(PS a) {
  if (a.mau<0) {
    a.tu*=-1;
    a.mau*=-1;
  }
  if (a.mau==1) {
    printf("%d\n", a.tu);
  }else{
    printf("%d/%d\n", a.tu, a.mau);
  }
}
void ssVoi1(PS a) {
  float num = a.tu/(float)a.mau;
  if (num==1.0) {
    printf("bang voi 1\n");
  }else if (num>1.0) {
    printf("Lon hon 1\n");
  }else {
    printf("Nho hon 1\n");
  }
}
