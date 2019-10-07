#include<stdio.h>
#include<conio.h>

void main(){
	float diemT, diemL, diemH, tongD, diemTB;
	printf("Nhap diem Ly: ");
	scanf("%f", &diemL);
	printf("Nhap diem Toan: ");
	scanf("%f", &diemT);
	printf("Nhap diem Hoa: ");
	scanf("%f", &diemH);
	tongD = diemT + diemH + diemL;
	diemTB = tongD/3;
	printf("Diem trung binh: %.2f", diemTB);
  
	getch();
}
