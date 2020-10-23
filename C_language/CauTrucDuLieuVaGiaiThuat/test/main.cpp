#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define len(x) (*x+1)-x
struct Date {
  int d, m, y;
};
struct SinhVien {
  char mssv[5];
  Date ngaySinh;
  char ho[30];
  char ten[10];
  char diadiem[50];
  char khoa[10];
  float dtb;
};

void menu(SinhVien *sv, int &n);
void DocFile(SinhVien *sv, int &n);
void xuatThongTin(SinhVien sv);
void xuat(SinhVien *sv, int n);
void QuickSort(SinhVien *sv, int l, int r, bool(* compare)(const void *, const void *));
bool compare_HoTen_asc(const void *, const void *);
template <typename T>
void swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}

int main()
{
  SinhVien sv[15];
  int n;
  menu(sv, n);
  getch();
  return 0;
}
bool compare_HoTen_asc(const void *a, const void *b)
{
  const SinhVien *sv1 = (SinhVien*)a;
  const SinhVien *sv2 = (SinhVien*)b;

  if(strcmpi(sv1->ten, sv2->ten)>0) return true;
  else if(strcmpi(sv1->ten, sv2->ten)==0)
  {
    if(strcmpi(sv1->ho, sv2->ho)>0) return true;
  }
  return false;
}

void menu(SinhVien *sv, int &n){
  size_t chon;
  do {
    printf("1. Doc ghi file va xuat\n");
    printf("2. Sap xep ho ten\n");
    printf("0. Thoat\n");
    printf("Chon: ");
    scanf("%d", &chon);
    switch (chon) {
      case 0: exit(1); break;
      case 1:
      {
        DocFile(sv, n);
        xuat(sv, n);
      } break;
      case 2:
      {
        QuickSort(sv, 0, n-1, compare_HoTen_asc);
        xuat(sv, n);
      } break;
      default: printf("Khong tim thay du lieu moi nhap lai\n");
    }
  } while(chon!=0);
}
void xuatThongTin(SinhVien sv)
{
  printf("%4s %10d/%2d/%d %15s %s %30s %10s %8.1f\n", \
  sv.mssv, sv.ngaySinh.d, sv.ngaySinh.m, sv.ngaySinh.y, sv.ho, sv.ten, sv.diadiem, sv.khoa, sv.dtb);
}
void xuat(SinhVien *sv, int n)
{
  printf("Thong tin sinh vien\n");
  printf("%2s %15s %15s %30s %15s %8s\n", \
        "mssv", "ngaysinh", "hoten", "diachi", "khoa", "dtb"
  );
  for (size_t i = 0; i < n; i++) {
    xuatThongTin(sv[i]);
  }
}
void DocFile(SinhVien *sv, int &n)
{
  FILE *f;
  char c[2];
  char hoten[50];
  if(!(f=fopen("input.txt", "r")))
  {
    printf("ERROR\n");
    getch();
    exit(1);
  }
  fscanf(f, "%d", &n);
  fscanf(f, "%c", &c);
  for (size_t i = 0; i < n; i++) {
    int d = 0;
    fscanf(f, "%s", sv[i].mssv);
    fscanf(f, "%d", &sv[i].ngaySinh.d);
    fscanf(f, "%c", &c);
    fscanf(f, "%d", &sv[i].ngaySinh.m);
    fscanf(f, "%c", &c);
    fscanf(f, "%d", &sv[i].ngaySinh.y);
    fscanf(f, "%c", &c);
    fgets(hoten, 51, f);
    hoten[strlen(hoten)-1] = '\0';
    strrev(hoten);
    int tmp = strspn(hoten, " ");
    for (size_t j = strlen(hoten)-1; j > tmp; j--) {
      sv[i].ho[d++] = hoten[j];
    }
    sv[i].ho[d-1] = '\0';
    char *t = strtok(hoten, " ");
    strcpy(sv[i].ten, strrev(t));
    fgets(sv[i].diadiem, 51, f);
    sv[i].diadiem[strlen(sv[i].diadiem)-1] = '\0';
    fgets(sv[i].khoa, 11, f);
    sv[i].khoa[strlen(sv[i].khoa)-1] = '\0';
    fscanf(f, "%f", &sv[i].dtb);
  }
}
void QuickSort(SinhVien *sv, int l, int r, bool(* compare)(const void *, const void *))
{
  if(l>=r) return;
  int mid = (l+r)/2;
  int i = l;
  int j = r;
  SinhVien x = sv[mid];
  do {
    while (compare(&x, &sv[i])) i++;
    while (compare(&sv[j], &x)) j--;
    if (i<=j) {
      swap(sv[j], sv[i]);
      i++;j--;
    }
  } while(i<j);
  QuickSort(sv, l, j, compare);
  QuickSort(sv, i, r, compare);
}
