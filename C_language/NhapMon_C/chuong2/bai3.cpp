#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
	int x,f,g;
	printf("Nhap x: ");
	scanf("%d", &x);
	f = 5*pow(x,2.0) + 6*x + 1;
	g = 2*pow(x,4.0) - 5*pow(x,2.0) + 4*x + 1;
	printf("F(x)= %d", f);
	printf("\nG(x)= %d", g);

	getch();
}