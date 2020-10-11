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
void XuatThongTinHHGanHet(HangHoa hh);
void XuatDSThongTinHHGanHet(HangHoa *hh, int n);
int demSLhangTheoTen(HangHoa *hh, int n, char *ten);
void sapXepHSD(HangHoa *hh, int n);
void sapXepTen(HangHoa *hh, int n);
void sapXepTonKho(HangHoa *hh, int n);
int demSLmatHang(HangHoa *hh, int n);
void hangCoGia40(HangHoa *hh, int n);
int demSoHangMoiSx(HangHoa *hh, int n);
void inDScacMatHang(HangHoa *hh, int n);
void inDSsoHangHoaMoiSX(HangHoa *hh, int n);
void inTheoTenHang(HangHoa *hh, int n, char *ten);
void xuatMatHangCoHSD_2_3Y(HangHoa *hh, int n);
void XoaMatHangHetHan(HangHoa *hh, int &n);
bool HetHSD(HangHoa hh);
void them1HangHoa(HangHoa *hh, int &n);
HangHoa soLuongTonKho_Max(HangHoa *hh, int n);
HangHoa soLuongTonKho_no2(HangHoa *hh, int n);

template <typename T>
void swap(T &a, T &b);

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
  XuatDSHangHoaHetHan(hh, n);
  XuatDSThongTinHHGanHet(hh, n);
  printf("\nSo luong hang chua ten \"BanhDanisa\": %d\n", demSLhangTheoTen(hh, n, "BanhDanisa"));
  inTheoTenHang(hh, n, "BanhDanisa");
  printf("\nSap xep theo hsd (han gan den xa)\n");
  sapXepHSD(hh, n);
  xuatDSThongTin(hh, n);
  size_t slMatHang = demSLmatHang(hh, n);
  if (slMatHang!=-1)
  {
    printf("\nso luong mat hang: %d\n", slMatHang);
    inDScacMatHang(hh, n);
  }
  else printf("\nKhong co mat hang nao\n");
  printf("\ncac mat hang co gia ban 40,000\n");
  hangCoGia40(hh, n);
  printf("\nTong so hang hoa moi sx: %d\n", demSoHangMoiSx(hh, n));
  inDSsoHangHoaMoiSX(hh, n);
  printf("\nCac mat hang  co han su dung tu 2 den 3 nam\n");
  xuatMatHangCoHSD_2_3Y(hh, n);
  XoaMatHangHetHan(hh, n);
  printf("\nXoa hang hoa het han\n");
  xuatDSThongTin(hh, n);
  printf("\n");
  them1HangHoa(hh, n);
  xuatDSThongTin(hh, n);
  printf("\nMat hang co so luong ton kho nhieu nhat\n");
  xuatThongTin(soLuongTonKho_Max(hh, n));
  printf("\nMat hang co so luong ton kho nhieu thu 2\n");
  xuatThongTin(soLuongTonKho_no2(hh, n));
  getch();
  return 1;
}

void DocFile(HangHoa *hh, int &n)
{
  FILE *f;
  char tmp[2];
  if((f=fopen("input.txt", "r"))==NULL)
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
  char *separator = "/";
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
    hh.nsx.thang = atoi(token);
    token = strtok(NULL, separator);
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
  FILE *f = fopen("output.txt", "w");
  fprintf(f, "So mat hang: %d\n", n);
  for (size_t i = 0; i < n; i++) {
    inThongTin(f, hh[i]);
  }
  fclose(f);
}
bool HetHSD(HangHoa hh)
{
  char date[7];
  strcpy(date, datenow);
  char *token = strtok(date, separator);
  int thang = atoi(token);
  token = strtok(0, separator);
  int nam = atoi(token);
  int tmp_m, tmp_y;
  if (hh.hsd + hh.nsx.thang > 12)
  {
    tmp_m = (hh.hsd + hh.nsx.thang)%12;
    tmp_y = hh.nsx.nam + 1;
  }else {
    tmp_m = hh.hsd + hh.nsx.thang;
    tmp_y = hh.nsx.nam;
  }
  if(nam > tmp_y || nam >= tmp_y && thang >= tmp_m) return true;
  return false;
}

void XuatDSHangHoaHetHan(HangHoa *hh, int n)
{
  printf("\nDanh sach hang hoa het han(tinh tai thoi diem thang 2/2019)\n");
  for (size_t i = 0; i < n; i++) {
    if(HetHSD(hh[i])) xuatThongTin(hh[i]);
  }
}
int xacDinhThang(int m)
{
  switch (m) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 1;
    case 4: case 6: case 9: case 11: return 0;
    case 2: return 2;
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
void XuatThongTinHHGanHet(HangHoa hh)
{
  if (hh.slTonKho < limit)
  {
    xuatThongTin(hh);
  }
}
void XuatDSThongTinHHGanHet(HangHoa *hh, int n)
{
  printf("\nThong tin hang hoa sap het\n");
  for (size_t i = 0; i < n; i++) {
    XuatThongTinHHGanHet(hh[i]);
  }
}
int demSLhangTheoTen(HangHoa *hh, int n, char *ten)
{
  size_t d = 0;
  for (size_t i = 0; i < n; i++) {
    if (strstr(hh[i].ten, ten) != NULL) d++;
  }
  return d;
}
void inTheoTenHang(HangHoa *hh, int n, char *ten)
{
  size_t d = 1;
  for (size_t i = 0; i < n; i++) {
    if (strstr(hh[i].ten, ten) != NULL) printf("%d. %s\n", d++, hh[i].ten);
  }
}
void sapXepHSD(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n-1; i++) {
    bool swapped_ = false;
    for (size_t j = 0; j < n-i-1; j++) {
      if(hh[j].hsd > hh[j+1].hsd) {
        swap(hh[j], hh[j+1]);
        swapped_ = true;
      }
    }
    if(!swapped_) break;
  }
}
template <typename T>
void swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}
void sapXepTen(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n-1; i++) {
    bool swapped_ = false;
    for (size_t j = 0; j < n-i-1; j++) {
      if(strcmpi(hh[j].ten, hh[j+1].ten)==1) {
        swap(hh[j], hh[j+1]);
        swapped_ = true;
      }
    }
    if(!swapped_) break;
  }
}
void sapXepTonKho(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n-1; i++) {
    bool swapped_ = false;
    for (size_t j = 0; j < n-i-1; j++) {
      if(hh[j].slTonKho > hh[j+1].slTonKho) {
        swap(hh[j], hh[j+1]);
        swapped_ = true;
      }
    }
    if(!swapped_) break;
  }
}
int demSLmatHang(HangHoa *hh, int n)
{
  if(n<1) return -1;
  sapXepTen(hh, n);
  size_t d = 1;
  for (size_t i = 0; i < n-1; i++)
  {
    char *tmp1 = strtok(hh[i].ten, "-");
    char *tmp2 = strtok(hh[i+1].ten, "-");
    if (strcmpi(tmp1, tmp2)!=0) d++;
  }
  return d;
}

void hangCoGia40(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n; i++) {
    if(hh[i].gia == 40)
      xuatThongTin(hh[i]);
  }
}
int demSoHangMoiSx(HangHoa *hh, int n)
{
  char date[7];
  strcpy(date, datenow);
  char *token = strtok(date, separator);
  int thang = atoi(token);
  token = strtok(0, separator);
  int nam = atoi(token);
  size_t d = 0;
  for (size_t i = 0; i < n; i++) {
    if(hh[i].nsx.thang == thang && hh[i].nsx.nam == nam) d++;
  }
  return d;
}
void inDScacMatHang(HangHoa *hh, int n)
{
  if(n<1) return;
  sapXepTen(hh, n);
  size_t d = 1;
  for (size_t i = 0; i < n; i++)
  {
    char *tmp1 = strtok(hh[i].ten, "-");
    char *tmp2 = strtok(hh[i+1].ten, "-");
    if (strcmpi(tmp1, tmp2)!=0) printf("%d. %s\n", d++, tmp1);
  }
}
void inDSsoHangHoaMoiSX(HangHoa *hh, int n)
{
  char date[7];
  strcpy(date, datenow);
  char *token = strtok(date, separator);
  int thang = atoi(token);
  token = strtok(0, separator);
  int nam = atoi(token);
  for (size_t i = 0; i < n; i++) {
    if(hh[i].nsx.thang == thang && hh[i].nsx.nam == nam) xuatThongTin(hh[i]);
  }
}
void xuatMatHangCoHSD_2_3Y(HangHoa *hh, int n)
{
  for (size_t i = 0; i < n; i++) {
    if(hh[i].hsd >= 24 && hh[i].hsd <= 36) xuatThongTin(hh[i]);
  }
}
void XoaMatHangHetHan(HangHoa *hh, int &n)
{
  for (size_t i = 0; i < n; i++) {
    if (HetHSD(hh[i])) {
      for (size_t j = i+1; j < n; j++) {
        swap(hh[j], hh[j-1]);
      }
      n--;
    }
  }
}
void them1HangHoa(HangHoa *hh, int &n)
{
  n++;
  printf("Them 1 hang hoa moi\n");
  NhapThongTin(hh[n-1]);
}
HangHoa soLuongTonKho_Max(HangHoa *hh, int n)
{
  sapXepTonKho(hh, n);
  return hh[n-1];
}
HangHoa soLuongTonKho_no2(HangHoa *hh, int n)
{
  sapXepTonKho(hh, n);
  return hh[n-2];
}
