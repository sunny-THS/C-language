#include<stdio.h>
#include<conio.h>

void main(){
	char tenSanPham[25];
	int soLuong;
	long donGia, tien;
	float thueGTGT;
	printf("Nhap ten san pham: ");
	scanf("%s", tenSanPham);
	printf("So luong: ");
	scanf("%d", &soLuong);
	printf("Don gia: ");
	scanf("%ld", &donGia);
	tien= donGia*soLuong;
	thueGTGT= tien*0.1;
	printf("\nTien: %ld\n", tien);
	printf("Thue gia tri gia tang: %.2f", thueGTGT);
  
	getch();
}
