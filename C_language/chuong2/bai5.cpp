#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
	int a,b,c;
	float delta,f,g;
	printf("Nhap a, b, c: ");
	scanf("%d%d%d",&a,&b,&c);
	delta = pow(b,2.0) - 4*a*c;
	float tuF = -b+sqrt(delta);
	float tuG = -b-sqrt(delta);
	float mau = 2*a;
	f = tuF/mau;
	g = tuG/mau;
	printf("F(x)= %.2f\nG(x)= %.1f", f, g);

	getch();
}