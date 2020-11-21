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
template <typename ItemType, typename SNode>
SNode *TaoNut(ItemType x)
{
  SNode *pNode = new SNode;
  if (!pNode)
  {
    printf("Khong du dung luong\n");
    return NULL;
  }
  pNode->info = x;
  pNode->next = NULL;
  return pNode;
}
template <typename Slist, typename SNode>
bool themCuoi(Slist &sl, SNode *pNode)
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
  // SNode_MonHoc *mh = sv->info.dsMH.head;
  // while (mh) {
  //   XuatMH(mh);
  //   mh = mh->next;
  // }
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
template <typename T>
void swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}
void SelectionSort(Slist_SinhVien &sl, bool(*compare)(const void*, const void*))
{
  SNode_SinhVien *pNode = new SNode_SinhVien;
  for (SNode_SinhVien *i = sl.head; i != sl.tail; i = i->next) {
    pNode = i;
    for (SNode_SinhVien *j = i->next; j != NULL; j = j->next) {
      if (compare(pNode, j)) pNode = j;
    }
    if (pNode != i) swap(pNode->info, i->info);
  }
}
bool compare_mssv_asc(const void *a, const void *b)
{
  SNode_SinhVien *sv1 = (SNode_SinhVien *)a;
  SNode_SinhVien *sv2 = (SNode_SinhVien *)b;
  return strcmpi(sv1->info.mssv, sv2->info.mssv) == 1 ? true : false;
}
bool compare_kqht_desc(const void *a, const void *b)
{
  SNode_SinhVien *sv1 = (SNode_SinhVien *)a;
  SNode_SinhVien *sv2 = (SNode_SinhVien *)b;
  return (sv1->info.diemKQ - sv2->info.diemKQ) < 0 ? true : false;
}
bool compare_TenSV_asc(const void *a, const void *b)
{
  SNode_SinhVien *sv1 = (SNode_SinhVien*)a;
  SNode_SinhVien *sv2 = (SNode_SinhVien*)b;
  return strcmpi(sv1->info.ten, sv2->info.ten) == 1 ? true : false;
}
bool ThemSV(Slist_SinhVien &sl)
{
  SinhVien sv;
  MonHoc mh;
  size_t len_SinhVien, len_MonHoc;
  SNode_SinhVien *pNode = sl.head;
  fflush(stdin);
  printf("Nhap mssv: ");
  scanf("%[^\n]%*c", sv.mssv);
  printf("Nhap ho dem: ");
  scanf("%[^\n]%*c", sv.hodem);
  printf("Nhap Ten: ");
  scanf("%[^\n]%*c", sv.ten);
  printf("Nam sinh: ");
  scanf("%d", &sv.namSinh);
  while (pNode) {
    if (strcmpi(pNode->info.mssv, sv.mssv)==0)
      return false;
    pNode = pNode->next;
  }
  KhoiTao(sv.dsMH); // khoi tao lai ds mon hoc cho tung sinh vien
  printf("Nhap so mon hoc: ");
  scanf("%d", &len_MonHoc);
  // them mon hoc
  for (size_t j = 0; j < len_MonHoc; j++) {
    bool trung = false;
    SNode_MonHoc *pNode_mh = sv.dsMH.head;
    fflush(stdin);
    printf("\nmon hoc %d\n", j+1);
    printf("Ma mon hoc: ");
    scanf("%[^\n]%*c", mh.maMH);
    printf("Ten mon hoc: ");
    scanf("%[^\n]%*c", mh.ten);
    printf("So Tc: ");
    scanf("%d", &mh.soTC);
    printf("Diem tieu luan mon hoc: ");
    scanf("%f", &mh.dtl);
    printf("Diem cuoi ki mon hoc: ");
    scanf("%f", &mh.dck);
    mh.diemMH = D_MH(mh.dtl, mh.dck); // tinh diem mon hoc
    while (pNode_mh) {
      if (strcmpi(pNode_mh->info.maMH, mh.maMH)==0 ||\
          strcmpi(pNode_mh->info.ten, mh.ten)==0\
          )
        {
          trung = true;
          j--; break;
        }
      pNode_mh = pNode_mh->next;
    }
    if (trung)
    {
      printf("\n-- mon hoc da co --\n");
      continue;
    }
    themCuoi(sv.dsMH, TaoNut<MonHoc, SNode_MonHoc>(mh));
  }
  sv.diemKQ = TinhDiemKQ(sv.dsMH); // tinh diem cho sv
  SNode_SinhVien *pNode_SV = TaoNut<SinhVien, SNode_SinhVien>(sv);
  SNode_SinhVien *pNode_temp = NULL;
  pNode = sl.head;
  // them nut
  if (!pNode)
  {
    sl.head = sl.tail = pNode_SV;
  }
  while (pNode) {
    if (strcmpi(pNode->info.mssv, pNode_SV->info.mssv)==1) break;
    pNode_temp = pNode;
    pNode = pNode->next;
  }
  if (!pNode_temp) {
    pNode_SV->next = sl.head;
    sl.head = pNode_SV;
  }else {
    pNode_SV->next = pNode;
    pNode_temp->next = pNode_SV;
  }
  if (pNode_temp==sl.tail) sl.tail = pNode_SV;
  return true;
}

void XoaDau(Slist_SinhVien &sl)
{
  SNode_SinhVien *pNode = sl.head;
  sl.head = pNode->next;
  if (!sl.head) sl.tail = NULL;
  delete pNode;
}
void XoaSau(Slist_SinhVien &sl, SNode_SinhVien *sv)
{
  if (!sv) return;
  SNode_SinhVien *p = sv->next;
  sv->next = p->next;
  if (p==sl.tail) sl.tail = sv;
  delete p;
}
void Xoa_SV(Slist_SinhVien &sl, char *info, bool(*IsEqual)(const void*, const void*))
{
  SNode_SinhVien *pNode = sl.head;
  SNode_SinhVien *tmp = NULL;
  bool KhongCoSV = true;
  if (!pNode)
  {
    printf("Danh Sach Rong\n");
    return;
  }
  while (pNode) {
    if (IsEqual(pNode, info))
    {
      if (!tmp) XoaDau(sl);
      else XoaSau(sl, tmp);
      KhongCoSV = false;
      pNode = sl.head;
      tmp = NULL;
      continue;
    }
    tmp = pNode;
    pNode = pNode->next;
  }
  if (KhongCoSV) {
    printf("-- Khong co sv --\n");
    return;
  }
}
bool IsEqual_mssv(const void *a, const void *b)
{
  SNode_SinhVien *sv = (SNode_SinhVien*)a;
  char *info = (char*)b;
  return strcmpi(sv->info.mssv, info) == 0?true:false;
}
bool IsEqual_ten(const void *a, const void *b)
{
  SNode_SinhVien *sv = (SNode_SinhVien*)a;
  char *info = (char*)b;
  return strcmpi(sv->info.ten, info) == 0?true:false;
}
Slist_SinhVien TaoDsSV_new_kqht_desc(Slist_SinhVien sl)
{
  Slist_SinhVien sl_new;
  SNode_SinhVien *pNode = sl.head;
  KhoiTao(sl_new);
  while (pNode) {
    themCuoi(sl_new, TaoNut<SinhVien, SNode_SinhVien>(pNode->info));
    pNode = pNode->next;
  }
  SelectionSort(sl_new, compare_kqht_desc);
  return sl_new;
}
Slist_SinhVien TaoDsSV_new_svKha(Slist_SinhVien sl)
{
  Slist_SinhVien sl_new;
  SNode_SinhVien *pNode = sl.head;
  KhoiTao(sl_new);
  while (pNode) {
    if (pNode->info.diemKQ>=7 && pNode->info.diemKQ<=8.5)
      themCuoi(sl_new, TaoNut<SinhVien, SNode_SinhVien>(pNode->info));
    pNode = pNode->next;
  }
  return sl_new;
}
Slist_SinhVien TaoDsSV_new_svGioi(Slist_SinhVien sl)
{
  Slist_SinhVien sl_new;
  SNode_SinhVien *pNode = sl.head;
  KhoiTao(sl_new);
  while (pNode) {
    if (pNode->info.diemKQ>8.5)
      themCuoi(sl_new, TaoNut<SinhVien, SNode_SinhVien>(pNode->info));
    pNode = pNode->next;
  }
  return sl_new;
}
int main()
{
  Slist_SinhVien sl;
  char ten[8], ma[10];
  taoSlist_SV(sl);
  XuatDsSv(sl);
  printf("\nTim thong tin sinh vien x\n");
  printf("Nhap ten: ");
  scanf("%[^\n]%*c", ten);
  XuatDsSv(TimSv(sl, ten));
  // sap xep tang dan theo mssv
  printf("\nsap xep ds sv theo chieu tang dan theo MSSV\n");
  SelectionSort(sl, compare_mssv_asc);
  XuatDsSv(sl);
  // sap xep ds sv theo chieu tang dan theo ten sinh vien
  printf("\nsap xep ds sv theo chieu tang dan theo ten sinh vien\n");
  SelectionSort(sl, compare_TenSV_asc);
  XuatDsSv(sl);
  // them sinh vien moi
  SelectionSort(sl, compare_mssv_asc);
  while (!ThemSV(sl))
  {
    printf("\nXin moi nhap lai\n");
  }
  XuatDsSv(sl);
  //  xoa sinh vien co MSSV
  printf("\nXoa sinh vien co mssv la x\n");
  printf("Nhap x: ");
  scanf("%[^\n]%*c", ma);
  Xoa_SV(sl, ma, IsEqual_mssv);
  XuatDsSv(sl);
  // xoa sv co ten x
  printf("\nXoa sinh vien co ten la x\n");
  printf("Nhap x: ");
  scanf("%[^\n]%*c", ten);
  Xoa_SV(sl, ten, IsEqual_ten);
  XuatDsSv(sl);
  printf("\nTao ds moi sao cho ds moi giam dan theo diem ket qua\n");
  Slist_SinhVien sl_new_kqht_desc = TaoDsSV_new_kqht_desc(sl);
  printf("\nDanh sach moi\n");
  XuatDsSv(sl_new_kqht_desc);
  printf("\nTao ds moi gom sinh duoc xep loi kha\n");
  Slist_SinhVien sl_new_svKha = TaoDsSV_new_svKha(sl);
  printf("\nDanh sach moi\n");
  XuatDsSv(sl_new_svKha);
  // tim diem kq cao nhat/thap nhat
  SelectionSort(sl, compare_kqht_desc);
  printf("Sinh vien co diem kq cao nhat\n");
  XuatSV(sl.head);
  printf("Sinh vien co diem kq thap nhat\n");
  XuatSV(sl.tail);
  Slist_SinhVien sl_new_svGioi = TaoDsSV_new_svGioi(sl);
  SelectionSort(sl_new_svGioi, compare_kqht_desc);
  printf("Sinh vien co diem kq thap nhat trong so cac sinh vien xep loai gioi\n");
  XuatSV(sl_new_svGioi.tail);
  getch();
  return 0;
}
