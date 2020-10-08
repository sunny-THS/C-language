#include<stdio.h>
#include<conio.h>

void main(){
  char xhC;
  int tong=0, soCotDiem = 4;
  float diem[4], diemTb;

  printf("Nhap diem mon Thuc hanh NMLT\n");
  printf("Nhap cot diem 1: ");
  scanf("%f", &diem[0]);
  printf("Nhap cot diem 2: ");
  scanf("%f", &diem[1]);
  printf("Nhap cot diem 3: ");
  scanf("%f", &diem[2]);
  printf("Nhap cot diem 4: ");
  scanf("%f", &diem[3]);
  for (int i = 0; i < soCotDiem; i++) {
      tong+=diem[i];
  }
  diemTb = (float)tong/soCotDiem;
  if (diemTb>=8.5) {
    xhC = 'A';
  }else if (diemTb>=7) {
    xhC = 'B';
  }
  else if (diemTb>=5.5) {
    xhC = 'C';
  }
  else if (diemTb>=4) {
    xhC = 'D';
  }
  else {
    xhC = 'F';
  }
  printf("\nDiem trung binh: %.2f\t<=>\t%c", diemTb, xhC);

	getch();
}
