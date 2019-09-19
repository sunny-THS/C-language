#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
	int bk; //ban kinh hinh tron, gia su ban kinh la so nguyen
	float dt, cv;
	const float PI = 3.14;
	printf("Nhap ban kinh: ");
	scanf("%d", &bk);
	cv= 2*PI*bk;
	dt= PI*pow(bk,2.0);
	printf("Dien tich: %.2f\nChu vi: %.2f", dt, cv);

	getch();
}