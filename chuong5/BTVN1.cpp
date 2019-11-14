#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 1000
void sapXepAD(int a[], int n);
void sapXepCL(int a[], int n);
void xoaSNT(int a[], int &n);
void taoMang_DMKN(int a[],int n, int b[], int &k);
int demSoDuong(int a[], int b);
int layPhanDuong(int a[], int n, int i);
void sapXepTangDan(int a[], int n);
void sapXepGiamDan(int a[], int n);
void swap(int &a, int &b);
int timSoLanXH_max(int a[], int n);
int kiemTraSD_min(int a[], int n);
int kiemTraCo_zero(int a[], int n);
int timSoDoiBP_min(int a[], int n);
int timaBP_min(int a[], int n);
int timSNT_MAX(int a[], int n);
int demSoLanX_XH(int a[], int n, int x);
int demSNT(int a[], int n);
int timSNT(int);
int demSoKhongAm(int a[], int n);
int tinhTongVT_chan(int a[], int n);
int tinhTongVT_le(int a[], int n);
int float_random(int,int);
int random(int, int);
void chenX_VT_i(int a[], int &n, int x, int m);
void xoaPT_i(int a[], int &n, int m);

void nhapMang(int a[], int &n){
  int chon;
  do {
    printf("Nhap gia tri cua mang: ");
    scanf("%d", &n);
  } while(n<=0||n>MAX_SIZE);
  printf("Chon phuong thuc:\n");
  printf("1. Nhap tu ban phim\n");
  printf("2. Phat sinh ngau nhien\n");
  do {
    printf("Chon: ");
    scanf("%d", &chon);
  } while(chon!=2&&chon!=1);
  if (chon==1) {
    for (int i = 0; i < n; i++) {
      printf("a[%d]= ", i);
      scanf("%d", &a[i]);
    }
  }else {
    for (int i = 0; i < n; i++) {
      a[i] = random(-100, 100);
    }
  }
}
void xuatMang(int a[], int n){
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}
void nhap_xuat_arr(int a[], int &n){
  nhapMang(a, n);
  printf("Mang vua nhap: ");
  xuatMang(a, n);
}

void main(){
  int chon, soBai=37, stt=0;
  printf("\n\tList bai tap\n");
  do {
    for (int i = 1; i <= soBai; i++) {
      if (i>=23&&i<=37) {
        printf("%d. Bai %d\t", ++stt, i);
        if (i%5==0) {
          printf("\n");
        }
      }
    }
    printf("\nChon: ");
    scanf("%d", &chon);
    switch (chon) {
      case 1: {
        int c, arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        do {
          printf("\nChon vi tri muon xoa: ");
          scanf("%d", &c);
          if (c<0 || c>n) {
            printf("Moi ban nhap lai\n");
          }
        } while(c<0 || c>n);
        xoaPT_i(arr, n, c);
        printf("Mang sau khi xoa: ");
        xuatMang(arr, n);
	      break;
      }
      case 2: {
        int arr[MAX_SIZE], n, x, c;
        nhap_xuat_arr(arr, n);
        printf("\nNhap x: ");
        scanf("%d", &x);
        printf("Nhap vi tri muon them: ");
        scanf("%d", &c);
        chenX_VT_i(arr, n, x, c);
        printf("Mang sau khi xoa: ");
        xuatMang(arr, n);
	      break;
      }
      case 3: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        printf("\nTong cac vi tri chan: %d\n", tinhTongVT_chan(arr, n));
        printf("Tong cac vi tri le: %d\n", tinhTongVT_le(arr,n));
        break;
      }
      case 4: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        printf("\nCo %d so khong am\n", demSoKhongAm(arr, n));
        break;
      }
      case 5: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        printf("\nCo %d so nguyen to\n", demSNT(arr, n));
        break;
      }
      case 6: {
        int arr[MAX_SIZE], n, a;
        nhap_xuat_arr(arr, n);
        printf("Nhap x: ");
        scanf("%d", &a);
        printf("So lan phan tu x xuat hien: \n", demSoLanX_XH(arr, n, a));
        break;
      }
      case 7: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        printf("\nSo nguyen to lon nhat: %d", timSNT_MAX(arr, n));
        break;
      }
      case 8: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        if (kiemTraCo_zero(arr, n)) {
          printf("\nSo co binh phuong nho nhat: %d", 0);
        }else if (!kiemTraCo_zero(arr, n)&&kiemTraSD_min(arr, n)) {
          printf("\nSo co binh phuong nho nhat: %d va %d", abs(timaBP_min(arr, n)), timSoDoiBP_min(arr, n));
        }else {
          printf("\nSo co binh phuong nho nhat: %d", timaBP_min(arr, n));
        }
        break;
      }
      case 9: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        if (timSoLanXH_max(arr, n)!=-1) {
          printf("\nSo xuat hien nhieu nhat: %d\n", timSoLanXH_max(arr, n));
        }else{
          printf("\nMoi phan tu xuat hien mot lan\n");
        }
        break;
      }
      case 10: {
        int arr[MAX_SIZE], n, b[MAX_SIZE];
        nhap_xuat_arr(arr, n);
        int k = demSoDuong(arr, n);
        for (int i = 0; i < k; i++) {
          b[i]= layPhanDuong(arr, n, i);
        }
        printf("\nXuat mang b[]: ");
        xuatMang(b, k);
        break;
      }
      case 11: {
        int arr[MAX_SIZE], b[MAX_SIZE], n, k;
        nhap_xuat_arr(arr, n);
        taoMang_DMKN(arr, n, b, k);
        printf("\nMang b[]: ");
        xuatMang(b,k);
        break;
      }
      case 12: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        xoaSNT(arr, n);
        printf("\nMang sau khi xoa: ");
        xuatMang(arr, n);
        break;
      }
      case 13: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        sapXepCL(arr, n);
        printf("\nMang sau khi sap xep: ");
        xuatMang(arr,n);
      }
      case 14: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        sapXepAD(arr, n);
        printf("\nMang sau khi sap xep: ");
        xuatMang(arr,n);
        break;
      }
      case 15: {
        int arr[MAX_SIZE], n;
        nhap_xuat_arr(arr, n);
        
      }
      default: printf("Invalid\n"); break;
    }
    printf("\n+=====+=======================+\n");
    stt=0;
  } while(chon!=0);
}

void xoaPT_i(int a[], int &n, int m) {
  for (int i = m-1; i < n-1; i++) {
    a[i]=a[i+1];
  }
  n--;
}
void chenX_VT_i(int a[], int &n, int x, int k) {
  if (k<0 || k > n || n > MAX_SIZE) {
    return;
  }
  for (int i = n; i > k ; i--) {
    a[i] = a[i-1];
  }
  a[k] =x;
  n++;
}
int random(int min, int max){
  return min + rand()%(max +1 - min);
}
int float_random(int min, int max){
  float scale = rand()/(float)RAND_MAX;
  return min + scale*(max-min);
}
int tinhTongVT_chan(int a[], int n){
  int s=0;
  for (int i = 0; i < n; i+=2) {
    s+=a[i];
  }
  return s;
}
int tinhTongVT_le(int a[], int n){
  int s=0;
  for (int i = 1; i < n; i+=2) {
    s+=a[i];
  }
  return s;
}
int demSoKhongAm(int a[], int n){
  int dem=0;
  for (int i = 0; i < n; i++) {
    if (a[i]>=0) {
      dem++;
    }
  }
  return dem;
}
int timSNT(int num){
  if (num<2) {
    return 0;
  }
  for (int i = 2; i < sqrt((float)num); i++) {
    if (num%i==0) {
      return 0;
    }
  }
  return 1;
}
int demSNT(int a[], int n){
  int d=0;
  for (int i = 0; i < n; i++) {
    if (timSNT(a[i])) {
      d++;
    }
  }
  return d;
}
int demSoLanX_XH(int a[], int n, int x){
  int d=0;
  for (int i = 0; i < n; i++) {
    if (a[i]==x) {
      d++;
    }
  }
  return d;
}
int timSNT_MAX(int a[], int n){
  int temp, max,bl=0;
  for (int i = 0; i < n; i++) {
    if (timSNT(a[i])) {
      max = a[i];
      temp = i;
      bl=1;
      break;
    }
  }
  if (bl) {
    for (int i = temp+1; i < n; i++) {
      if (max<a[i]&&timSNT(a[i])) {
        max=a[i];
      }
    }
  }else{
    return 0;
  }
  return max;
}
int kiemTraCo_zero(int a[], int n){
  for (int i = 0; i < n; i++) {
    if (a[i]==0) {
      return 1;
    }
  }
  return 0;
}
int kiemTraSD_min(int a[], int n){
  int minD, maxA, bl1=0, bl2=0;
  for (int i = 0; i < n; i++) {
    if (a[i]>0) {
      minD=a[i];
    }
    if (a[i]<0) {
      maxA = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (maxA<a[i]&&a[i]<0) {
      maxA = a[i];
    }
    if (minD>a[i]&&a[i]>0) {
      minD = a[i];
    }
  }

  for (int i = 0; i < n; i++) {
    if (abs(maxA)==a[i]) {
      bl1=1;
    }
    if (minD==-a[i]) {
      bl2=1;
    }
  }
  if (bl1&&bl2) {
    return 1;
  }
  return 0;
}
int timSoDoiBP_min(int a[], int n){
  int min, temp;
  for (int i = 0; i < n; i++) {
    if (a[i]>0) {
      min = a[i];
      temp = i;
      break;
    }
  }
  for (int i = temp+1; i < n; i++) {
    if (min>a[i]&&a[i]>0) {
      min = a[i];
    }
  }
  min*=min;
  for (int i = 0; i < n; i++) {
    if (a[i]*a[i]==min&&a[i]<0) {
      temp = a[i];
    }
  }
  return temp;
}
int timaBP_min(int a[], int n){
  int temp = a[0];
  int min = temp*temp;
  for (int i = 0; i < n; i++) {
    if (min>a[i]*a[i]) {
      temp = a[i];
      min = temp*temp;
    }
  }
  return temp;
}
void swap(int &a, int &b){
  int t;
  t=a;
  a=b;
  b=t;
}
void sapXepGiamDan(int a[], int n){
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i]<a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}
void sapXepTangDan(int a[], int n){
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i]>a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}
int timSoLanXH_max(int a[], int n){
  sapXepGiamDan(a, n);
  int temp=-1, d=1, max=0;
  for (int i = 0; i < n-1; i++) {
    if (a[i]==a[i+1]) {
      d++;
      if (d>max) {
        max = d;
        temp = i;
      }
    }else {
      d=1;
    }
  }
	return a[temp];
}
int layPhanDuong(int a[], int n, int i){
  sapXepGiamDan(a, n);
  return a[i];
}
int demSoDuong(int a[], int b){
  int d=0;
  for (int i = 0; i < b; i++) {
    if (a[i]>0) {
      d++;
    }
  }
  return d;
}
void taoMang_DMKN(int a[], int n, int b[], int &k){
  k=0;
  sapXepGiamDan(a, n);
  for (int i = 0; i < n-1; i++) {
    if (a[i]==a[i+1]) {
      continue;
    }
    b[k++]=a[i];
  }
  if (a[n-2]!=a[n-1]) {
    b[k++]=a[n-1];
  }else{
    b[k++]=a[n-2];
  }
}
void xoaSNT(int a[], int &n){
  int i=0;
  while (i<n) {
    if (timSNT(a[i])) {
      for (int j = i; j < n-1; j++) {
        a[j]=a[j+1];
      }
      n--;
    }else{
      i++;
    }
  }
}
void sapXepCL(int a[], int n){
  int chan[MAX_SIZE], le[MAX_SIZE],c=0,l=0;
  for (int i = 0; i < n; i++) {
    if (a[i]%2==0) {
      chan[c++]=a[i];
    }else{
      le[l++]=a[i];
    }
  }
  sapXepTangDan(chan, c);
  sapXepTangDan(le, l);
  for (int i = 0; i < n; i++) {
    if (i<c) {
      a[i]= chan[i];
    }else{
      a[i]=le[--l];
    }
  }
}
void sapXepAD(int a[], int n){
  int duong[MAX_SIZE], am[MAX_SIZE], khong[MAX_SIZE],q=0,w=0,k=0;
  for (int i = 0; i < n; i++) {
    if (a[i]!=0) {
      if (a[i]>0) {
        duong[q++]=a[i];
      }else{
        am[w++]=a[i];
      }
    }else {
      khong[k++]=a[i];
    }
  }
  sapXepTangDan(duong, q);
  sapXepTangDan(am, w);
  for (int i = 0; i < k; i++) {
    a[n-1-i]=khong[i];
  }
  for (int i = 0; i < n-k; i++) {
    if (i<q) {
      a[i]= duong[i];
    }else{
      a[i]=am[--w];
    }
  }
}
