#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <string.h>
struct BaiHat {
    char TenBai[50], TacGia[40], CaSi[40];
    int ThoiLuong; // tinh bang giay
};
typedef BaiHat ItemType;
struct SNode_BaiHat {
  ItemType info;
  SNode_BaiHat *next;
};
struct Slist_BaiHat {
  SNode_BaiHat *head;
  SNode_BaiHat *tail;
};

void initSlist(Slist_BaiHat &sl)
{
  sl.head = sl.tail = NULL;
}
SNode_BaiHat *TaoBaiHat(ItemType bh)
{
  SNode_BaiHat *p_BaiHat = new SNode_BaiHat;
  if (!p_BaiHat)
  {
    printf("Khong Du Bo Nho\n");
    return NULL;
  }
  p_BaiHat->info = bh;
  p_BaiHat->next = NULL;
  return p_BaiHat;
}
bool ThemCuoi(Slist_BaiHat &sl, SNode_BaiHat *pNode)
{
  if (!pNode) return false;
  if (!sl.head)
  {
    sl.head = sl.tail = pNode;
  }else
  {
    sl.tail->next = pNode;
    sl.tail = pNode;
  }
  return true;
}
bool ThemDau(Slist_BaiHat &sl, SNode_BaiHat *pNode)
{
  if (!pNode) return false;
  if (!sl.head) sl.head = sl.tail = pNode;
  else
  {
    pNode->next = sl.head;
    sl.head = pNode;
  }
  return true;
}
BaiHat NhapBaiHat()
{
  ItemType x;
  printf("Nhap ten bai hat: ");
  scanf("%[^\n]%*c", x.TenBai);
  printf("Nhap tac gia: ");
  scanf("%[^\n]%*c", x.TacGia);
  printf("Nhap ca si: ");
  scanf("%[^\n]%*c", x.CaSi);
  printf("Nhap thoi luong: ");
  scanf("%d", &x.ThoiLuong);
  fflush(stdin);
  return x;
}
void TaoDsNhac(Slist_BaiHat &sl)
{
  initSlist(sl);
  FILE *f;
  size_t n;
  ItemType x;
  if (!(f=fopen("input2.txt", "r")))
  {
    printf("Error\n");
    exit(1);
  }
  fscanf(f, "%d\n", &n);
  for (size_t i = 0; i < n; i++) {
    fscanf(f, "%[^\n]%*c\n", x.TenBai);
    fscanf(f, "%[^\n]%*c\n", x.TacGia);
    fscanf(f, "%[^\n]%*c\n", x.CaSi);
    fscanf(f, "%d\n", &x.ThoiLuong);
    ThemCuoi(sl, TaoBaiHat(x));
  }
}
void XuatBaiHat(SNode_BaiHat *bh)
{
  printf("%25s\t", bh->info.TenBai);
  printf("%20s\t", bh->info.TacGia);
  printf("%20s\t", bh->info.CaSi);
  printf("%10d s\n", bh->info.ThoiLuong);
}
void XuatDs(Slist_BaiHat sl)
{
  SNode_BaiHat *pNode = sl.head;
  if (!pNode)
  {
    printf("Danh Sanh Rong\n");
    return;
  }
  printf("%25s\t%20s\t%20s\t%15s\n",\
          "TenBai", "TacGia", "CaSi", "ThoiLuong"
        );
  printf("\n");
  while (pNode) {
    XuatBaiHat(pNode);
    pNode = pNode->next;
  }
}
int TinhThoiLuong(Slist_BaiHat sl)
{
  size_t time = 0;
  SNode_BaiHat *pNode = sl.head;
  if (!pNode) return 0;
  while (pNode) {
    time += pNode->info.ThoiLuong;
    pNode = pNode->next;
  }
  return time;
}
void DoiSoGiay(int giay)
{
  size_t h = giay/3600;
  size_t m = giay%3600/60;
  size_t s = giay%3600%60;
  char dateTime[50];
  if (h>=24) {
    printf("%d d %d:%d:%d\n", h%24, h, m, s);
  }else
    printf("%d h:%d m:%d s\n", h, m, s);
}
void XoaDau(Slist_BaiHat &sl)
{
  SNode_BaiHat *pNode = sl.head;
  sl.head = pNode->next;
  if (!sl.head) sl.tail = NULL;
  delete pNode;
}
void XoaSau(Slist_BaiHat &sl, SNode_BaiHat *bh)
{
  if (!bh) return;
  SNode_BaiHat *p = bh->next;
  bh->next = p->next;
  if (p==sl.tail) sl.tail = bh;
  delete p;
}
void XoaBaiHat(Slist_BaiHat &sl, char *tenBaiHat)
{
  SNode_BaiHat *pNode = sl.head;
  SNode_BaiHat *tmp = NULL;
  if (!pNode)
  {
    printf("Danh Sach Rong\n");
    return;
  }
  while (pNode) {
    if (strcmpi(pNode->info.TenBai, tenBaiHat) == 0)
      break;
    tmp = pNode;
    pNode = pNode->next;
  }
  if (!pNode) {
    printf("Khong co bai hat\n");
    return;
  }
  if (!tmp) XoaDau(sl);
  else XoaSau(sl, tmp);
}
SNode_BaiHat *TimBaiHat(Slist_BaiHat sl, char *tenBaiHat)
{
  SNode_BaiHat *pNode = sl.head;
  if (!pNode) return NULL;
  while (pNode) {
    if (strcmpi(pNode->info.TenBai, tenBaiHat) == 0)
      return pNode;
    pNode = pNode->next;
  }
  return NULL;
}
template <typename T>
void swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}
void SelectionSort(Slist_BaiHat &sl, bool(*compare)(const void*, const void*))
{
  SNode_BaiHat *pNode = new SNode_BaiHat;
  for (SNode_BaiHat *i = sl.head; i != sl.tail; i = i->next) {
    pNode = i;
    for (SNode_BaiHat *j = i->next; j != NULL; j = j->next) {
      if (compare(pNode, j)) pNode = j;
    }
    if(pNode != i) swap(pNode->info, i->info);
  }
}
bool compare_Name_asc(const void *a, const void *b)
{
  SNode_BaiHat *b1 = (SNode_BaiHat *)a;
  SNode_BaiHat *b2 = (SNode_BaiHat *)b;
  return strcmpi(b1->info.TenBai, b2->info.TenBai)==1?true:false;
}
bool compare_TenCaSi_desc(const void *a, const void *b)
{
  SNode_BaiHat *b1 = (SNode_BaiHat*)a;
  SNode_BaiHat *b2 = (SNode_BaiHat*)b;
  return strcmpi(b2->info.CaSi, b1->info.CaSi)==1?true:false;
}
void ChuyenBaiHatLenDau(Slist_BaiHat &sl, char *x)
{
  SNode_BaiHat *pNode = sl.head;
  SNode_BaiHat *tmp = NULL;
  if (!TimBaiHat(sl, x))
  {
    printf("\nKhong co bai hat nay\n");
    return;
  }else
  {
    while (pNode) {
      if (strcmpi(pNode->info.TenBai, x)==0)
        break;
      tmp = pNode;
      pNode = pNode->next;
    }
    if (!tmp) return;
    SNode_BaiHat *pNode_x = pNode;
    tmp->next = pNode->next;
    pNode_x->next = NULL;
    if (pNode==sl.tail) sl.tail=tmp;
    // chuyen len dau
    pNode_x->next = sl.head;
    sl.head = pNode_x;
  }
}
int main()
{
  Slist_BaiHat sl;
  char tenBaiHat[50];
  TaoDsNhac(sl);
  XuatDs(sl);
  size_t tg = TinhThoiLuong(sl);
  printf("\nDe nghe het tat ca bai hat trong playlist phai can %d giay -- ",\
          tg
        );
  DoiSoGiay(tg);
  printf("\nNhap 1 bai hat them vao cuoi\n");
  ThemCuoi(sl, TaoBaiHat(NhapBaiHat()));
  XuatDs(sl);
  printf("\nNhap 1 bai hat them vao dau\n");
  ThemDau(sl, TaoBaiHat(NhapBaiHat()));
  XuatDs(sl);
  printf("\nXoa 1 bai hat\n");
  printf("Nhap ten bai hat can xoa: ");
  scanf("%[^\n]%*c", tenBaiHat);
  XoaBaiHat(sl, tenBaiHat);
  XuatDs(sl);
  printf("\nTim 1 bai hat\n");
  printf("Nhap ten bai hat can tim: ");
  scanf("%[^\n]%*c", tenBaiHat);
  SNode_BaiHat *tmp = TimBaiHat(sl, tenBaiHat);
  if (tmp) XuatBaiHat(tmp);
  else printf("Khong co trong playlist\n");
  printf("\nSap Xep Bai Hat theo thu tu tu dien\n");
  SelectionSort(sl, compare_Name_asc);
  XuatDs(sl);
  printf("\nSap Xep giam dan theo ten ca si\n");
  SelectionSort(sl, compare_TenCaSi_desc);
  XuatDs(sl);
  printf("\nChuyen bai hat x len dau playlist\n");
  printf("Nhap ten bai hat can tim: ");
  scanf("%[^\n]%*c", tenBaiHat);
  ChuyenBaiHatLenDau(sl, tenBaiHat);
  XuatDs(sl);
  getch();
  return 0;
}
