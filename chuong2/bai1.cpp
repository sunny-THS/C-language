#include<stdio.h>
#include<conio.h>

void main() {
	float a,b;
	printf("Nhap hai so thuc: ");
	scanf("%f%f",&a,&b);
	float tong = a + b;
	float hieu = a - b;
	float thuong = a / b;
	float tich = a * b;
	printf("%.2f + %.2f = %.2f",a,b,tong);
	printf("\n%.2f - %.2f = %.2f",a,b,hieu);
	printf("\n%.2f * %.2f = %.2f",a,b,tich);
	printf("\n%.2f / %.2f = %.2f",a,b,thuong);

	getch();
}