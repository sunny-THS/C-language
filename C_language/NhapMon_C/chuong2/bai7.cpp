#include<stdio.h>
#include<conio.h>

void main() {
	int cd, cr, dt, cv;
	printf("Nhap chieu dai: ");
	scanf("%d", &cd);
	printf("Nhap chieu rong: ");
	scanf("%d", &cr);
	dt= cd*cr;
	cv= (cd+cr)*2;
	printf("Dien tich: %d\nChu vi: %d",dt,cv);

	getch();
}