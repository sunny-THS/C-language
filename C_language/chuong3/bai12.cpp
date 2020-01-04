#include<stdio.h>
#include<conio.h>

void main(){
  int a, b, n;
  printf("Nhap 2 so nguyen: ");
  scanf("%d%d", &a, &b);
  printf("\n1. Phep cong");
  printf("\n2. Phep tru");
  printf("\n3. Phep nhan");
  printf("\n4. Phep chia");
  scanf("%d", &n);
  switch(n){
    case 1: printf("%d + %d = %d", a, b, a+b); break;
    case 2: printf("%d - %d = %d", a, b, a-b); break;
    case 3: printf("%d * %d = %d", a, b, a*b); break;
    case 4: printf("%d / %d = %.2f", a, b, (float)a/b); break;
  }
  getch();
}
