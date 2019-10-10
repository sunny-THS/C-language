#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
  int chon;
  int soBai = 35;

  do {
    //in list bai tap
    printf("\n\t\t\t\t\tDanh sach bai tap chuong 3\n\n");
    for (int i = 1; i <= soBai; i++) {
      printf("%2d. Bai %d\t", i, i);
      if (i%3==0) {
        printf("\n");
      }
    }
    printf("0. Thoat chuong trinh");
    //lua cho bai tap
    printf("\nChon bai: ");
    scanf("%d", &chon);

    //xu ly chon bai
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
        printf("\n");
        break;
      }
      case 2: {
        int a, b, max;
        printf("Tim Max-Min\n\n" );
        printf("Nhap 2 so: ");
        scanf("%d%d", &a, &b);
        if(a>b){
          max = a;
        }else{
          max = b;
        }
        printf("So lon nhat: %d\n", max);
        break;
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
        printf("\n");
        break;
      }
      case 4: {
        int a, b;
        printf("So sanh 2 so a va b \n\n");
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
        printf("\n");
        break;
      }
      case 5: {
        int a, b;
        printf("Xac dinh boi so\n\n");
        printf("Nhap a, b: ");
        scanf("%d%d", &a, &b);
        if(a%b==0){
          printf("a la boi cua b");
        }
        else{
          printf("a khong phai la boi cua b");
        }
        printf("\n");
        break;
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
        printf("\n");
        break;
      }
      case 7: {
        int a, b;
        float x;
        printf("Giai phuong trinh bac nhat\n\n");
        printf("Nhap a, b: ");
        scanf("%d%d", &a, &b);
        if(a!=0){
          x = -(float)b/a;
          printf("Nghiem cua pt bac nhat la: %.2f", x);
        }else{
          printf("Phuong trinh vo nghiem");
        }
        printf("\n");
        break;
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
        printf("\n");
        break;
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
        printf("\n");
        break;
      }
      case 10: {
        int nam;
        printf("Kiem tra nam nhuan hay khong\n\n");
        printf("Nhap 1 nam: ");
        scanf("%d", &nam);
        if(nam%400==0 || nam%4==0 && nam%100!=0){
          printf("Do la nam nhuan");
        }else{
          printf("Do khong phai la nam nhuan");
        }
        printf("\n");
        break;
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
        printf("\n");
        break;
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
        printf("\n");
        break;
      }
      case 13: {
        printf("In tu 1 den 100\n\n");
        for(int i=1;i<=100;i++){
          printf("%2d",i);
        }
        printf("\n");
        break;
      }
      case 14: {
        int tong = 0;
        for(int i=1;i<=20;i++){
          tong+=i;
        }
        printf("1 + 2 + 3 + ... + 20 = %d", tong);
        printf("\n");
        break;
      }
      case 15: {
        int kq = 1;
        int n;
        printf("Nhap so n(n>0): ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          kq*=i;
        }
        printf("1*2*3*...*%d = %d", n, kq);
        printf("\n");
        break;
      }
      case 16: {
        int tong=0;
        for(int i=2;i<=20;i+=2){
          tong+=i;
        }
        printf("2+4+6+8+...+20= %d", tong);
        printf("\n");
        break;
      }
      case 17: {
        int n, sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          sum+=i*(i+1);
        }
        printf("1*2 + 2*3 + 3*4+...+%d*(%d+1)= %d", n, n, sum);
        printf("\n");
        break;
      }
      case 18: {
        int n,sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          sum+=(float)1/(n*(n+1)*(n+2));
        }
        printf("Tong: %d", sum);
        printf("\n");
        break;
      }
      case 19: {
        int n,sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          sum+=i*i;
        }
        printf("1^2 + 2^2 + 3^2+...+%d^2 %d", n, sum);
        printf("\n");
        break;
      }
      case 20: {
        int n,sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          for(int j=1;j<=i;j++){
            sum+=j;
          }
        }
        printf("1 + 1+2 + 1+2+3+...+ 1+2+..n %d", sum);
        printf("\n");
        break;
      }
      case 21: {
        printf("In bang cuu chuong\n\n");
        for(int j=1;j<=10;j++){
          for(int i=1;i<=9;i++){
            printf("%d*%d=%d\t", i, j, i*j);
          }
          printf("\n");
        }
        printf("\n");
        break;
      }
      case 22: {
        int n;
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("Bang cuu chuong so %d", n);
        for(int i=1;i<=10;i++){
          printf("\n%d*%d=%d", n, i, i*n);
        }
        printf("\n");
        break;
      }
      case 23: {
        int cd, cr;
        printf("Ve hinh chu nhat\n\n");
        printf("Nhap chieu dai va chieu rong: ");
        scanf("%d%d", &cd, &cr);
        for(int i=0;i<cr;i++){
          for(int j=0;j<cd;j++){
            printf("* ");
          }
          printf("\n");
        }
        printf("\n");
        break;
      }
      case 24: {
        int n;
        printf("Tim so le nho hon n\n\n");
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("So le nho hon n: ");
        for(int i=1;i<n;i+=2){
          printf("%d ",i);
        }
        printf("\n");
        break;
      }
      case 25: {
        int sum=0,n;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=0;i<n;i+=2){
          sum+=i;
        }
        printf("Tong so chan nho hon n: %d", sum);
        printf("\n");
        break;
      }
      case 26: {
        int n;
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("Boi so cua 5 nho hon n:");
        for(int i=1; i<n; i++){
          if(i%5==0){
            printf("%d ",i);
          }
        }
        printf("\n");
        break;
      }
      case 27: {
        int a, b, c, d, uc,bc;
        printf("Nhap 2 so nguyen: \n");
        scanf("%d%d", &a, &b);
        if (a==b) {
          uc = a;
        }else{
          c=a; //thay the cho a va b
          d=b;
          while (c!=d) {
            if (c>d) {
              c-=d;
            }else{
              d-=c;
            }
          }
          uc = c;
        }
        bc = (float)(a*b)/uc;
        printf("UCLN(%d,%d)=%2d\nBCNN(%d,%d)=%2d\n", a,b,uc,a,b,bc);
        break;
      }
      case 28: {
        const int gioMoCua = 10;
        const int gioDongCua = 24;
        const int mocGiao = 17;	 // moc phan biet 2 menh  gia tien phai tra
        const int giaTrc17h = 20000;
        const long giaSau17h = 45000;
        int gioVao, phutVao, gioRa, phutRa, gioTrc, phutTrc, gioSau, phutSau, tongH, tongM;
        long tongTien;

        printf("Tinh tien karaoke\n");
        do {
	        printf("=============================\n");
          printf("Gio vao(gom ca gio va phut cach nhau boi dau cach): \n");
          scanf("%d%d", &gioVao, &phutVao);
          printf("Gio ra(gom ca gio va phut cach nhau boi dau cach): \n");
          scanf("%d%d", &gioRa, &phutRa);
        } while(gioVao>24 || gioVao<1 || phutVao>59 || phutVao<1 || gioRa<1 || gioRa>24 || phutRa<0 || phutRa>59); //dieu kien nhap
		//Xu li tinh tien
        if (gioVao<gioMoCua || gioVao>gioDongCua) {
          printf("Quan da dong cua\n");
          break;
        }else{
          if ((gioVao>=gioMoCua && gioRa<=mocGiao) || (gioVao>=mocGiao && gioRa<=gioDongCua)) {
            if (phutRa<phutVao) {
              phutRa+=60;
              gioRa-=1;
            }
            tongH = gioRa-gioVao;
            tongM = phutRa-phutVao;
            if (gioVao>=gioMoCua && gioRa<=mocGiao) {
              tongTien = (tongH + (float)tongM/60)*giaTrc17h;
            }else{
              tongTien = (tongH + (float)tongM/60)*giaSau17h;
            }
          }else{
            //Xu ly thoi gian truoc 17h
            gioTrc = (mocGiao-1) - gioVao;
            phutTrc = 60- phutVao;
            //Xu ly thoi gian sau 17h
            gioSau = gioRa - mocGiao;
            phutSau = phutRa;
            tongTien = (gioTrc+(float)phutTrc/60)*giaTrc17h + (gioSau+(float)phutSau/60)*giaSau17h;
          }
        }
        printf("Tien phai tra: %ld\n", tongTien);
        break;
      }
      case 29: {}
      case 30: {}
      case 31: {}
      case 32: {}
      case 33: {}
      case 34: {}
      case 35: {}
      case 0: printf("Bam nut bat ki de thoat\n"); break;
      default: printf("Khong co du lieu\n"); break;
    }
	printf("==========================================================================================================");
  } while(chon!=0);

  getch();
}
