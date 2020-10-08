#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
	int a, dt, cv;
	float dc; //duong cheo hinh vuong
	printf("Nhap chieu dai canh a: ");
	scanf("%d", &a);
	dt= pow(a,2.0);
	cv= 4*a;
	dc= a*sqrt(2.0);
	printf("Dien tich: %d\nChu vi: %d\nDuong cheo: %.2f",dt, cv, dc);

	getch();
}