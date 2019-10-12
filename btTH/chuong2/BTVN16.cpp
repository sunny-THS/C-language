#include<stdio.h>
#include<conio.h>

void main(){
  int a, b, c;
  printf("Nhap vao ba canh cua tam giac: ");
  scanf("%d%d%d", &a, &b, &c);
  if (a<b+c && b<a+c && c<a+b) {
    if (a==b || b==c || a==c) {
      if (a==b&&b==c) {
        printf("Day la tam giac deu\n");
      }else if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a) {
        printf("Day la tam giac vuong can\n");
      }else{
        printf("Day la tam giac can\n");
      }
    }else if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a) {
      printf("Day la tam giac vuong\n");
    }else if (a*a>b*b+c*c || b*b>a*a+c*c || c*c>a*a+b*b) {
      printf("Day la tam giac tu\n");
    }else {
      printf("Day la tam giac thuong\n");
    }
  }else printf("Khong phai 3 canh tam giac\n");
  getch();
}
