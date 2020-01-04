#include<stdio.h>
#include<conio.h>

void main(){
  int diemT, diemL, diemH, diemV, diemA, diemS, tongD=0;
  char *xh;
  float diemTb, diemThapNhat;
  printf("Nhap diem toan: ");
  scanf("%d", &diemT);
  printf("Nhap diem ly: ");
  scanf("%d", &diemL);
  printf("Nhap diem hoa: ");
  scanf("%d", &diemH);
  printf("Nhap diem van: ");
  scanf("%d", &diemV);
  printf("Nhap diem anh: ");
  scanf("%d", &diemA);
  printf("Nhap diem su: ");
  scanf("%d", &diemS);
  float a[] = {diemT, diemL, diemH, diemV, diemA, diemS};//gan mang
  diemThapNhat = a[0];
  int soMon = sizeof(a)/sizeof(float);

  for (int i = 0; i < soMon; i++) {
    tongD+=a[i];
    if(diemThapNhat>a[i]){
      diemThapNhat = a[i];
    }
  }

  diemTb = (float)tongD/soMon;

  if (diemTb>=8 && diemThapNhat>6.5) {
    xh = "Gioi";
  }else if (diemTb>=7 && diemThapNhat>5) {
    xh = "Kha";
  }else if (diemTb>=5 && diemThapNhat>3.5) {
    xh = "Trung Binh";
  }else{
    xh = "Yeu";
  }
  
  printf("Diem trung binh mon: %.2f\tXep loai: %s", diemTb, xh);
  getch();
}
