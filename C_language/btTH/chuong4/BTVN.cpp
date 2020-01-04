#include<stdio.h>
#include<conio.h>

void main(){
  int chon, soBai=14, j=1;
  do {
    printf("\tBai tap ve nha\n");
    for (int i = 1; i <= soBai+1; i++) {
      if (i<7) {
        continue;
      }else if (i==(soBai+1)) {
        printf("\t%d. Thoat chuong trinh", j-j);
      }else{
        printf("\t%d. Bai %d\n", j++, i);
      }
    }
    printf("\nChon: ");
    scanf("%d", &chon);
    switch (chon) {
      case 1: {
        int num, bl=0, dem=0;
        printf("\nNhap 1 so nguyen duong: ");
        scanf("%d", &num);
        while (num!=0) {
          int a = num%10;
          if (a%2==0) {
            bl++;
          }
          num/=10;
          dem++;
        }
        if (dem==bl) {
          printf("So nguyen duong n co cac chu so toan la chu so chan\n");
        }else{
          printf("So nguyen duong n khong co cac chu so toan la chu so chan\n");
        }
        break;
      }
      case 2: {
        int num, bl=0, dem=0;
        printf("\nNhap 1 so nguyen duong: ");
        scanf("%d", &num);
        while (num!=0) {
          int a = num%10;
          if (a%2!=0) {
            bl++;
          }
          num/=10;
          dem++;
        }
        if (dem==bl) {
          printf("So nguyen duong n co cac chu so toan la chu so le\n");
        }else{
          printf("So nguyen duong n khong co cac chu so toan la chu so le\n");
        }
        break;
      }
      case 3: {
        int num, a, b;
        printf("\nNhap 1 so nguyen duong: ");
        scanf("%d", &num);
        a = num%10;
        while (num!=0) {
          b = num/10%10;
          if (a>=b) {
            a=b;
          }else break;
          num/=10;
        }
        if (a==b) {
          printf("So nguyen duong n co cac chu so tang dan\n");
        }else{
          printf("So nguyen duong n khong co cac chu so chu so tang dan\n");
        }
        break;
      }
      case 4: {
        int num, a, b;
        printf("\nNhap 1 so nguyen duong: ");
        scanf("%d", &num);
        a = num%10;
        while (num!=0) {
          b = num/10%10;
          if (a<=b) {
            a=b;
          }else break;
          num/=10;
        }
        if (a==num) {
          printf("So nguyen duong n co cac chu so giam dan\n");
        }else{
          printf("So nguyen duong n khong co cac chu so chu so giam dan\n");
        }
        break;
      }
      case 5: {
        int n, m=0, btm, tong=0;
        printf("\nNhap 1 so nguyen duong n: ");
        scanf("%d", &n);
        while (tong<n) {
          tong+=++m;
          if (tong<n) {
            btm=m;
          }
        }
        printf("So nguyen duong m lon nhat sao cho 1+2+3+...+ m < n: %d\n", btm);
        break;
      }
      case 6: {
        int n, m=0, tong=0;
        printf("\nNhap 1 so nguyen duong n: ");
        scanf("%d", &n);
        while (tong<=n) {
          tong+=m++;
        }
        printf("So nguyen duong m lon nhat sao cho 1+2+3+...+ m > n: %d\n", m);
        break;
      }
      case 7: {
        int n;
        printf("\nNhap 1 so nguyen duong n: ");
        scanf("%d", &n);
        printf("So dao: ");
        if (n%10==0) {
          n/=10;
        }
        while (n!=0) {
          printf("%d", n%10);
          n/=10;
        }
        break;
      }
      case 8: {
        const int STDM = 1000;// so tien dat muc
        const float MLS = 0.7;

        int m, tongTien=0, soThang=0;
        float laiSuat = 1 + MLS;
        printf("So tien An gui(menh gia $): ");
        scanf("%d", &m);
        while (tongTien<=STDM) {
          tongTien += m*laiSuat;
          laiSuat*=laiSuat;
          soThang++;
        }
        printf("So thang can gui: %d\n", soThang);
        break;
      }
      case 0: {
        printf("Nhan phim bat ki de thoat\n");
      }
    }
    j=1;
    printf("\n===========================================================\n");
  } while(chon!=0);

  getch();
}
