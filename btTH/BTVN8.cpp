#include<stdio.h>
#include<conio.h>

void main(){
  int a, b, max, min;
	printf("Nhap 2 so: ");
	scanf("%d%d", &a, &b);
	max = a>b?a:b;
	min = a<b?a:b;
	printf("So lon nhat: %d\nSo nho nhat: %d", max, min);
  
  getch();
}
