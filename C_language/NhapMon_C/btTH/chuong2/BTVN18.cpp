#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
  char diemC;
  int soMon = 0;
  int diemHeB;
  float a,b,c,d,e,f,p,o,i,u,y,t,tong,tb;
  printf("Nhap diem trung binh va tin chi cua mon hoc thu %d: ", ++soMon);
  scanf("%f", &a, &p);
  printf("Nhap diem trung binh va tin chi cua mon hoc thu %d: ", ++soMon);
  scanf("%f", &b, &o);
  printf("Nhap diem trung binh va tin chi cua mon hoc thu %d: ", ++soMon);
  scanf("%f", &c, &i);
  printf("Nhap diem trung binh va tin chi cua mon hoc thu %d: ", ++soMon);
  scanf("%f", &d, &u);
  printf("Nhap diem trung binh va tin chi cua mon hoc thu %d: ", ++soMon);
  scanf("%f", &e, &y);
  printf("Nhap diem trung binh va tin chi cua mon hoc thu %d: ", ++soMon);
  scanf("%f", &f, &t);
  tong = a+b+c+d+e+f;
  tb = (float)tong/soMon;
  
  if (tb>=8.5) {
    diemHeB = 4;
    diemC = 'A';
  }else if (tb>=7) {
    diemHeB = 3;
    diemC = 'B';
  }else if (tb>=5.5) {
    diemHeB = 2;
    diemC = 'C';
  }else if (tb>=4) {
    diemHeB = 1;
    diemC = 'D';
  }else {
    diemHeB = 0;
    diemC = 'F';
  }
  printf("\nDiem trung binh chung(he 10): %.2f\nDiem trung binh chung(he 4): %d\nDiem chu: %c", tb, diemHeB, diemC);
	getch();
}
