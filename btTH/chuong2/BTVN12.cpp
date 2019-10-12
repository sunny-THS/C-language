#include<stdio.h>
#include<conio.h>

void main(){
  int a, b, c, max, min;
  printf("Nhap a, b, c: ");
  scanf("%d%d%d", &a, &b, &c);
  max = a;
  min = a;
  if (max < b) {
    max =b;
  }
  if (max < c) {
    max =c;
  }
  if (min > b) {
    min =b;
  }
  if (min > c) {
    min =c;
  }
  printf("Max: %d\nMin: %d", max, min);
	getch();
}
