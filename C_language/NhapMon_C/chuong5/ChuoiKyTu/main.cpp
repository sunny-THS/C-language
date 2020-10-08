#include<stdio.h>
#include<conio.h>
#include<string.h>
int kiemTraChuoiDoi(char *str);
void xoaPt(char *str, int n, int *len);
void xoaKhoangChanThua(char *str);
void lk_CHAR_inString(char *str);
int demSoTu(char *str);
char *layTenFILE(char *url, char *fName);
int kiemTraHe2(char *str);
int luyThua2(int);
char *chuyenSangHe10(char *str, char *n);
void inTu_lenMax(char *str);
int dem_char_a(char *str, char a);
void inVT_a(char *str, char a);
void main(){
	char a[100], n[100];
	gets(a);
	char v;
	printf("Nhap v: ");
	scanf("%c",&v);
	inVT_a(a,v);
	getch();
}
