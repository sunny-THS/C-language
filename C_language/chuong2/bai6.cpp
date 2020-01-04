#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
	int x;
	float f, g;
	printf("Nhap x: ");
	scanf("%d", &x);
	float tuF= 3*pow(x,2.0) + 4*x + 5;
	float mauF= 2*x + 1;
	float tuG= 3*pow(x,5.0) + 2*x + sqrt(x + 1.0);
	float mauG= 5*pow(x,2.0) - 3;
	f= tuF/mauF;
	g= tuG/mauG;
	printf("F(x)= %.2f\nG(x)= %.2f", f, g);

	getch();
}