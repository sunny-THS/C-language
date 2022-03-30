// STT: 29
// MSSV: 2001190791
// Ho va Ten: Tu Hue Son
// Noi Dung: Bai tap ve nha buoi
// ----------------------------------------
// khai bao thu vien
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// khai bao hang so
#define MAXSIZE 100

// khai bao prototype
int menu();
void chucNang(int);
int iRandom(int min, int max);
float fRandom(float min, float max);
void nhapMang1Chieu_iRandom(int *arr, int &n);
void nhapMang1Chieu_fRandom(float *arr, int &n);
void iXuatMang(int *arr, int n);
void fXuatMang(float *arr, int n);
void mergeASC(int * arr, int l, int mid, int r);
void mergeDESC(int * arr, int l, int mid, int r);
void mergeSort(int * arr, int l, int r, void(*merge)(int*, int, int, int));
long iPow(long, long);
int getSize(long num);
long karatsuba(long x, long y);
bool sortASC(int, int);
bool sortDESC(int, int);
void quickSort(int * arr, int l, int r, bool(*typeSort)(int,int));
void Swap(int & a, int & b);
// ham main
int main() {
  srand(time(0));
  while (1) {
    int iSelect = menu();
    printf("\n==========================================================\n");
    chucNang(iSelect);
    printf("\n==========================================================\n");
    printf("\n\n");
    getch();
    fflush(stdin);
    system("cls");
  }
  return 1;
}
int menu() {
  int iChonCau = -1;
  printf("================= Bai tap ve nha =========================");
  printf("\n==Bai 1, cai dat ham mergeSort \t\t\t\t==");
  printf("\n==Bai 2, nhan 2 so nguyen lon \t\t\t\t==");
  printf("\n==Bai 3, thuat toan sap xep nhanh \t\t\t==");
  printf("\n==Bai 4, bai toan luy thua x^y \t\t\t\t==");
  printf("\n==\t\t\t\t\t\t\t==");
  printf("\n== \t\t\t0. Thoat\t\t\t==");
  printf("\n==========================================================\n");
  printf("\nChon: ");
  scanf("%d", &iChonCau);
  return iChonCau;
}
void chucNang(int iSelect) {
  int iArr[MAXSIZE];
  float fArr[MAXSIZE];

  int n;

  switch (iSelect) {
  case 0:
    exit(0);
    break;
  case 1: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    printf("\n\nSap xep tang dan\n");
    mergeSort(iArr, 0, n-1, mergeASC);
    iXuatMang(iArr, n);
    printf("\n\nSap xep giam dan\n");
    mergeSort(iArr, 0, n-1, mergeDESC);
    iXuatMang(iArr, n);
  } break;
  case 2: {
    long a, b;
    printf("\nNhap a: ");
    scanf("%ld", &a);
    printf("\nNhap b: ");
    scanf("%ld", &b);
    printf("Tich 2 so %ld\n", karatsuba(a, b));
  } break;
  case 3: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    printf("\n\nSap xep tang dan\n");
    quickSort(iArr, 0, n-1, sortASC);
    iXuatMang(iArr, n);
    printf("\n\nSap xep giam dan\n");
    quickSort(iArr, 0, n-1, sortDESC);
    iXuatMang(iArr, n);
  } break;
  case 4: {
    int x, y;
    printf("\nNhap x: ");
    scanf("%ld", &x);
    printf("\nNhap y: ");
    scanf("%ld", &y);
    printf("Luy thua x^y = %d\n", iPow(x, y));
  } break;
  default:
    printf("Khong co bai nay vui long nhap lai\n");
    break;
  }
}
int iRandom(int min, int max) {
  // ham tra ve 1 so nguyen ngau nhien tu min den max
  return min + rand() % (max + 1 - min);
}
float fRandom(float min, float max) {
  // ham tra ve 1 so thuc ngau nhien tu min den max
  return min + (rand() / (float)RAND_MAX) * (max - min);
}
void nhapMang1Chieu_iRandom(int *arr, int &n) {
  do {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
  } while (n <= 0);
  for (size_t i = 0; i < n; i++) {
    arr[i] = iRandom(-100, 100);
  }
}
void nhapMang1Chieu_fRandom(float *arr, int &n) {
  do {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
  } while (n <= 0);
  for (size_t i = 0; i < n; i++) {
    arr[i] = fRandom(-100, 100);
  }
}
void iXuatMang(int *arr, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
void fXuatMang(float *arr, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%.2f ", arr[i]);
  }
}
void mergeASC(int * arr, int l, int mid, int r) {
  int i, j, k;
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeDESC(int * arr, int l, int mid, int r) {
  int i, j, k;
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] > R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
// hàm mergeSort
void mergeSort(int * arr, int l, int r, void(*merge)(int*, int, int, int)) {
  if (l < r) {
    int mid = (l + r)/2;
    mergeSort(arr, l, mid, merge);
    mergeSort(arr, mid + 1, r, merge);

    merge(arr, l, mid, r);
  }
}

//trả về kích thước của số vd 123 có độ dài bằng 3
int getSize(long num) {
  int count = 0;
  while (num > 0) {
    count++;
    num /= 10;
  }
  return count;
}

// tinh luy thua a^b
long iPow(long a, long b) {
  if (b == 1) // base case
    return a;
  return b % 2 == 0 ? iPow(a, b/2) * iPow(a, b/2) :\
                      iPow(a, b/2) * iPow(a, b/2) * a;
}

long karatsuba(long x, long y) {
  // Base Case
  if (x < 10 && y < 10)
    return x * y;

  // determine the size of X and Y
  int size = fmax(getSize(x), getSize(y));

  // Split X and Y
  int n = size / 2;
  long p = iPow(10, n);

  long a = x / p;
  long b = x % p;
  long c = y / p;
  long d = y % p;

  // Recur until base case
  long ac = karatsuba(a, c);
  long bd = karatsuba(b, d);
  long e = karatsuba(a + b, c + d) - ac - bd;

  // return the equation
  return iPow(10, 2 * n) * ac + iPow(10, n) * e + bd;
}
// hàm Swap
void Swap(int & a, int & b) {
  int t = a;
  a = b;
  b = t;
}
bool sortASC(int a, int b) {
  return a > b;
}
bool sortDESC(int a, int b) {
  return a < b;
}
void quickSort(int * arr, int l, int r, bool(*typeSort)(int,int)) {
  // điều kiện dừng
  if (l >= r) return;
  int mid = (l + r) / 2;
  int left = l;
  int right = r;
  int x = arr[mid]; // lấy móc mid để phân hoạch

  do {
    while (typeSort(x, arr[left]))
      left++;
    while (typeSort(arr[right], x))
      right--;
    if (left <= right) {
      Swap(arr[left], arr[right]);
      left++; right--;
    }
  } while(left < right);

  // gọi đệ quy
  quickSort(arr, l, right, typeSort);
  quickSort(arr, left, r, typeSort);
}
