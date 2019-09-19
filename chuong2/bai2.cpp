#include<stdio.h>
#include<conio.h>

void main() {
	int doF; //Gia su do F la so nguyen
	float doC;
	printf("Nhap do F: ");
	scanf("%d",&doF);
	doC = (float)5/9*(doF-32);
	printf("Do C: %.2f", doC);

	getch();
}