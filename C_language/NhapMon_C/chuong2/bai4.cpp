#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
	int x;
	float f, g;
	printf("Nhap x: ");
	scanf("%d", &x);
	float tuF = 1+x;
	float mauF = 1-x;
	float tuG = 1+5*x-7*pow(x,2.0);
	float mauG = 2+3*pow(x,3.0);
	f = tuF/mauF;
	g = tuG/mauG;
	printf("F(x)= %.2f\nG(x)= %.2f", f, g);

	getch();
}