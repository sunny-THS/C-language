#include<stdio.h>
#include<conio.h>

void main() {
  int chon;
  imt soBai = 35;
  printf("\tDanh sach bai tap chuong 3\n");
  for (int i = 0; i < soBai; i++) {
    printf("%2d. Bai %d\n", i, i);
  }
  scanf("%d", &chon);
  switch (chon) {
    case 1: {
      int a;
      printf("Kiem tra so nguyen duong hay nguyen am\n\n");
      printf("Nhap so nguyen: ");
      scanf("%d", &a);
      if(a>0){
        printf("Do la so nguyen duong");
      }else{
        printf("Do la so nguyen am");
      }
    }
    case 2: {
      int a, b;
      printf("Tim Max-Min\n\n" );
      printf("Nhap 2 so: ");
      scanf("%d%d", &a, &b);
      if(a>b){
        printf("%d > %d", a, b);
      }else{
        printf("%d < %d", a, b);
      }
    }
    case 3: {
      int a;
      printf("Xet tinh chan le\n\n");
      printf("Nhap mot so nguyen: ");
      scanf("%d", &a);
      if(a%2==0){
        printf("Do la so chan");
      }else{
        printf("Do la so le");
      }
    }
    case 4: {
      int a, b;
      printf("So sanh 2 so a va b \n\n", );
      printf("Nhap 2 so: ");
      scanf("%d%d", &a, &b);
      if(a!=b){
        if(a>b){
          printf("%d > %d", a, b);
        }else{
          printf("%d < %d", a, b);
        }
      }else{
        printf("%d = %d", a, b);
      }
    }
    case 5: {
      int a, b;
      printf("Xac dinh boi so\n", );
      printf("Nhap a, b: ");
      scanf("%d%d", &a, &b);
      if(a%b==0){
        printf("a la boi cua b");
      }
      else{
        printf("a khong phai la boi cua b");
      }
    }
    case 6: {
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
    }
    case 7: {
      int a, b;
      float x;
      printf("Giai phuong trinh bac nhat\n\n", );
      printf("Nhap a, b: ");
      scanf("%d%d", &a, &b);
      x= -(float)b/a;
      printf("Nghiem cua pt bac nhat la: %.2f", x);
    }
    case 8: {
      int a, b, c;
      float x1, x2, delta;
      printf("Giai phuong trinh bac hai\n\n");
      printf("Nhap a, b, c: ");
      scanf("%d%d%d", &a, &b, &c);
      delta = pow(b,2.0) - 4*a*c;
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
    }
    case 9: {
      int thang;
      printf("Xac dinh so ngay trong thang\n\n");
      printf("Nhap 1 thang: ");
      scanf("%d", &thang);
      switch(thang){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: printf("Co 31 ngay"); break;
        case 4:
        case 6:
        case 9:
        case 11: printf("Co 30 ngay"); break;
        case 2: printf("Co 28 hoac 29 ngay"); break;
        default: printf("Invalid"); break;
      }
    }
    case 10: {
      int nam
      printf("Kiem tra nam nhuan hay khong\n\n", );
      printf("Nhap 1 nam: ");
      scanf("%d", &nam);
      if(nam%400==0 || nam%4==0 && nam%100!=0){
        printf("Do la nam nhuan");
      }else{
        printf("Do khong phai la nam nhuan");
      }
    }
    case 11: {
      const float PI = 3.14;
      int a, cd, cr, canh, bk;
      float dt, cv;
      printf("1. Hinh chu nhat\n");
      printf("2. Hinh vuong\n");
      printf("3. Hinh tron\n");
      printf("Chon hinh can tinh: ");
      scanf("%d", &a);
      switch(a){
        case 1:{
          printf("Nhap lan luot chieu dai va chieu rong: ");
          scanf("%d%d", &cd, &cr);
          cv= (cd+cr)*2;
          dt= cd*cr;
          printf("Chu vi: %.0f\nDien tich: %.0f", cv, dt);
          break;
        }
        case 2: {
          printf("Nhap canh hinh vuong: ");
          scanf("%d", &canh);
          cv= canh*4;
          dt= canh*canh;
          printf("Chu vi: %.0f\nDien tich: %.0f", cv, dt);
          break;
        }
        case 3: {
          printf("Nhap ban kinh: ");
          scanf("%d", &bk);
          cv= 2*PI*bk;
          dt= PI*bk*bk;
          printf("Chu vi: %.2f\nDien tich: %.2f", cv, dt);
          break;
        }
        default: printf("Invalid"); break;
      }
    }
    case 12: {
      int a, b, n;
      printf("Nhap 2 so nguyen: ");
      scanf("%d%d", &a, &b);
      printf("\n1. Phep cong");
      printf("\n2. Phep tru");
      printf("\n3. Phep nhan");
      printf("\n4. Phep chia");
      scanf("%d", &n);
      switch(n){
        case 1: printf("%d + %d = %d", a, b, a+b); break;
        case 2: printf("%d - %d = %d", a, b, a-b); break;
        case 3: printf("%d * %d = %d", a, b, a*b); break;
        case 4: printf("%d / %d = %.2f", a, b, (float)a/b); break;
      }
    }
    case 13: {
      printf("In tu 1 den 100\n");
      for(int i=1;i<=100;i++){
        printf("%d ",i);
      }
    }
    case 14: {

    }
    case 15: {

    }
    case 16: {

    }
    case 17: {

    }
    case 18: {

    }
    case 19: {

    }
    case 20: {

    }
    case 21: {

    }
    case 22: {

    }
    case 23: {

    }

    case 24: {

    }
    case 25: {

    }

  }

  getch();
}
