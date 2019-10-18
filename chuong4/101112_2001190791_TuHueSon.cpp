#include<stdio.h>
#include<conio.h>
#include<math.h>

//prototype function
void luaChonBT(int);
int uc(int, int); // uoc cua 1 so;
int kiemTraChanLe(int); // chan le
int kiemTraSNT(int); // so nguyen to
int kiemTraSCP(int); // so chinh phuong
int kiemTraSHT(int); // so hoan thien
int tachSo(int); // doc so
int demSo(int); // cac so trong so N (bai 8)
//doc so
void docSoDV(int);
void docSoHangChuc(int);
void docSonHangTram(int);
void docSo5_DV(int);
//===========
int bai_9(int);
void bai_10(int);
void doiG(int);// doi giay sang h:m:s
void tinhPhanSo(int,int,int,int,int,int); // tinh tong va tich 3 phan so (bai12)
int ucln(int,int); // tim uoc chung lon nhat
void tim_SNTCN_n(int, int); //tim m so nguyen to cung nhau voi n
int xacDinhSoGNDM(long, int);// xac dinh so giong nhau doi mot
int bai_16(int);
//main
void main() {
  int chon;
  int soBai = 17;
  do {
    //in list bai tap
    printf("\n\t\t\t\t\tDanh sach bai tap chuong 4\n\n");
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
    luaChonBT(chon);
    printf("\n==========================================================================================================\n");
  } while(chon!=0);
  getch();
}

void luaChonBT(int chon) {
  /*Input: 1 bai trong list bai tap
    Output: none
    description: xu ly chon bai tap
  */
  switch (chon) {
    case 1: {
      int a;
      printf("Kiem tra so nguyen x chan hay le\n\n");
      printf("Nhap so nguyen x: ");
      scanf("%d", &a);
      if (kiemTraChanLe(a)) {
        printf("Day la so chan\n");
      }else {
        printf("Day la so le\n");
      }
      break;
    }
    case 2: {
      int a;
      printf("Kiem tra so nguyen to\n\n");
      printf("Nhap n: ");
      scanf("%d", &a);
      if (kiemTraSNT(a)) {
        printf("Day la so nguyen so\n");
      }else {
        printf("Khong phai la so nguyen to\n");
      }
      break;
    }
    case 3: {
      int a;
      printf("Kiem tra so chinh phuong\n\n");
      printf("Nhap mot so nguyen: ");
      scanf("%d", &a);
      if(kiemTraSCP(a)){
        printf("Do la so chinh phuong\n");
      }else{
        printf("Khong phai la so chinh phuong\n");
      }
      break;
    }
    case 4: {
      int a;
      printf("Kiem tra so hoan thien\n\n");
      printf("Nhap n: ");
      scanf("%d", &a);
      if(kiemTraSHT(a)){
        printf("Day la so hoan thien\n");
      }else{
        printf("Day khong phai la so hoan thien\n");
      }
      break;
    }
    case 5: {
      int a, j= 0, i=2;
      printf("Xuat n so nguyen to dau tien\n\n");
      printf("Nhap n(n>0): ");
      scanf("%d", &a);
      while (j<a) {
        if (kiemTraSNT(i)) {
          printf("%d ", i);
          j++; // dem so lan xuat ra man hinh
        }
        i++; // cac so nguyen tu 2->...
      }
      break;
    }
    case 6: {
      int a, j= 0, i=1;
      printf("Xuat n so chinh phuong dau tien\n\n");
      printf("Nhap n(n>0): ");
      scanf("%d", &a);
      while (j<a) {
        if (kiemTraSCP(i)) {
          printf("%d ", i);
          j++; // dem so lan xuat ra man hinh
        }
        i++; // cac so nguyen tu 2->...
      }
      break;
    }
    case 7: {
      int dem=0,a;
      printf("So uoc cua so nguyen N\n\n");
      printf("Nhap N: ");
      scanf("%d", &a);
      for (int i = 1; i <= a; i++) {
        if (uc(a, i)) {
          dem++;
        }
      }
      printf("So uoc cua so nguyen N: %d\n", dem);
      break;
    }
    case 8: {
      int a;
      printf("Doc so N\n\n");
      do {
        printf("Nhap N: ");
        scanf("%d", &a);
        int dv = tachSo(a);
        int chuc = tachSo(a);
        int tram = tachSo(a);
        //printf("%d %d %d\n", tram, chuc, dv); //xem so tach
        if (tram == 0 && chuc!=0 && dv == 5) {
          docSoHangChuc(chuc);
          docSo5_DV(dv);
        }else if (tram!=0 && chuc!=0 && dv == 5) {
          docSonHangTram(tram);
          docSoHangChuc(chuc);
          docSo5_DV(dv);
        }else if (dv == 0 && chuc == 0) {
          docSonHangTram(tram);
        }else{
          switch (demSo(a)) {
            case 1:{
              docSoDV(dv); break;
            }
            case 2: {
              docSoHangChuc(chuc);
              docSoDV(dv);
              break;
            }
            case 3: {
              docSonHangTram(tram);
              docSoHangChuc(chuc);
              docSoDV(dv);
              break;
            }
          }
        }
      } while(a<0 && a>1000);
      break;
    }
    case 9: {
      int n;
      printf("Nhap so N: ");
      scanf("%d", &n);
      printf("So n lon nhat so cho 1+2+3+...+n<N: %d\n", bai_9(n));
      break;
    }
    case 10: {
      int ngay;
      do {
        printf("Nhap N so ngay: ");
        scanf("%d", &ngay);
        bai_10(ngay);
      } while(ngay<=0);
      break;
    }
    case 11: {
      int sc;
      printf("Nhap so giay: ");
      scanf("%d", &sc);
      doiG(sc);
      break;
    }
    case 12: {
      int a, b, c, d, e, f;
      do {
        printf("Nhap phan so thu nhat: ");
        scanf("%d/%d", &a, &b);
        printf("Nhap phan so thu hai: ");
        scanf("%d/%d", &c, &d);
        printf("Nhap phan so thu ba: ");
        scanf("%d/%d", &e, &f);
      } while(b==0 || d==0 || f==0);
      tinhPhanSo(a, b, c, d, e, f);
      break;
    }
    case 13: {
      int n, m;
      printf("Tim m so nguyen to cung nhau voi so n\n\n");
      printf("Nhap m: ");
      scanf("%d", &m);
      printf("nhap n: ");
      scanf("%d", &n);
      tim_SNTCN_n(n, m);
      break;
    }
    case 14: {
      printf("Cac so co 3 chu so khac nhau doi mot:\n");
      for (int i = 100; i < 1000; i++) {
        if (xacDinhSoGNDM(i, 0)) {
          printf("%d ", i);
        }
      }
      break;
    }
    case 15: {
      const long B = 10000;
      long a=0;
      for(long i = B; i<B*10; i++){
        if (xacDinhSoGNDM(i, 1)) {
          printf("%ld ", i);
          a++;
        }
      }
      printf("\n\n\t%ld so co dung 2 chu so bang nhau\n", a);
      break;
    }
    case 16: {
      for(int i=10;i<1000;i++){
        if (bai_16(i)) {
          printf("%d ", i);
        }
      }
      break;
    }
    case 17: {
      int a, tong=0, max, demC=0, demL=0;
      long n;
      printf("Nhap N: ");
      scanf("%ld", &n);
      int dem= demSo(n);
      max=n%10;
      while(n!=0){
        a = n%10;
        if(a%2==0){
          demC++;
        }else{
          demL++;
        }
        tong+=a;
        if(max<a){
          max = a;
        }
        n/=10;
      }
      printf("\nChu so hang dau tien: %d", a);
      printf("\nTong cac chu so: %d", tong);
      printf("\nChu so lon nhat: %d", max);
      printf("\nSo chu so cua N: %d", dem);
      if(xacDinhSoGNDM(n, 0)){
        printf("\nN la so co cac chu so khac nhau doi mot");
      }else{
        printf("\nN khong phai so co cac chu so khac nhau doi mot");
      }
      printf("\nCo %d so chan\nCo %d so le", demC, demL);
      break;
    }
    case 0: printf("Bam nut bat ki de thoat\n"); break;
    default: printf("Khong co du lieu\n"); break;
  }
}

int kiemTraChanLe(int num) {
  /*Input: 1 so nguyen
    Output: true or false (1 or 0)
    description: kiem tra tinh chan le
  */
  if (num%2==0) {
    return 1;
  }
  return 0;
}

int kiemTraSNT(int num) {
  /*Input: 1 so nguyen
    Output: true or false (1 or 0)
    description: kiem tra SNT
  */
  if (num<2) {
    return 0;
  }
  for (int i = 2; i <= sqrt((float)num); i++) {
    if (num%i==0) {
      return 0;
    }
  }
  return 1;
}

int kiemTraSCP(int num) {
  /*Input: 1 so nguyen
    Output: true or false (1 or 0)
    description: kiem tra so chinh phuong
  */
  int a = sqrt((float)num);
  if (a*a == num) {
    return 1;
  }
  return 0;
}

int kiemTraSHT(int num) {
  /*Input: 1 so nguyen
    Output: true or false (1 or 0)
    description: kiem tra so hoan thien
  */
  int tong = 0;
  for (int i = 1; i <= num/2; i++) {
    if (num%i==0) {
      tong+=i;
    }
  }
  if (tong == num) {
    return 1;
  }
  return 0;
}

int uc(int num, int i){
  /*Input: 1 so nguyen, so dem
    Output: true or false (1 or 0)
    description: tim uoc
  */
  if (num%i==0) {
    return 1;
  }
  return 0;
}

int demSo(int num) {
  /*Input: 1 so nguyen
    Output: So cac chu no N
    description:
  */
  int n=0;
  while (num!=0) {
    n++;
    num/=10;
  }
  return n;
}

int tachSo(int a) {
  /*Input: 1 so nguyen
    Output: tach hang dv, chuc, tram,...
    description:
  */
  static int b = 1;
  a/=b;
  int n = a%10;
  b*=10;
  if (b==1000) {
    b = 1;
  }
  return n;
}

//Cach doc so
void docSoDV(int num) {
  switch (num) {
    case 0: printf(" ");break;
    case 1: printf(" mot");break;
    case 2: printf(" hai");break;
    case 3: printf(" ba");break;
    case 4: printf(" bon");break;
    case 5: printf(" nam");break;
    case 6: printf(" sau");break;
    case 7: printf(" bay");break;
    case 8: printf(" tam");break;
    case 9: printf(" chin");break;
  }
}
void docSoHangChuc(int num) {
  switch (num) {
    case 0: printf("le");break;
    case 1: printf("muoi");break;
    case 2: printf("hai muoi");break;
    case 3: printf("ba muoi");break;
    case 4: printf("bon muoi");break;
    case 5: printf("nam muoi");break;
    case 6: printf("sau muoi");break;
    case 7: printf("bay muoi");break;
    case 8: printf("tam muoi");break;
    case 9: printf("chin muoi");break;

  }
}
void docSonHangTram(int num) {
  switch (num) {
    case 1: printf("mot tram ");break;
    case 2: printf("hai tram ");break;
    case 3: printf("ba tram ");break;
    case 4: printf("bon tram ");break;
    case 5: printf("nam tram ");break;
    case 6: printf("sau tram ");break;
    case 7: printf("bay tram ");break;
    case 8: printf("tam tram ");break;
    case 9: printf("chin tram ");break;

  }
}
void docSo5_DV(int num) {
  printf(" lam");
}
//======================================

int bai_9(int num) {
  /*Input: 1 so nguyen
    Output: so lon nhat
    description:
  */
  int tong = 0;
  for (int i = 1; i < num; i++) {
    tong+=i;
    if (tong >= num) {
      return --i;
    }
  }
}

void bai_10(int num){
  /*Input: 1 so nguyen
    Output:
    description: in tuan va ngay le
  */
  int tuan = num/7;
  int ngayLe = num%7;
  if (tuan==0) {
    printf("%d ngay le\n", ngayLe);
  }else {
    printf("%d tuan va %d ngay le\n", tuan, ngayLe);
  }
}

void doiG(int t) {
  /*Input: 1 so giay
    Output:
    description: chuyen so giay sang dang h:m:s
  */
  int h = t/3600;
  int m = t%3600/60;
  int s= t%3600%60;
  printf("%dh: %dm: %ds\n", h, m, s);
}

void tinhPhanSo(int a,int b,int c,int d,int e,int f) {
  /*Input: 3 phan so
    Output:
    description: in tong va tich voi ket qua toi gian
  */
  int toiGian;
  //tinh tong
  int tongT, tongM;
  tongT = (a*d*f)+(c*b*f)+(e*b*d);
  tongM = b*d*f;
  toiGian = ucln(tongT, tongM);
  tongT/=toiGian;
  tongM/=toiGian;
  // tinh tich
  int tichT, tichM;
  tichT = a*c*e;
  tichM = b*d*f;
  toiGian = ucln(tichT, tichM);
  tichT/=toiGian;
  tichM/=toiGian;
  // xu li mau va in ra man hinh
  printf("\nTong 3 phan so: %d/%d (%.2f)\n", tongT, tongM, (float)tongT/tongM);
  printf("Tich 3 phan so: %d/%d (%.2f)\n", tichT, tichM, (float)tichT/tichM);
}

int ucln(int a, int b) {
  /*Input: 2 so nguyen
    Output: ucln cua 2 so nguyen
    description:tim uoc chung lon nhat cua 2 so nguyen
  */
  if (a==0 || b==0) {
    return a+b;
  }
  while (a!=b) {
    if (a>b) {
      a-=b;
    }else {
      b-=a;
    }
  }
  return a;
}

void tim_SNTCN_n(int num, int d) {
  /*Input: 1 so nguyen va so dem
    Output:
    description: tim m so nguyen to cung nhau voi n
  */
  int m = 0, i=1;
  printf("%d so nguyen to cung nhau voi so %d: ", d, num);
  while (m<d) {
    if (ucln(i, num)==1) {
      m++;
      printf("%d ", i);
    }
    i++;
  }

}

int xacDinhSoGNDM(long num, int n) {
  /*Input: 1 so nguyen, so giong nhau
    Output: true or false (1 or 0)
    description: xac dinh so giong nhau doi mot. 
    Note: n=0 => khac nhau doi mot
          n=1 => 2 chu so giong nhau
          n=2 => 2 cap so giong vd 1122
          n=3 => 3 chu so giong nhau
          n=6 => 4 chu so giong nhau
          n=10 => 5 chu so giong nhau
          .......(tuy vao do dai so duoc nhap)
  */
  int dem=0, a[10];
  int g=0; // so giong nhau
  while (num!=0) {
    a[dem++] = num%10; // gan cac so o tung hang (dv, chuc, tram...) vao mang
    num/=10;
  }
  // xet su giong nhau giua cac so trong n
  for (int i = 0; i < dem-1; i++) {
    for (int j=i+1; j < dem; j++) {
      if (a[i]!=a[j]) {
        continue;
      }else{
        g++;
      }
    }
  }

  if(g==n){
    return 1;
  }
  return 0;
}

int bai_16(int num){
  int a,b,c, tong, tich;
  a = tachSo(num);
  b = tachSo(num);
  c = tachSo(num);
  if(c==0){
    tong = a+b;
    tich = a*b;
  }else{
    tong = a+b+c;
    tich = a*b*c;
  }
  
  if(tong==tich){
    return 1;
  }
  return 0;
}
