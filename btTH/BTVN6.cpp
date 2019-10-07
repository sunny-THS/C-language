#include<stdio.h>
#include<conio.h>

void main(){
	char asT;
	int asN;
	printf("Nhap 1 ki tu: ");
	scanf("%c", &asT);
	asN = asT;
	if((asN>=65&&asN<=90)||(asN>=97&&asN<=122)){
	printf("Thuoc trong 26 chu cai tieng anh");
	}else{
		printf("Ki tu khac");
	}
	getch();
}
