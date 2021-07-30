// STT: 29
// MSSV: 2001190791
// Ho va Ten: Tu Hue Son
// Noi Dung: Bai tap ve nha buoi 2
// ----------------------------------------
// khai bao thu vien
#include <cmath>
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
void nhapMang2Chieu_iRandom(int arr[MAXSIZE][MAXSIZE], int &rows, int &cols);
void nhapMang2Chieu_fRandom(float arr[MAXSIZE][MAXSIZE], int &rows, int &cols);
void iXuatMang(int *arr, int n);
void fXuatMang(float *arr, int n);
void iXuatMang_2c(int arr[MAXSIZE][MAXSIZE], int rows, int cols);
void fXuatMang_2c(float arr[MAXSIZE][MAXSIZE], int rows, int cols);
bool isSHT(int num);
bool isSNT(int num);
bool is_soDau_le(int num);
bool is_soHangChu_5(int num);
bool is_maTran_toanDuong(int arr[MAXSIZE][MAXSIZE], int rows, int cols);
void lietKeGtriChan(int *arr, int n);
void lietKeVtri_gtriAm(int *arr, int n);
void lietKeGtri_SHT(int arr[MAXSIZE][MAXSIZE], int rows, int cols);
int timGiaTri_max(int *arr, int n);
float timGiaTri_duongFirst(float *arr, int n);
float timGiatri_duongMin(float *arr, int n);
int timGiaTri_chanLast(int *arr, int n);
int timGiaTri_SNTFirst(int *arr, int n);
int timVtri_SHT_min(int *arr, int n);
int timVtri_chanFirst(int *arr, int n);
int timVtri_SHT_last(int *arr, int n);
int sum_ptu_soDau_le(int arr[MAXSIZE][MAXSIZE], int rows, int cols);
int sum_ptu_lonHon_TTD_soSau(int arr[MAXSIZE][MAXSIZE], int rows, int cols);
int sum_ptu_row(int arr[MAXSIZE][MAXSIZE], int rows, int cols, int row);
int sum_ptu_cacBien(int arr[MAXSIZE][MAXSIZE], int);              // ma tran
int sum_ptu_duong_row(int arr[MAXSIZE][MAXSIZE], int n, int row); // ma tran
int count_ptu_soHangChuc_5(int arr[MAXSIZE][MAXSIZE], int rows, int cols);
int count_xuatHien_x(int arr[MAXSIZE][MAXSIZE], int n, int x); // ma tran
int count_yenNgua(int arr[MAXSIZE][MAXSIZE], int n);           // ma tran
// ham main
int main() {
  srand(time(0));
  while (1) {
    int iSelect = menu();
    printf(
        "\n==============================================================\n");
    chucNang(iSelect);
    printf(
        "\n==============================================================\n");
    printf("\n\n");
    getch();
    fflush(stdin);
  }
  return 1;
}
int menu() {
  int iChonCau = -1;
  printf("================= Bai tap ve nha =========================");
  printf("\n== \t\t\tMang 1 chieu\t\t\t==");
  printf("\n== Bai 1.1: liet ke cac gia tri chan \t\t\t==");
  printf("\n== Bai 1.2: liet ke vi tri co gia tri am \t\t==");
  printf("\n== Bai 1.3: tim gia tri lon nhat \t\t\t==");
  printf("\n== Bai 1.4: tim gia tri duong dau tien (so thuc)\t==");
  printf("\n== Bai 1.5: tim so chan cuoi cung \t\t\t==");
  printf("\n== Bai 1.6: tim vi tri so hoan thien nho nhat \t\t==");
  printf("\n== Bai 1.7: tim vi tri cua gia tri chan dau tien \t==");
  printf("\n== Bai 1.8: tim vi tri so hoan thien cuoi cung \t\t==");
  printf("\n== Bai 1.9: tim gia tri duong nho nhat (so thuc) \t==");
  printf("\n== Bai 1.10: tim SNT dau tien \t\t\t\t==");
  printf("\n==\t\t\t\t\t\t\t==");
  printf("\n== \t\t\tMang 2 chieu\t\t\t==");
  printf("\n== Bai 2.1: tinh tong cac ptu chu so dau la so le \t==");
  printf("\n== Bai 2.2: dem ptu co chu so hang chuc la 5 \t\t==");
  printf("\n== Bai 2.3: liet ke cac so hoan thien \t\t\t==");
  printf("\n== Bai 2.4: tinh tong cac ptu lon hon TTD cua so sau no ==");
  printf("\n== Bai 2.5: tinh tong gia tri tren 1 dong ma tran \t==");
  printf("\n== Bai 2.6: kiem tra ma tran toan duong \t\t==");
  printf("\n== Bai 2.7: tinh tong cac gia tri tren bien cua ma tran ==");
  printf("\n== Bai 2.8: dem tan suat xuat hien cua ptu x trong mtran==");
  printf("\n== Bai 2.9: tinh tong gtri duong tren 1 dong ma tran \t==");
  printf("\n== Bai 2.10: Dem so luong \"yen ngua\" \t\t\t==");
  printf("\n==\t\t\t\t\t\t\t==");
  printf("\n== \t\t\t0. Thoat\t\t\t==");
  printf("\n==========================================================\n");
  printf("\nChon: ");
  scanf("%d", &iChonCau);
  return iChonCau;
}
void chucNang(int iSelect) {
  int *iArr = new int;
  float *fArr = new float;

  int iArr_2c[MAXSIZE][MAXSIZE];
  float fArr_2c[MAXSIZE][MAXSIZE];

  int n;

  int rows, cols;

  switch (iSelect) {
  case 0:
    exit(0);
    break;
  case 11: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    printf("\nKQ: \n");
    lietKeGtriChan(iArr, n);
  } break;
  case 12: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    printf("\nVi tri co gia tri am: ");
    lietKeVtri_gtriAm(iArr, n);
  } break;
  case 13: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    printf("\nGia tri lon nhat: %d", timGiaTri_max(iArr, n));
  } break;
  case 14: {
    nhapMang1Chieu_fRandom(fArr, n);
    fXuatMang(fArr, n);
    float kq = timGiaTri_duongFirst(fArr, n);
    if (kq != -1)
      printf("\nKQ: %.2f", kq);
    else
      printf("\nKhong tim thay so duong");
  } break;
  case 15: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    int kq = timGiaTri_chanLast(iArr, n);
    if (kq != -1)
      printf("\nKQ: %d", kq);
    else
      printf("\nKhong tim thay so chan");
  } break;
  case 16: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    int kq = timVtri_SHT_min(iArr, n);
    if (kq != -1)
      printf("\nKQ: %d", kq);
    else
      printf("\nKhong tim thay so hoan thien");
  } break;
  case 17: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    int kq = timVtri_chanFirst(iArr, n);
    if (kq != -1)
      printf("\nKQ: %d", kq);
    else
      printf("\nKhong tim thay so chan");
  } break;
  case 18: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    int kq = timVtri_SHT_last(iArr, n);
    if (kq != -1)
      printf("\nKQ: %d", kq);
    else
      printf("\nKhong tim thay so hoan thien");
  } break;
  case 19: {
    nhapMang1Chieu_fRandom(fArr, n);
    fXuatMang(fArr, n);
    float kq = timGiatri_duongMin(fArr, n);
    if (kq != -1)
      printf("\nKQ: %.2f", kq);
    else
      printf("\nKhong tim thay so duong");
  } break;
  case 110: {
    nhapMang1Chieu_iRandom(iArr, n);
    iXuatMang(iArr, n);
    int kq = timGiaTri_SNTFirst(iArr, n);
    if (kq != -1)
      printf("\nKQ: %d", kq);
    else
      printf("\nKhong tim thay so nguyen to");
  } break;
  case 21: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    printf("\nTong cac so co chu so dau la le: %d",
           sum_ptu_soDau_le(iArr_2c, rows, cols));
  } break;
  case 22: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    printf("\nSo luong cac so co chu so hang chuc la 5: %d",
           count_ptu_soHangChuc_5(iArr_2c, rows, cols));
  } break;
  case 23: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    printf("\nKQ: ");
    lietKeGtri_SHT(iArr_2c, rows, cols);
  } break;
  case 24: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    printf("\nTong cac ptu lon hon TTD cua so sau no: %d",
           sum_ptu_lonHon_TTD_soSau(iArr_2c, rows, cols));
  } break;
  case 25: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    size_t row;
    printf("\nNhap hang can tinh: ");
    scanf("%d", &row);
    printf("\nTong cac ptu tren hang %d: %d", row,
           sum_ptu_row(iArr_2c, rows, cols, row - 1));
  } break;
  case 26: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    if (is_maTran_toanDuong(iArr_2c, rows, cols))
      printf("\nMa tran toan duong");
    else
      printf("\nMa tran co so am");
  } break;
  case 27: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    printf("Tong cac gia tri tren bien cua ma tran: %d",
           sum_ptu_cacBien(iArr_2c, rows));
  } break;
  case 28: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    int x;
    printf("\nNhap x: ");
    scanf("%d", &x);
    printf("So lan xuat hien cua ptu x: %d lan",
           count_xuatHien_x(iArr_2c, rows, x));
  } break;
  case 29: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    size_t row;
    printf("\nNhap hang can tinh: ");
    scanf("%d", &row);
    printf("Tong cac gia tri duong tren hang %d: %d", row,
           sum_ptu_duong_row(iArr_2c, rows, row - 1));
  } break;
  case 210: {
    nhapMang2Chieu_iRandom(iArr_2c, rows, cols);
    iXuatMang_2c(iArr_2c, rows, cols);
    printf("Tong so \"yen ngua\" cua ma tran: %d",
           count_yenNgua(iArr_2c, rows));
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
void nhapMang2Chieu_iRandom(int arr[MAXSIZE][MAXSIZE], int &rows, int &cols) {
  do {
    printf("Nhap so dong: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
  } while (rows <= 0 || cols <= 0);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      arr[i][j] = iRandom(-100, 100);
}
void nhapMang2Chieu_fRandom(float arr[MAXSIZE][MAXSIZE], int &rows, int &cols) {
  do {
    printf("Nhap so dong: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
  } while (rows <= 0 || cols <= 0);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      arr[i][j] = fRandom(-100, 100);
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
void iXuatMang_2c(int arr[MAXSIZE][MAXSIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%5d ", arr[i][j]);
    }
    printf("\n");
  }
}
void fXuatMang_2c(float arr[MAXSIZE][MAXSIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%5.2f  ", arr[i][j]);
    }
    printf("\n");
  }
}
bool isSHT(int num) {
  if (num <= 0)
    return false;
  int sum = 0;
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }
  return sum == num ? true : false;
}
bool isSNT(int num) {
  if (num < 2)
    return false;
  for (int i = 2; i <= sqrt(num); i++)
    if (num % i == 0)
      return false;
  return true;
}
bool is_soDau_le(int num) {
  while (num >= 10)
    num /= 10;
  return num % 2 == 1 ? true : false;
}
bool is_soHangChu_5(int num) {
  while (num >= 100)
    num /= 10;
  return num / 10 == 5 ? true : false;
}
// bai 1.1: liet ke cac gia tri chan
void lietKeGtriChan(int *arr, int n) {
  for (size_t i = 0; i < n; i++) {
    if (arr[i] % 2 == 0)
      printf("%d ", arr[i]);
  }
}
// bai 1.2: liet ke vi tri co gia tri am
void lietKeVtri_gtriAm(int *arr, int n) {
  for (size_t i = 0; i < n; i++) {
    if (arr[i] < 0)
      printf("%d ", i);
  }
}
// bai 1.3: tim gia tri lon nhat
int timGiaTri_max(int *arr, int n) {
  int flgMax = arr[0];
  for (size_t i = 1; i < n; i++)
    if (flgMax < arr[i])
      flgMax = arr[i];
  return flgMax;
}
// bai 1.4: tim gia tri duong dau tien (so thuc)
float timGiaTri_duongFirst(float *arr, int n) {
  for (size_t i = 0; i < n; i++)
    if (arr[i] > 0)
      return arr[i];
  return -1;
}
// bai 1.5: tim so chan cuoi cung
int timGiaTri_chanLast(int *arr, int n) {
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] % 2 == 0)
      return arr[i];
  }
  return -1;
}
// bai 1.6: tim vi tri so hoan thien nho nhat
int timVtri_SHT_min(int *arr, int n) {
  int i, index = -1;
  int flg_SHT_min;
  for (i = 0; i < n; i++) {
    if (isSHT(arr[i])) {
      index = i;
      flg_SHT_min = arr[i];
      break;
    }
  }

  for (; i < n; i++) {
    if (isSHT(arr[i]) && flg_SHT_min > arr[i]) {
      flg_SHT_min = arr[i];
      index = i;
    }
  }
  return index;
}
// bai 1.7: tim vi tri cua gia tri chan dau tien
int timVtri_chanFirst(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0)
      return i;
  }
  return -1;
}
// bai 1.8: tim vi tri so hoan thien cuoi cung
int timVtri_SHT_last(int *arr, int n) {
  for (int i = n - 1; i >= 0; i--) {
    if (isSHT(arr[i]))
      return i;
  }
  return -1;
}
// bai 1.9: tim gia tri duong nho nhat
float timGiatri_duongMin(float *arr, int n) {
  float flg_num_duong_min = -1;
  int i;
  for (i = 0; i < n; i++)
    if (arr[i] > 0) {
      flg_num_duong_min = arr[i];
      break;
    }
  for (; i < n; i++)
    if (flg_num_duong_min > arr[i] && arr[i] > 0)
      flg_num_duong_min = arr[i];
  return flg_num_duong_min;
}
// bai 1.10: tim SNT dau tien
int timGiaTri_SNTFirst(int *arr, int n) {
  for (int i = 0; i < n; i++)
    if (isSNT(arr[i]))
      return arr[i];
  return -1;
}
// bai 2.1: tinh tong cac ptu chu so dau la so le
int sum_ptu_soDau_le(int arr[MAXSIZE][MAXSIZE], int rows, int cols) {
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (is_soDau_le(abs(arr[i][j]))) {
        sum += arr[i][j];
        // printf("%d ", arr[i][j]);
      }
    }
  }
  return sum;
}
// bai 2.2: dem ptu co chu so hang chuc la 5
int count_ptu_soHangChuc_5(int arr[MAXSIZE][MAXSIZE], int rows, int cols) {
  int count = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (is_soHangChu_5(abs(arr[i][j]))) {
        count++;
        // printf("%d ", arr[i][j]);
      }
    }
  }
  return count;
}
// bai 2.3: liet ke cac so hoan thien
void lietKeGtri_SHT(int arr[MAXSIZE][MAXSIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (isSHT(arr[i][j]))
        printf("%d ", arr[i][j]);
}
// bai 2.4: tinh tong cac ptu lon hon TTD cua so sau no
int sum_ptu_lonHon_TTD_soSau(int arr[MAXSIZE][MAXSIZE], int rows, int cols) {
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols - 1; j++) {
      if (arr[i][j] > (abs(arr[i][j + 1]))) {
        sum += arr[i][j];
        printf("%d ", arr[i][j]);
      }
    }
  }
  return sum;
}
// bai 2.5: tinh tong gia tri tren 1 dong ma tran
// row <= rows
int sum_ptu_row(int arr[MAXSIZE][MAXSIZE], int rows, int cols, int row) {
  int sum = 0;
  for (int i = 0; i < cols; i++) {
    sum += arr[row][i];
  }
  return sum;
}
// bai 2.6: kiem tra ma tran toan duong
bool is_maTran_toanDuong(int arr[MAXSIZE][MAXSIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (arr[i][j] < 0)
        return false;
  return true;
}
// bai 2.7: tinh tong cac gia tri tren bien cua ma tran
int sum_ptu_cacBien(int arr[MAXSIZE][MAXSIZE], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[0][i];     // bien tren
    sum += arr[n - 1][i]; // bien duoi
  }
  for (int i = 1; i < n - 1; i++) {
    sum += arr[i][0];     // bien tren
    sum += arr[i][n - 1]; // bien duoi
  }
  return sum;
}
// bai 2.8: dem tan suat xuat hien cua ptu x trong mtran
int count_xuatHien_x(int arr[MAXSIZE][MAXSIZE], int n, int x) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == x) {
        count++;
        // printf("%d ", arr[i][j]);
      }
    }
  }
  return count;
}
// bai 2.9: tinh tong gtri duong tren 1 dong ma tran
int sum_ptu_duong_row(int arr[MAXSIZE][MAXSIZE], int n, int row) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[row][i] > 0)
      sum += arr[row][i];
  }
  return sum;
}
// bai 2.10: dem so luong "yen ngua"
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
int count_yenNgua(int arr[MAXSIZE][MAXSIZE], int n) {
  int flg_max_row, flg_min_col;
  int count = 0;
  int indexi, indexj;
  for (int i = 0; i < n; i++) {
    indexi = i;
    flg_max_row = arr[indexi][0];
    for (int j = 1; j < n; j++) {
      if (flg_max_row < arr[i][j]) {
        flg_max_row = arr[i][j];
        indexj = j;
      }
    }
    flg_min_col = arr[indexi][indexj];
    for (int k = 0; k < n; k++) {
      if (flg_min_col > arr[k][indexj]) {
        flg_min_col = arr[k][indexj];
        break;
      }
    }
    if (flg_min_col == arr[indexi][indexj])
      count++;
  }
  return count;
}
