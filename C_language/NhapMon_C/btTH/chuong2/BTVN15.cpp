#include<stdio.h>
#include<conio.h>

void main(){
	int tienDienThangTrc, tienDienThangSau, mucDienSD, tien;
	printf("Nhap tien dien thang truoc: ");
	scanf("%d", &tienDienThangTrc);
	printf("Nhap tien dien thang sau: ");
	scanf("%d", &tienDienThangSau);
	mucDienSD = tienDienThangSau - tienDienThangTrc;
	if (mucDienSD>300){
		tien = 100*5 + 50*7 + 50*10 + 100/15 + (mucDienSD-300)*20;
	}else if(mucDienSD>=201&&mucDienSD<=300){
		tien = 100*5 + 50*7 + 50*10 + (mucDienSD-200)*15;
	}else if(mucDienSD>=151&&mucDienSD<=200){
		tien = 100*5 + 50*7 + (mucDienSD-150)*10;
	}else if(mucDienSD>=101&&mucDienSD<=150){
		tien = 100*5 + (mucDienSD-100)*7;
	}else if(mucDienSD>=1&&mucDienSD<=100){
		tien = mucDienSD *5;
	}
	printf("tien: %d",tien);
	getch();
}
