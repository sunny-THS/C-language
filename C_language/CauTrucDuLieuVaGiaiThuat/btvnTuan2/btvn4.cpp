#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 14
#define len(x) *(&x+1)-x
#define limit 5
const char* datenow = "2/2019";
const char *separator = "/";

struct Date {
  int ngay, thang, nam;
};
struct HangHoa {
  char ma[5];
  char ten[20];
  float gia; //
  Date nsx; //
  int hsd; //
  int slTonKho; //
};
void DocFile(HangHoa *hh, int &n);
void GhiFile(HangHoa *hh, int n);
void inThongTin(FILE *f, HangHoa hh);
void xuatThongTin(HangHoa hh);
void xuatDSThongTin(HangHoa* hh, int n);
void NhapThongTin(HangHoa &hh);
void NhapDSThongTin(HangHoa *hh, int &n);
void XuatDSHangHoaHetHan(HangHoa *hh, int n);
bool testDate(int d, int m, int y);
int xacDinhThang(int m);
bool KiemTraNamNhuan(int y);
template <typename T>
void swap(T &a, T &b);
void sortAscending_NSX(HangHoa *hh, int n);
void sortDescending_SLTONKHO(HangHoa *hh, int);
void sortAscending_HSD(HangHoa *hh, int);
void sapXepTheoDeBai(HangHoa *hh, int n);

int main()
{
  HangHoa hh[MAX];
  int n;
  printf("doc file hoac nhap tu ban phim (1/2): ");
  scanf("%d", &n);
  if(n==1) DocFile(hh, n);
  else if (n==2) NhapDSThongTin(hh, n);
  else {
    printf("du lieu nhap sai\n");
    exit(1);
  }
  xuatDSThongTin(hh, n);
  GhiFile(hh, n);
  printf("\nSap xep tang dan theo nsx\n");
  sortAscending_NSX(hh, n);
  xuatDSThongTin(hh, n);
  printf("\nSap xep giam dan theo so luong ton kho\n");
  sortDescending_SLTONKHO(hh, n);
  xuatDSThongTin(hh, n);
  printf("\nSap xep theo de bai\n");
  sapXepTheoDeBai(hh, n);
  xuatDSThongTin(hh, n);
  getch();
  return 1;
}

void DocFile(HangHoa *hh, int &n)
{
  FILE *f;
  char tmp[2];
  if((f=fopen("input4.txt", "r"))==NULL)
  {
    printf("ERROR\n");
    exit(1);
  }
  fscanf(f, "%d", &n);
  for (size_t i = 0; i < n; i++)
  {
    fscanf(f, "%s", &hh[i].ma);
    fscanf(f, "%s", &hh[i].ten);
    fscanf(f, "%f", &hh[i].gia);
    fscanf(f, "%d", &hh[i].nsx.ngay);
    fscanf(f, "%c", &tmp);
    fscanf(f, "%d", &hh[i].nsx.thang);
    fscanf(f, "%c", &tmp);
    fscanf(f, "%d", &hh[i].nsx.nam);
    fscanf(f, "%d", &hh[i].hsd);
    fscanf(f, "%d", &hh[i].slTonKho);
  }
  fclose(f);
}
void NhapThongTin(HangHoa &hh)
{
  char tmp[15];
  printf("ma hang hoa: ");
  scanf("%s", &hh.ma);
  printf("ten hang hoa: ");
  scanf("%s", &hh.ten);
  printf("gia hang hoa: ");
  scanf("%f", &hh.gia);
  do {
    printf("NSX(d/m/y): ");
    scanf("%s", &tmp);
    char *token = strtok(tmp, separator);
    hh.nsx.ngay = atoi(token);
    token = strtok(NULL, separator);
    if(token==NULL)
    {
      hh.nsx.thang = 0;
      hh.nsx.nam = 2000;
	  continue;
    }
    hh.nsx.thang = atoi(token);
    token = strtok(NULL, separator);
    if(token==NULL)
    {
      hh.nsx.thang = 0;
      hh.nsx.nam = 2000;
	  continue;
    }
    hh.nsx.nam = atoi(token);
  } while(!testDate(hh.nsx.ngay, hh.nsx.thang, hh.nsx.nam));
  printf("HSD: ");
  scanf("%d", &hh.hsd);
  printf("so luong hang ton kho: ");
  scanf("%d", &hh.slTonKho);
}
void NhapDSThongTin(HangHoa *hh, int &n)
{
  do {
    printf("Nhap so luong mat hang: ");
    scanf("%d", &n);
  } while(n<1||n>MAX);
  for (size_t i = 0; i < n; i++) {
    NhapThongTin(hh[i]);
  }
}
void xuatThongTin(HangHoa hh)
{
  printf("%s\t-- %20s\t-- %4.0f,000vnd\t-- %2d/%2d/%4d(NSX)\t-- %2d thang(HSD)\t-- sl ton kho:%3d\n", hh.ma, hh.ten, hh.gia, hh.nsx.ngay, hh.nsx.thang, hh.nsx.nam, hh.hsd, hh.slTonKho);
}
void inThongTin(FILE *f, HangHoa hh)
{
  fprintf(f, "%s  -- %s\n\tGia: %.2f\n\tNSX: %d/%d/%d\n\tHSD: %d thang\n\tSL ton kho: %d\n\n", hh.ma, hh.ten, hh.gia, hh.nsx.ngay, hh.nsx.thang, hh.nsx.nam, hh.hsd, hh.slTonKho);
}
void xuatDSThongTin(HangHoa *hh, int n)
{
  printf("Danh sach hang hoa\n");
  for (size_t i = 0; i < n; i++) {
    xuatThongTin(hh[i]);
  }
}
void GhiFile(HangHoa *hh, int n)
{
  FILE *f = fopen("output4.txt", "w");
  fprintf(f, "So mat hang: %d\n", n);
  for (size_t i = 0; i < n; i++) {
    inThongTin(f, hh[i]);
  }
  fclose(f);
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
void swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}
void sortAscending_NSX(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n-1; i++) {
    bool swapped = false;
    for (size_t j = i+1; j < n; j++) {
      if (hh[i].nsx.nam>hh[j].nsx.nam) {
        swap(hh[i], hh[j]);
        swapped = true;
      }else if (hh[i].nsx.nam==hh[j].nsx.nam) {
        if (hh[i].nsx.thang>hh[j].nsx.thang) {
          swap(hh[i], hh[j]);
          swapped = true;
        }else if (hh[i].nsx.thang==hh[j].nsx.thang) {
          if (hh[i].nsx.ngay>hh[j].nsx.ngay) {
            swap(hh[i], hh[j]);
            swapped = true;
          }
        }
      }
    }
    if (!swapped) return;
  }
}
void sortDescending_SLTONKHO(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n-1; i++) {
    bool swapped = false;
    for (size_t j = i+1; j < n; j++) {
      if(hh[i].slTonKho < hh[j].slTonKho)
      {
        swap(hh[i], hh[j]);
        swapped = true;
      }
    }
    if (!swapped) return;
  }
}
void sortAscending_HSD(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n-1; i++) {
    bool swapped = false;
    for (size_t j = i+1; j < n; j++) {
      if(hh[i].hsd > hh[j].hsd)
      {
        swap(hh[i], hh[j]);
        swapped = true;
      }
    }
    if (!swapped) return;
  }
}
void sapXepTheoDeBai(HangHoa *hh, int n)
{
  sortAscending_HSD(hh, n);
  for (size_t i = 0; i < n-1; i++) {
    for (size_t j = i+1; j < n; j++) {
      if(hh[i].hsd == hh[j].hsd)
      {
        if (hh[i].nsx.nam>hh[j].nsx.nam) {
          swap(hh[i], hh[j]);
        }else if (hh[i].nsx.nam==hh[j].nsx.nam) {
          if (hh[i].nsx.thang>hh[j].nsx.thang) {
            swap(hh[i], hh[j]);
          }else if (hh[i].nsx.thang==hh[j].nsx.thang) {
            if (hh[i].nsx.ngay>hh[j].nsx.ngay) {
              swap(hh[i], hh[j]);
            }
          }
        }
      }
    }
  }
}
