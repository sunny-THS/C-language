#include<stdio.h>
#include<conio.h>

void main() {
	int i, bthuc;
  printf("Gia tri cua i la ");
  scanf("%d", &i);
  bthuc = 20 + ++i + i++;
  printf("Bieu thuc 20 + ++i + i++ co ket qua la: %d; i = %d", bthuc, i);

	getch();
} 
