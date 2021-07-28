// STT: 29
// MSSV: 2001190791
// Ho va Ten: Tu Hue Son
// Noi Dung: Bai tap ve nha buoi 2
// ----------------------------------------
// khai bao thu vien
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//khai bao prototype
int menu();
void chucNang(int);
int iRandom(int min, int max);
float fRandom(float min, float max);
void nhapMang1Chieu_iRandom(int * arr, int &n);
void nhapMang1Chieu_fRandom(float * arr, int &n);
void iXuatMang(int * arr, int n);
void fXuatMang(float * arr, int n);
void lietKeGtriChan(int * arr, int n);
void lietKeVtri_gtriAm(int * arr, int n);
int timGiaTri_max(int * arr, int n);
float timGiaTri_duongFirst(float * arr, int n);
// ham main
int main() {
  srand(time(0));
  while (1) {
    int iSelect = menu();
    printf("\n==============================================================\n");
    chucNang(iSelect);
    printf("\n==============================================================\n");
    printf("\n\n");
    getch();
  }
  return 1;
}
int menu() {
  int iChonCau = -1;
  printf("================= Bai tap ve nha =========================");
  printf("\n== \t\t\tMang 1 chieu\t\t\t==");
  printf("\n== Bai 1.1: liet ke cac gia tri chan \t\t\t==");
  printf("\n== Bai 1.2: liet ke vi tri co gia tri am \t\t==");
  printf("\n== Bai 1.3: tim gia tri lon nhat \t\t\t==");
  printf("\n== Bai 1.4: tim gia tri duong dau tien (so thuc)\t==");
  printf("\n== Bai 1.5: tim so chan cuoi cung \t\t\t==");
  printf("\n== Bai 1.6: tim vi tri gia tri nho nhat dau tien \t==");
  printf("\n== Bai 1.7: tim vi tri cua gia tri chan dau tien \t==");
  printf("\n== Bai 1.8: tim vi tri so hoan thien cuoi cung \t\t==");
  printf("\n== Bai 1.9: tim gia tri duong nho nhat (so thuc) \t==");
  printf("\n== Bai 1.10: tim SNT dau tien \t\t\t\t==");
  printf("\n==\t\t\t\t\t\t\t==");
  printf("\n== \t\t\tMang 2 chieu\t\t\t==");
  printf("\n== Bai 2.1: tinh tong cac ptu chu so dau la so le \t==");
  printf("\n== Bai 2.2: dem ptu co chu so hang chuc la 5 \t\t==");
  printf("\n== Bai 2.3: liet ke cac so hoan thien \t\t\t==");
  printf("\n== Bai 2.4: tinh tong cac ptu lon hon TTD cua so sau no ==");
  printf("\n== Bai 2.5: tinh tong gia tri tren 1 dong ma tran \t==");
  printf("\n== Bai 2.6: kiem tra ma tran toan duong \t\t==");
  printf("\n== Bai 2.7: tinh tong cac gia tri tren bien cua ma tran ==");
  printf("\n== Bai 2.8: dem tan suat xuat hien cua ptu x trong mtran==");
  printf("\n== Bai 2.9: tinh tong gtri duong tren 1 dong ma tran \t==");
  printf("\n== Bai 2.10: kiem tra ma tran toan duong \t\t==");
  printf("\n==\t\t\t\t\t\t\t==");
  printf("\n== \t\t\t0. Thoat\t\t\t==");
  printf("\n==========================================================\n");
  printf("\nChon: ");
  scanf("%d", &iChonCau);
  return iChonCau;
}
void chucNang(int iSelect) {
  int * iArr = new int;
  float * fArr = new float;
  int n;
  switch (iSelect) {
    case 0: exit(0); break;
    case 11: {
      nhapMang1Chieu_iRandom(iArr, n);
      iXuatMang(iArr, n);
      printf("\nKQ: \n");
      lietKeGtriChan(iArr, n);
    } break;
    case 12: {
      nhapMang1Chieu_iRandom(iArr, n);
      iXuatMang(iArr, n);
      printf("\nVi tri co gia tri am: ");
      lietKeVtri_gtriAm(iArr, n);
    } break;
    case 13: {
      nhapMang1Chieu_iRandom(iArr, n);
      iXuatMang(iArr, n);
      printf("\nGia tri lon nhat: %d", timGiaTri_max(iArr, n));
    } break;
    case 14: {
      nhapMang1Chieu_fRandom(fArr, n);
      fXuatMang(fArr, n);
      float kq = timGiaTri_duongFirst(fArr, n);
      if (kq!=-1)
        printf("\nKQ: %.2f", kq);
      else printf("\nKhong tim thay so duong");
    } break;
    case 15: {

    } break;
    case 16: {

    } break;
    case 17: {

    } break;
    case 18: {

    } break;
    case 19: {

    } break;
    case 110: {

    } break;
    case 21: {

    } break;
    case 22: {

    } break;
    case 23: {

    } break;
    case 24: {

    } break;
    case 25: {

    } break;
    case 26: {

    } break;
    case 27: {

    } break;
    case 28: {

    } break;
    case 29: {

    } break;
    case 210: {

    } break;
    default: printf("Khong co bai nay vui long nhap lai\n");
    break;
  }
  delete iArr;
  delete fArr;
}
int iRandom(int min, int max) {
  // ham tra ve 1 so nguyen ngau nhien tu min den max
  return min + rand() % (max + 1 - min);
}
float fRandom(float min, float max) {
  // ham tra ve 1 so thuc ngau nhien tu min den max
  return min + (rand()/(float)RAND_MAX) * (max - min);
}
void nhapMang1Chieu_iRandom(int * arr, int &n) {
  do {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
  } while(n<=0);
  for (size_t i = 0; i < n; i++) {
    arr[i] = iRandom(-100, 100);
  }
}
void nhapMang1Chieu_fRandom(float * arr, int &n) {
  do {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
  } while(n<=0);
  for (size_t i = 0; i < n; i++) {
    arr[i] = fRandom(-100, 100);
  }
}
void iXuatMang(int * arr, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
void fXuatMang(float * arr, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%.2f ", arr[i]);
  }
}
// bai 1.1
void lietKeGtriChan(int * arr, int n) {
  for (size_t i = 0; i < n; i++) {
    if (arr[i]%2==0)
      printf("%d ", arr[i]);
  }
}
// bai 1.2
void lietKeVtri_gtriAm(int * arr, int n) {
  for (size_t i = 0; i < n; i++) {
    if (arr[i]<0)
      printf("%d ", i);
  }
}
// bai 1.3
int timGiaTri_max(int * arr, int n) {
  int flgMax = arr[0];
  for (size_t i = 1; i < n; i++)
    if (flgMax<arr[i])
      flgMax = arr[i];
  return flgMax;
}
// bai 1.4
float timGiaTri_duongFirst(float * arr, int n) {
  for (size_t i = 0; i < n; i++)
    if (arr[i] > 0)
      return arr[i];
  return -1;
}
