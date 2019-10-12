#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
  int a, b, c;
  float x1, x2, delta;
  printf("Giai phuong trinh bac hai\n\n");
  printf("Nhap a, b, c: ");
  scanf("%d%d%d", &a, &b, &c);
  delta = pow(b,2.0) - 4*a*c;
  if (a!=0) {
    if(delta!=0){
      if(delta>0){
        x1= (-b+sqrt(delta))/(2*a);
        x2= (-b-sqrt(delta))/(2*a);
        printf("Pt co 2 nghiem:\nx= %.2f\nx= %.2f", x1, x2);
      }else{
        printf("Pt trinh vo nghiem");
      }
    }else{
      x1= -(float)b/(2*a);
      printf("Pt co 1 nghiem duy nhat: %.2f", x1);
    }
  }else{
    printf("Pt trinh vo nghiem");
  }

	getch();
}
