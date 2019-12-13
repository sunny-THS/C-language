#include<stdio.h>
#include<conio.h>
struct Taxi{
  char maSo[5];
  char hoTen[50];
  char diaChiDonKhach[100];
  int soKM;
  int soChoNgoi;
};
void nhapTT(Taxi &a);
void xuatTT(Taxi a);
int kiemTra_DiaDiemDonKhach(Taxi, char *diaChi);
void xuatChoNgoi(Taxi);
int tinhTienXe(Taxi);

void main(){
  Taxi a;
  char diaChi[50];
  nhapTT(a);
  xuatTT(a);
  printf("\nNhap quan/huyen can kiem tra: ");
  fflush(stdin);
  gets(diaChi);
  if(kiemTra_DiaDiemDonKhach(a, diaChi)){
    printf("\nTaxi co chay tren quan/huyen %s\n", diaChi);
  }else printf("\nTaxi khongco chay tren quan/huyen %s\n", diaChi);
  xuatChoNgoi(a);
  printf("Tien xe phai tra: %d\n",tinhTien(a));
  getch();
}
