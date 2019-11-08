#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX_SIZE  100
int timSNT(int);
void timSoKhacNhau(int i, int a[], int &b);
void nhapMang(int a[], int &n){
  printf("Nhap so phan tu trong mang: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("a[%d]= ", i);
    scanf("%d", &a[i]);
  }
}
void xuatMang(int a[], int n){
  printf("Xuat mang vua nhap: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}
void nhapMangCL(int a[], int &n) {
  int temp, i=0;
  bool bl;
  printf("Nhap so phan tu trong mang: ");
  scanf("%d", &n);
  printf("a[%d]= ", i);
  scanf("%d", &temp);
  if (temp%2==0) {
    bl = true;
    a[i++]=temp;
  }else {
    bl = false;
    a[i++]=temp;
  }
  for (; i < n; i++) {
    if (bl) {
      do {
        printf("a[%d]= ", i);
        scanf("%d", &temp);
        if (temp%2!=0) {
          bl=!bl;
          a[i]=temp;
        }
      } while(bl);
    }else {
      do {
        printf("a[%d]= ", i);
        scanf("%d", &temp);
        if (temp%2==0) {
          bl=!bl;
          a[i]=temp;
        }
      } while(!bl);
    }
  }
}
void xuatPT_max(int a[], int n) {
  int k;
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (max<a[i]) {
      max = a[i];
      k=i;
    }
  }
  printf("phan tu lon nhat: %d\n", max);
  printf("Nam o phan tu thu: %d\n", k+1);
}
void xuatPT_min(int a[], int n) {
  int k;
  int min = a[0];
  for (int i = 1; i < n; i++) {
    if (min>a[i]) {
      min = a[i];
      k=i;
    }
  }
  printf("phan tu nho nhat: %d\n", min);
  printf("Nam o phan tu thu: %d\n", k+1);
}
void tongPT_CL(int a[], int n) {
  int tongC=0, tongL=0;
  for (int i = 0; i < n; i++) {
    if (a[i]%2==0) {
      tongC+=a[i];
    }else{
      tongL+=a[i];
    }
  }
  printf("Tong cac phan tu chan: %d\n", tongC);
  printf("Tong cac phan tu le: %d\n", tongL);
}
void xuatViTri_CL(int a[], int n){
  int c[MAX_SIZE], l[MAX_SIZE], dc=0, dl=0;
  for (int i = 0; i < n; i++) {
    if (i%2==0) {
      c[dc++]=a[i];
    }else{
      l[dl++]=a[i];
    }
  }
  printf("Cac phan tu o vi tri chan: ");
  for (int i = 0; i < dc; i++) {
    printf("%d ", c[i]);
  }
  printf("\n\nCac phan tu o vi tri le: ");
  for (int i = 0; i < dl; i++) {
    printf("%d ", l[i]);
  }
}
void xuat_AMax_DMin(int a[], int n){
  int maxA, minD;
  int ba=0, bd=0;
  for (int i = 0; i < n; i++) {
    if (a[i]>0) {
      minD = a[i];
      bd = 1;
    }
    if (a[i]<0) {
      maxA = a[i];
      ba= 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i]>0) {
      if (minD>a[i]) {
        minD = a[i];
      }
    }
    if (a[i]<0) {
      if (maxA<a[i]) {
        maxA = a[i];
      }
    }
  }
  if (!bd) {
    printf("Khong co gia tri duong\n");
  }else{
    printf("so duong nho nhat: %d\n", minD);
  }
  if (!ba) {
    printf("Khong co gia tri am\n");
  }else{
    printf("so am lon nhat: %d\n", maxA);
  }
}
void nhapMangKQ_2_Lan(int a[], int &n) {
  int d, j=0;
  printf("nhap so phan tu: ");
  scanf("%d", &n);
  printf("a[%d]= ", j);
  scanf("%d", &a[j]);
  for (int i = 1; i < n; i++) {
    //2 2 2 2 2 2 3
    do {
      d=0;
      printf("a[%d]= ", i);
      scanf("%d", &a[i]);
      for (int q = i-1; q >= j; q--) {
        if (a[i]==a[q]) {
          d++;
        }
      }
    } while(d==2);
  }
}
void nhapSDTD(int a[], int &n){
  int temp, temp1;
  printf("nhap so phan tu: ");
  scanf("%d", &n);
  printf("a[%d]= ", 0);
  scanf("%d", &temp);
  a[0]=temp;
  for (int i = 1; i < n; i++) {
    do {
      printf("a[%d]= ", i);
      scanf("%d", &a[i]);
      if (a[i]<=0) {
        temp1 = temp;
        break;
      }
      temp1 = temp;
      if (temp<a[i]) {
        temp=a[i];
      }
    } while(temp<=temp1||a[i-1]>=a[i]);
  }
}
void nhapMang_17(int a[], int &n) {
  int d=0, sub, temp, bl=0;
  printf("so phan tu cua mang: ");
  scanf("%d", &n);
  // 8 4 6 7 5 10 -9
  for (int i = 0; i < n; i++) {
    do {
      bl=0;
      printf("a[%d]= ", i);
      scanf("%d", &a[i]);
      if (i>1) {
        for (int j = i-1; j >= 0; j--) {
          sub=a[i]-a[j];
          if (abs(sub)>4) {
            bl++;
          }
        }
      }
      if (a[i]==0) {
        d++;
      }
    } while(a[i]<=0||d>3||bl!=0);
  }
}
void nhapMang_18(int a[], int &n){
  int d, bl, max, g;
  printf("nhap so phan tu: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    //2 2 2 2 2 2 3
    do {
      d=0;
      bl=0;
      g=0;
      printf("a[%d]= ", i);
      scanf("%d", &a[i]);
      if (timSNT(a[i])) {
        if (a[i]>200) {
          bl=1;
        }
      }else{
        if (i>0) {
          for (int q = i-1; q >= 0; q--) {
            if (a[i]<=a[q]) {
              g=1;
            }
          }
        }
      }
      timSoKhacNhau(i,a,d);
    } while(d!=0 || bl || !g);
  }
}

void main() {
  int chon, soBai=22, stt=0;
  do {
    for (int i = 1; i <= soBai; i++) {
      if (i>=7&&i<=22) {
        printf("%d. Bai %d\t", ++stt, i);
        if (i%5==0) {
          printf("\n");
        }
      }
    }
    printf("\nChon: ");
    scanf("%d", &chon);
    switch (chon) {
      case 2:
      case 1: {
        int a[MAX_SIZE], n;
        nhapMang(a,n);
        xuatMang(a,n);
        break;
      }
      case 3: {
        int arr[MAX_SIZE], n;
        nhapMangCL(arr,n);
        xuatMang(arr, n);
        break;
      }
      case 4: {
        int arr[MAX_SIZE], n;
        nhapMang(arr, n);
        xuatPT_max(arr, n);
        break;
      }
      case 5: {
        int arr[MAX_SIZE], n;
        nhapMang(arr, n);
        xuatPT_min(arr, n);
        break;
      }
      case 6: {
        int arr[MAX_SIZE], n;
        nhapMang(arr, n);
        tongPT_CL(arr, n);
        break;
      }
      case 7: {
        int arr[MAX_SIZE], n;
        nhapMang(arr, n);
        xuatViTri_CL(arr, n);
        break;
      }
      case 8: {
        int arr[MAX_SIZE], n;
        nhapMang(arr, n);
        xuat_AMax_DMin(arr, n);
        break;
      }
      case 9: {
        int arr[MAX_SIZE], n;
        nhapMangKQ_2_Lan(arr, n);
        xuatMang(arr, n);
      }
      case 10: {
        int arr[MAX_SIZE], n;
        nhapSDTD(arr, n);
        xuatMang(arr, n);
        break;
      }
      case 11: {
        int arr[MAX_SIZE], n;
        nhapMang_17(arr, n);
        xuatMang(arr, n);
        break;
      }
      case 12: {
        int arr[MAX_SIZE], n;
        nhapMang_18(arr, n);
        xuatMang(arr, n);
        break;
      }
      case 13: {}
      case 14: {}
      case 15: {}
      case 16: {}
    }
    printf("\n+=====+=======================+\n");
  } while(chon!=0);
  getch();
}

int timSNT(int a){
  if (a<2) {
    return 0;
  }
  for (int i = 2; i <= sqrt((float)a); i++) {
    if (a%i==0) {
      return 0;
    }
  }
  return 1;
}
void timSoKhacNhau(int i, int a[], int &b){
  if (i>1) {
    for (int q = i-1; q >= 0; q--) {
      if (a[i]==a[q]) {
        b++;
      }
    }
  }
}
