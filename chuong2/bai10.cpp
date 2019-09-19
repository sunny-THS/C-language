#include<stdio.h>
#include<conio.h>

void main() {
	int a, b, max;
	printf("Nhap 2 so: ");
	scanf("%d%d", &a, &b);
	max = a>b?a:b;
	printf("So lon nhat: %d", max);

	getch();
}