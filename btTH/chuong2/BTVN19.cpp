#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
  char b[10];
  int a;

  printf("Nhap 1 ki so thap luc nhi phan: ");
  scanf("%s", &b);

  if ((*b>=48 && *b<=57) || (*b>=65 && *b<=70)) {
    if (*b>=48 && *b<=57) {
      printf("Gia tri thap phan tuong ung: %s\n", b);
    }else{
      switch (*b) {
        case 65: a=10;break;
        case 66: a=11;break;
        case 67: a=12;break;
        case 68: a=13;break;
        case 69: a=14;break;
        case 70: a=15;break;
      }
      printf("Gia tri thap phan tuong ung: %d\n", a);
    }
  }else{
    printf("He thap luc phan khong dung ki tu nay");
  }

  getch();
}
