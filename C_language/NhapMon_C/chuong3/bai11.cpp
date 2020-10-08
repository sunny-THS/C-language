#include<stdio.h>
#include<conio.h>

void main(){
  const float PI = 3.14;
  int a, cd, cr, canh, bk;
  float dt, cv;
  printf("1. Hinh chu nhat\n");
  printf("2. Hinh vuong\n");
  printf("3. Hinh tron\n");
  printf("Chon hinh can tinh: ");
  scanf("%d", &a);
  switch(a){
    case 1:{
      printf("Nhap lan luot chieu dai va chieu rong: ");
      scanf("%d%d", &cd, &cr);
      cv= (cd+cr)*2;
      dt= cd*cr;
      printf("Chu vi: %.0f\nDien tich: %.0f", cv, dt);
      break;
    }
    case 2: {
      printf("Nhap canh hinh vuong: ");
      scanf("%d", &canh);
      cv= canh*4;
      dt= canh*canh;
      printf("Chu vi: %.0f\nDien tich: %.0f", cv, dt);
      break;
    }
    case 3: {
      printf("Nhap ban kinh: ");
      scanf("%d", &bk);
      cv= 2*PI*bk;
      dt= PI*bk*bk;
      printf("Chu vi: %.2f\nDien tich: %.2f", cv, dt);
      break;
    }
    default: printf("Invalid"); break;
  }
  getch();
}
