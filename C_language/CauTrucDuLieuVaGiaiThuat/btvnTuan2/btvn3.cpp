#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
#define len(x) *(&x+1)-x
const char *separator = "/";
struct Date {
  int d, m, y;
};
struct HoTen {
  char ho[25], ten[20];
};
struct SinhVien {
  char ma[5];
  Date NgaySinh;
  HoTen hoTen;
  char DiaChi[50];
  char NganhHoc[10];
  float dtb;
};

void DocFile(SinhVien *sv, int &n);
void GhiFile(SinhVien *sv, int n);
void inThongTin(FILE *f, SinhVien sv);
void Xuat(SinhVien *sv, int n);
void XuatThongTin(SinhVien sv);
char *TinhDiemChu(SinhVien sv);
char *XepLoai(SinhVien sv);
void NhapDSThongTin(SinhVien *sv, int &n);
void NhapThongTin(SinhVien &sv);
int xacDinhThang(int m);
bool KiemTraNamNhuan(int y);
bool testDate(int d, int m, int y);
template <typename T>
void Swap(T &a, T &b);
int compare_Descending_DTB(const void* a, const void* b);
int compare_Ascending_HoTen(const void* a, const void* b);
int compare_Ascending_DiemChu(const void* a, const void* b);
void sortDescending_DTB(SinhVien *sv, int n);

int main()
{
  SinhVien sv[MAX];
  int n;
  size_t sizeof_SinhVien = sizeof(struct SinhVien);
  printf("doc file hoac nhap tu ban phim (1/2): ");
  scanf("%d", &n);
  if(n==1) DocFile(sv, n);
  else if (n==2) NhapDSThongTin(sv, n);
  else {
    printf("du lieu nhap sai\n");
    exit(1);
  }
  GhiFile(sv, n);
  Xuat(sv, n);
  printf("\nSap xep giam dan theo diem tb\n");
  qsort(sv, n, sizeof_SinhVien, compare_Descending_DTB);
  Xuat(sv, n);
  printf("\nSap xep tang dan theo ho ten\n");
  qsort(sv, n, sizeof_SinhVien, compare_Ascending_HoTen);
  Xuat(sv, n);
  printf("\nSap xep theo dieu kien de bai\n");
  qsort(sv, n, sizeof_SinhVien, compare_Ascending_DiemChu);
  sortDescending_DTB(sv, n);
  Xuat(sv, n);
  getch();
  return 0;
}
void sortDescending_DTB(SinhVien *sv, int n)
{
  for (size_t i = 0; i < n-1; i++) {
    for (size_t j = i+1; j < n; j++) {
      if (strcmpi(TinhDiemChu(sv[i]), TinhDiemChu(sv[j]))==0 && sv[i].dtb<sv[j].dtb) {
        Swap(sv[i], sv[j]);
      }
    }
  }
}
int compare_Ascending_DiemChu(const void* a, const void* b)
{
  SinhVien *sv1 = (SinhVien*)a;
  SinhVien *sv2 = (SinhVien*)b;
  return strcmpi(TinhDiemChu(*sv1), TinhDiemChu(*sv2));
}
int compare_Ascending_HoTen(const void *a, const void *b)
{
  const SinhVien *sv1 = (SinhVien*)a;
  const SinhVien *sv2 = (SinhVien*)b;

  return strcmpi(sv1->hoTen.ten, sv2->hoTen.ten);
}
int compare_Descending_DTB(const void* a, const void* b)
{
  if (((struct SinhVien*)a)->dtb > ((struct SinhVien*)b)->dtb) return -1;
  if (((struct SinhVien*)a)->dtb == ((struct SinhVien*)b)->dtb) return 0;
  if (((struct SinhVien*)a)->dtb < ((struct SinhVien*)b)->dtb) return 1;
}
void inThongTin(FILE *f, SinhVien sv)
{
  fprintf(f, "%4s %12s %s %4d/%2d/%d %22s %8s %8.1f %7s%7s%s\n", \
          sv.ma, sv.hoTen.ho, sv.hoTen.ten, sv.NgaySinh.d, sv.NgaySinh.m, sv.NgaySinh.y, sv.DiaChi, sv.NganhHoc, sv.dtb, TinhDiemChu(sv), " ", XepLoai(sv)\
        );
}
void GhiFile(SinhVien *sv, int n)
{
  FILE *f = fopen("output3.txt", "w");
  fprintf(f, "%4s %13s %14s %18s %15s %5s %10s %10s\n", \
          "MSSV", "Ho Ten", "Ngay Sinh", "Dia Chi", "Nganh Hoc", "Dtb", "Diem Chu", "Xep Loai"\
        );
  for (size_t i = 0; i < 100; i++) {
    fprintf(f, "%c", '-');
  }
  fprintf(f, "%c", '\n');
  for (size_t i = 0; i < n; i++) {
    inThongTin(f, sv[i]);
  }
  fclose(f);
}
void XuatThongTin(SinhVien sv)
{
  printf("%4s %12s %s %4d/%2d/%d %22s %8s %8.1f %7s\t  %s\n", \
          sv.ma, sv.hoTen.ho, sv.hoTen.ten, sv.NgaySinh.d, sv.NgaySinh.m, sv.NgaySinh.y, sv.DiaChi, sv.NganhHoc, sv.dtb, TinhDiemChu(sv), XepLoai(sv)\
        );
}
void Xuat(SinhVien *sv, int n)
{
  printf("Thong Tin Sinh Vien\n");
  printf("%4s %13s %14s %18s %15s %5s %10s %10s\n", \
          "MSSV", "Ho Ten", "Ngay Sinh", "Dia Chi", "Nganh Hoc", "Dtb", "Diem Chu", "Xep Loai"\
        );
  for (size_t i = 0; i < 100; i++) {
    printf("-");
  }
  printf("\n");
  for (size_t i = 0; i < n; i++) {
    XuatThongTin(sv[i]);
  }
}
void DocFile(SinhVien *sv, int &n)
{
  FILE *f;
  char t[2];
  char hoten[50];
  char *p;
  if((f=fopen("input3.txt", "r"))==NULL)
  {
    printf("Error\n");
    exit(1);
  }
  fscanf(f, "%d", &n);
  fscanf(f, "%c", &t);
  for (size_t i = 0; i < n; i++) {
    size_t tmp=0;
    fgets(sv[i].ma, 6, f);
    sv[i].ma[strlen(sv[i].ma)-1] = '\0';
    fscanf(f, "%d", &sv[i].NgaySinh.d);
    fscanf(f, "%c", &t);
    fscanf(f, "%d", &sv[i].NgaySinh.m);
    fscanf(f, "%c", &t);
    fscanf(f, "%d", &sv[i].NgaySinh.y);
    fscanf(f, "%c", &t);
    fgets(hoten, 51, f);
    hoten[strlen(hoten)-1] = '\0';
    strrev(hoten);
    int i_ten = strcspn(hoten, " ");
    for (size_t j = strlen(hoten)-1; j > i_ten; j--) {
      sv[i].hoTen.ho[tmp++] = hoten[j];
    }
    sv[i].hoTen.ho[tmp] = '\0';
    p = strtok(hoten, " ");
    strcpy(hoten, p);
    strcpy(sv[i].hoTen.ten, strrev(hoten));
    fgets(sv[i].DiaChi, 51, f);
    sv[i].DiaChi[strlen(sv[i].DiaChi)-1] = '\0';
    fgets(sv[i].NganhHoc, 11, f);
    sv[i].NganhHoc[strlen(sv[i].NganhHoc)-1] = '\0';
    fscanf(f, "%f", &sv[i].dtb);
    fscanf(f, "%c", &t);
  }
}
char * TinhDiemChu(SinhVien sv)
{
	if (sv.dtb>=8.5) return "A";
	else if (sv.dtb >= 8) return "B+";
	else if (sv.dtb >= 7) return "B";
	else if (sv.dtb >= 6.5) return "C+";
	else if (sv.dtb >= 5.5) return "C";
	else if (sv.dtb >= 5) return "D+";
	else if (sv.dtb >= 4) return "D";
	else return "F";
}
char * XepLoai(SinhVien sv)
{
	if (sv.dtb>=8.5) return "Gioi";
	else if (sv.dtb >= 7) return "Kha";
	else if (sv.dtb >= 5.5) return "Trung Binh";
	else if (sv.dtb >= 4) return "Trung Binh Yeu";
	else return "Kem";
}
void NhapThongTin(SinhVien &sv)
{
  char tmp[15];
  printf("mssv: ");
  scanf("%s", sv.ma);
  // printf("Ho ten: ");
  // scanf("%s", sv.HoTen);
  do {
    printf("Nganh Sinh(d/m/y): ");
    scanf("%s", tmp);
    char *token = strtok(tmp, separator);
    sv.NgaySinh.d = atoi(token);
    token = strtok(NULL, separator);
    if(token==NULL)
    {
      sv.NgaySinh.m = 0;
      sv.NgaySinh.y = 2000;
	  continue;
    }
    sv.NgaySinh.m = atoi(token);
    token = strtok(NULL, separator);
    if(token==NULL)
    {
      sv.NgaySinh.m = 0;
      sv.NgaySinh.y = 2000;
	  continue;
    }
    sv.NgaySinh.y = atoi(token);
  } while(!testDate(sv.NgaySinh.d, sv.NgaySinh.m, sv.NgaySinh.y));
  printf("Dia chi(quan/huyen, thanh pho): ");
  scanf("%s", sv.DiaChi);
  printf("Nganh hoc: ");
  scanf("%s", sv.NganhHoc);
  do {
    printf("Dtb : ");
    scanf("%f", &sv.dtb);
    if (sv.dtb<0 || sv.dtb>10) {
      printf("\nMoi Nhap Lai\n");
    }
  } while(sv.dtb<0 || sv.dtb>10);
}
void NhapDSThongTin(SinhVien *sv, int &n)
{
  do {
    printf("Nhap so luong mat hang: ");
    scanf("%d", &n);
  } while(n<1||n>MAX);
  for (size_t i = 0; i < n; i++) {
    NhapThongTin(sv[i]);
  }
}

int xacDinhThang(int m)
{
  switch (m) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 1;
    case 4: case 6: case 9: case 11: return 0;
    case 2: return 2;
	default: return -1;
  }
}
bool KiemTraNamNhuan(int y)
{
  if (y%400==0 || y%4==0 && y%100!=0) {
    return true;
  }
  return false;
}
bool testDate(int d, int m, int y)
{
  int d_[] = {0, 28, 29, 30, 31};
  int m_ = xacDinhThang(m);
  if (\
      (m_==1 && d>d_[0] && d<=d_[len(d_)-1]) ||\
      (m_==2 && d>d_[0] && d<=d_[1]) || \
      (m_==0 && d>d_[0] && d<=d_[len(d_)-2])\
    ) {
    return true;
  }
  if (KiemTraNamNhuan(y)) {
    if (m_==2 && d>d_[0] && d<=d_[2]) {
      return true;
    }
  }
  printf("\nXin Moi Nhap Lai\n");
  return false;
}
template <typename T>
void Swap(T &a, T &b){
  T t = a;
  a = b;
  b = t;
}
