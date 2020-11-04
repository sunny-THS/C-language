#include <stdio.h>
#include <conio.h>
#include <math.h>
typedef int ItemType;
struct PhanSo {
  ItemType TuSo, MauSo;
  PhanSo *pNext;
};
struct Slist {
  PhanSo *head;
  PhanSo *tail;
};
void KhoiTaoDs(Slist &sl)
{
  sl.head = sl.tail = NULL;
}
PhanSo *TaoPhanSo(ItemType tu, ItemType mau)
{
  PhanSo *p_ps = new PhanSo;
  if (!p_ps)
  {
    printf("Khong du bo nho\n");
    return NULL;
  }
  p_ps->TuSo = tu;
  p_ps->MauSo = mau;
  p_ps->pNext = NULL;
  return p_ps;
}
bool themCuoi(Slist &sl, PhanSo *p_ps)
{
  if (!p_ps) return false;
  if (!sl.head)
  {
    sl.head = p_ps;
    sl.tail = p_ps;
  } else {
    sl.tail->pNext = p_ps;
    sl.tail = p_ps;
  }
  return true;
}
PhanSo *nhapPhanSo(int i=0)
{
  int tu, mau;
  do {
    mau = 0;
    i==0 ? printf("Phan So: ") : printf("Phan So %d: ", i);
    scanf("%d/%d", &tu, &mau);
    if (mau==0) {
      printf("\nMoi nhap lai\n");
    }
  } while(mau==0);
  return TaoPhanSo(tu, mau);
}
void nhapDsPhanSo(Slist &sl)
{
  size_t n;
  KhoiTaoDs(sl);
  do {
    printf("\nNhap n:");
    scanf("%d", &n);
  } while(n<=0);
  printf("Nhap Phan So\n");
  for (size_t i = 0; i < n; i++) {

    themCuoi(sl, nhapPhanSo(i+1));
  }
}
void Xuat_PS(PhanSo *p_ps)
{
  if (p_ps->TuSo == 0) {
    printf("0\t");
  }else if (p_ps->MauSo == 1) {
    printf("%d\t", p_ps->TuSo);
  }else printf("%d/%d\t", p_ps->TuSo, p_ps->MauSo);
}
void Xuat(Slist sl)
{
  PhanSo *p_ps = sl.head;
  if (!p_ps)
  {
    printf("Khong co\n");
    return;
  }
  printf("Danh sach phan so\n");
  while (p_ps)
  {
    Xuat_PS(p_ps);
    p_ps = p_ps->pNext;
  }
}
int ucln(int a, int b)
{
  if (a==0 || b==0) return a+b;
  while (a!=b) {
    a > b ? a -= b : b -= a;
  }
  return a;
}
PhanSo *toiGianPhanSo(PhanSo *p_ps)
{
  int uc = ucln(abs(p_ps->TuSo), abs(p_ps->MauSo));
  p_ps->TuSo /= uc;
  p_ps->MauSo /= uc;
  if (p_ps->MauSo < 0) {
    p_ps->MauSo *= -1;
    p_ps->TuSo *= -1;
  }
  return p_ps;
}
bool toiGianDSPhanSo(Slist &sl)
{
  PhanSo *p_ps = sl.head;
  if (!p_ps)
  {
    printf("error\n");
    return false;
  }
  while (p_ps)
  {
    p_ps = toiGianPhanSo(p_ps);
    p_ps = p_ps->pNext;
  }
}
PhanSo *Tinh(Slist sl, bool isSum = true) // default is sum
{
  PhanSo *a = new PhanSo;
  PhanSo *p_ps = sl.head;
  if (!p_ps)
  {
    printf("error\n");
    return NULL;
  }
  a->TuSo =  isSum ? 0 : 1;
  a->MauSo = 1;
  while (p_ps) {
    Xuat_PS(p_ps);
    if (isSum) {
      a->TuSo = p_ps->TuSo * a->MauSo + a->TuSo * p_ps->MauSo;
      a->MauSo *= p_ps->MauSo;
      if (p_ps->pNext == NULL) {
        printf(" = ");
        break;
      }
      printf("+\t");
    }else {
      a->TuSo *= p_ps->TuSo;
      a->MauSo *= p_ps->MauSo;
      if (p_ps->pNext == NULL) {
        printf(" = ");
        break;
      }
      printf("*\t");
    }
    p_ps = p_ps->pNext;
  }
  return toiGianPhanSo(a);
}
PhanSo *TimPhanSo_maxmin(Slist sl, bool isMax = true)
{
  PhanSo *p_ps = sl.head;
  PhanSo *tmp = p_ps;
  float n = p_ps->TuSo * 1.0/p_ps->MauSo;
  if (!p_ps) return NULL;
  while (p_ps) {
    float t = p_ps->TuSo * 1.0/p_ps->MauSo;
    if (isMax) {
      if (n < t) {
        tmp = p_ps;
        n=t;
      }
    }else {
      if (n > t) {
        tmp = p_ps;
        n=t;
      }
    }
    p_ps = p_ps->pNext;
  }
  return tmp;
}
void tangPS_1Dv(Slist sl)
{
  PhanSo *p_ps = sl.head;
  while (p_ps) {
    p_ps->TuSo = p_ps->TuSo * 1 + 1 * p_ps->MauSo;
    p_ps->MauSo *= 1;
    p_ps = p_ps->pNext;
  }
}
Slist dsPs_lonHon1(Slist sl)
{
  PhanSo *p_ps = sl.head;
  Slist a;
  KhoiTaoDs(a);
  while (p_ps) {
    float n = p_ps->TuSo * 1.0/p_ps->MauSo;
    if (n>1) themCuoi(a, TaoPhanSo(p_ps->TuSo, p_ps->MauSo));
    p_ps = p_ps->pNext;
  }
  return a;
}
PhanSo *TimPhanSo_P(Slist sl, PhanSo *p)
{
  PhanSo *p_ps = sl.head;
  printf("phan so can tim: ");
  if (!p_ps) return NULL;
  while (p_ps) {
    if (p_ps->TuSo == p->TuSo && p_ps->MauSo == p->MauSo)
      return p_ps;
    p_ps = p_ps->pNext;
  }
  return NULL;
}
int main()
{
  Slist sl;
  nhapDsPhanSo(sl);
  Xuat(sl);
  printf("\n\nPhan so toi gian\n");
  toiGianDSPhanSo(sl);
  Xuat(sl);
  printf("\n\nTinh tong: ");
  PhanSo *p_ps = Tinh(sl);
  Xuat_PS(p_ps);
  printf("\n\nTinh tich: ");
  p_ps = Tinh(sl, false);
  Xuat_PS(p_ps);
  printf("\n\nPhan so lon nhat: ");
  Xuat_PS(TimPhanSo_maxmin(sl));
  printf("\n\nPhan so nho nhat: ");
  Xuat_PS(TimPhanSo_maxmin(sl, false));
  printf("\n\nds phan so lon hon 1\n");
  Xuat(dsPs_lonHon1(sl));
  printf("\n\nTim phan so p\n");
  Xuat_PS(TimPhanSo_P(sl, nhapPhanSo()));
  printf("\n\nMoi phan so trong ds tang 1 dv\n");
  tangPS_1Dv(sl);
  Xuat(sl);
  getch();
  return 0;
}
