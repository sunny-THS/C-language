#include<stdio.h>
#include<conio.h>

void main() {
	int a, b, c, max, min;
	printf("Nhap a b c : ");
	scanf("%d%d%d", &a,&b,&c);
	max= a>b? (a>c?a:c) : (b>c?b:c);
	min= a<b? (a<c?a:c) : (b<c?b:c);
	printf("Max: %d\nMin: %d", max, min);

	getch();
} 
