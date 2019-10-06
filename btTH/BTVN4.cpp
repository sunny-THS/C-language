#include<stdio.h>
#include<conio.h>
#inlcude<math.h>

void main(){
  int cd, cr, dt, cv;
  float dc;
  printf("Nhap 2 canh hinh chu nhat: ");
  scanf("%d%d", &cd, &cr);
  dt = cd*cr;
  cv = (cd+cr)*2;
  dc = sqrt(pow(cd,2.0)+pow(cr,2.0));
  printf("Dien tich: %d\nChu vi: %d\nDuong cheo: %.2f", dt, cv, dc);
  
  getch();
}
