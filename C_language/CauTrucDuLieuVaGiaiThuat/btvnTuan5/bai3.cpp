#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#define D_MH(dtl, dck) (0.3*dtl + 0.7*dck) // tinh diem mon hoc

struct MonHoc {
  char maMH[10], ten[30];
  int soTC;
  float dtl, dck;
  float diemMH;
};
struct SNode_MonHoc {
  MonHoc info;
  SNode_MonHoc *next;
};
struct Slist_MonHoc {
  SNode_MonHoc *head;
  SNode_MonHoc *tail;
};
struct SinhVien {
  char mssv[10], hodem[25], ten[8];
  int namSinh;
  float diemKQ;
  Slist_MonHoc dsMH;
};
struct SNode_SinhVien {
  SinhVien info;
  SNode_SinhVien *next;
};
struct Slist_SinhVien {
  SNode_SinhVien *head;
  SNode_SinhVien *tail;
};
template <typename Slist>
void KhoiTao(Slist &sl)
{
  sl.head = sl.tail = NULL;
}
template <typename ItemType, typename Node>
Node *TaoNut(ItemType x)
{
  Node *pNode = new Node;
  if (!pNode)
  {
    printf("Khong du dung luong\n");
    return NULL;
  }
  pNode->info = x;
  pNode->next = NULL;
  return pNode;
}
template <typename Slist, typename Node>
bool themCuoi(Slist &sl, Node *pNode)
{
  if (!pNode) return false;
  if (!sl.head) sl.head = sl.tail = pNode;
  else {
    sl.tail->next = pNode;
    sl.tail = pNode;
  }
  return true;
}
float TinhDiemKQ(Slist_MonHoc mh)
{
  SNode_MonHoc *pNode = mh.head;
  size_t d = 0;
  float diem = 0.0;
  while (pNode) {
    diem += pNode->info.diemMH;
    d++;
    pNode = pNode->next;
  }
  diem /= d;
  return diem;
}
void taoSlist_SV(Slist_SinhVien &sl)
{
  KhoiTao(sl);
  FILE *f;
  SinhVien sv;
  MonHoc mh;
  size_t len_SinhVien, len_MonHoc;

  if (!(f=fopen("input3.txt", "r")))
  {
    printf("Error\n");
    exit(1);
  }
  fscanf(f, "%d\n", &len_SinhVien);
  for (size_t i = 0; i < len_SinhVien; i++) {
    fscanf(f, "%[^\n]%*c\n", sv.mssv);
    fscanf(f, "%[^\n]%*c\n", sv.hodem);
    fscanf(f, "%[^\n]%*c\n", sv.ten);
    fscanf(f, "%d\n", &sv.namSinh);
    KhoiTao(sv.dsMH); // khoi tao lai ds mon hoc cho tung sinh vien
    fscanf(f, "%d\n", &len_MonHoc);
    for (size_t j = 0; j < len_MonHoc; j++) {
      fscanf(f, "%[^\n]%*c\n", mh.maMH);
      fscanf(f, "%[^\n]%*c\n", mh.ten);
      fscanf(f, "%d\n", &mh.soTC);
      fscanf(f, "%f\n", &mh.dtl);
      fscanf(f, "%f\n", &mh.dck);
      mh.diemMH = D_MH(mh.dtl, mh.dck);
      themCuoi(sv.dsMH, TaoNut<MonHoc, SNode_MonHoc>(mh));
    }
    sv.diemKQ = TinhDiemKQ(sv.dsMH);
    themCuoi(sl, TaoNut<SinhVien, SNode_SinhVien>(sv));
  }
}
void XuatMH(SNode_MonHoc *mh) {
  printf("\n%s -- %s\n", mh->info.maMH, mh->info.ten);
  printf("TC: %d\n", mh->info.soTC);
  printf("DTL: %.2f -- DCK: %.2f\n", mh->info.dtl, mh->info.dck);
  printf("Tong Diem: %.2f\n", mh->info.diemMH);
}
void XuatSV(SNode_SinhVien *sv)
{
  printf("\n%10s", sv->info.mssv);
  printf("%20s ", sv->info.hodem);
  printf("%s", sv->info.ten);
  printf("%10d\t", sv->info.namSinh);
  printf("|%10.2f\n", sv->info.diemKQ);
  SNode_MonHoc *mh = sv->info.dsMH.head;
  while (mh) {
    XuatMH(mh);
    mh = mh->next;
  }
}
void XuatDsSv(Slist_SinhVien sl)
{
  printf("Thong Tin cac sv\n");
  printf("\n-----------------------------------------------------------------------------------\n");
  SNode_SinhVien *pNode = sl.head;
  if (!pNode) {
    printf("Danh sach rong\n");
    return;
  }
  while (pNode) {
    XuatSV(pNode);
    printf("\n-----------------------------------------------------------------------------------\n");
    pNode = pNode->next;
  }
}
Slist_SinhVien TimSv(Slist_SinhVien sl, char *ten)
{
  Slist_SinhVien sl_new;
  KhoiTao(sl_new);
  SNode_SinhVien *pNode = sl.head;
  size_t d = 0;
  while (pNode) {
    if (strcmpi(pNode->info.ten, ten)==0)
    {
      themCuoi(sl_new, TaoNut<SinhVien, SNode_SinhVien>(pNode->info));
      d++;
    }
    pNode = pNode->next;
  }
  printf("Tim thay %d sinh vien\n", d);
  return sl_new;
}
int main()
{
  Slist_SinhVien sl;
  char ten[8];
  taoSlist_SV(sl);
  XuatDsSv(sl);
  printf("\nTim thong tin sinh vien x\n");
  printf("Nhap ten: ");
  scanf("%[^\n]%*c", ten);
  XuatDsSv(TimSv(sl, ten));
  getch();
  return 0;
}
