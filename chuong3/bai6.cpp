#include<stdio.h>
#include<conio.h>

void main(){
  int donGia, soLuong, thanhTien;
  float giamGia=0, tongTien;
  printf("Nhap don gia va so luong: ");
  scanf("%d%d", &donGia, &soLuong);
  thanhTien= donGia * soLuong;
  if(thanhTien>100){
    giamGia= thanhTien * 0.03;
  }
  tongTien= thanhTien - giamGia;
  printf("Tong tien: %.2f", tongTien);
  
  getch();
}
