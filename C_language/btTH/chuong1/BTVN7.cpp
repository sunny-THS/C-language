  
#include<stdio.h>
#include<conio.h>

void main(){
	  int a, b;
	  float x;
	  printf("Nhap a, b: ");
	  scanf("%d%d", &a, &b);
	  if(a!=0){
		x= -(float)b/a;
		printf("Nghiem cua pt bac nhat la: %.2f", x);
	  }else{
		printf("Phuong trinh vo nghiem");
	  }
  
	  getch();
}
