#include<stdio.h>
#include<conio.h>

void main(){
	char asT; //text
	int asN;  //number
	printf("Nhap 1 ki tu: ");
	scanf("%c", &asT);
	asN = asT;
	if((asN>=65&&asN<=90)||(asN>=97&&asN<=122)){
	if(asN>=65&&asN<=90){
		printf("Ki tu in hoa");
	}else{
		printf("Ki tu thuong");
	}
	}else{
		printf("Ki tu khac");
	}
	getch();
}
