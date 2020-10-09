#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12
#define DATENOW "2/2019"
struct Date {
  int ngay, thang, nam;
};
struct HangHoa {
  char ma[5];
  char ten[20];
  float gia; // chia 1000
  Date nsx; // ngày sử dụng
  int hsd; // hạn sử dụng
  int slTonKho; // số lượng tồn kho
};
void DocFile(HangHoa *hh, int &n);
void GhiFile(HangHoa *hh, int n);
void inThongTin(FILE *f, HangHoa hh);
void xuatThongTin(HangHoa hh);
void xuatDSThongTin(HangHoa* hh, int n);
void NhapThongTin(HangHoa &hh);
void NhapDSThongTin(HangHoa *hh, int &n);
HangHoa HangHoaHetHan(HangHoa hh);

int main()
{
  HangHoa hh[MAX];
  int n;
  // DocFile(hh, n);
  NhapDSThongTin(hh, n);
  xuatDSThongTin(hh, n);
  GhiFile(hh, n);
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
  printf("NSX: ");
  scanf("%s", &tmp);
  char *token = strtok(tmp, separator);
  hh.nsx.ngay = atoi(token);
  token = strtok(NULL, separator);
  hh.nsx.thang = atoi(token);
  token = strtok(NULL, separator);
  hh.nsx.nam = atoi(token);
  printf("HSD: ");
  scanf("%d", &hh.hsd);
  printf("so luong hang ton kho: ");
  scanf("%d", &hh.slTonKho);
}
void NhapDSThongTin(HangHoa *hh, int &n)
{
  do {
    /* code */
  } while(n<1&&n>MAX);
  printf("Nhap so luong mat hang: ");
  scanf("%d", &n);
  for (size_t i = 0; i < n; i++) {
    NhapThongTin(hh[i]);
  }
}
void xuatThongTin(HangHoa hh)
{
  printf("%s\t-- %s\t-- %.0f000vnd\t-- %d/%d/%d(NSX)\t-- %d thang(HSD)\t-- sl ton kho:%3d\n", hh.ma, hh.ten, hh.gia, hh.nsx.ngay, hh.nsx.thang, hh.nsx.nam, hh.hsd, hh.slTonKho);
}
void inThongTin(FILE *f, HangHoa hh)
{
  fprintf(f, "%s  -- %s\n\tGia: %.2f\n\tNSX: %d/%d/%d\n\tHSD: %d\n\tSL ton kho: %d\n\n", hh.ma, hh.ten, hh.gia, hh.nsx.ngay, hh.nsx.thang, hh.nsx.nam, hh.hsd, hh.slTonKho);
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
HangHoa HangHoaHetHan(HangHoa hh)
{
  char *token = strtok(tmp, separator);
  int thang = atoi(token);
  token = strtok(NULL, separator);
  int nam = atoi(token);
  if(hh.nsx.thang-thang==0)
}
