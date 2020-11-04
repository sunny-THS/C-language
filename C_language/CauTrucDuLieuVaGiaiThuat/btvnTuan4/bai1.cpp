#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
typedef int ItemType;
struct SNode {
  ItemType info;
  SNode *pNext;
};
struct SList {
  SNode *head;
  SNode *tail;
};
void initSlist(SList &sl) // initialization a singly linked list
{
  sl.head = sl.tail = NULL;
}
bool isEmpty(SList sl)
{
  return !sl.head ? true : false;
}
SNode *CreateSNode(ItemType x) // create a singly linked
{
  SNode *pSNode = new SNode;
  if(!pSNode)
  {
    printf("Khong du bo nho\n");
    return NULL;
  }
  pSNode->info = x;
  pSNode->pNext = NULL;
  return pSNode;
}
bool addTail(SList &sl, SNode *pSNode)
{
  if (!pSNode) return false;
  if (isEmpty(sl))
  {
    sl.head = pSNode;
    sl.tail = pSNode;
  }else {
    sl.tail->pNext = pSNode;
    sl.tail = pSNode;
  }
  return true;
}
bool addBefore(SList &sl, ItemType x, ItemType y)
{
  SNode *pSNode_y = CreateSNode(y);
  SNode *pSNode = sl.head;
  SNode *prev = NULL;
  bool isEqual = true;
  if (!pSNode) return false;
  if (isEmpty(sl))
  {
    sl.head =  pSNode;
    sl.tail = pSNode;
  }
  while (pSNode)
  {
    SNode *pSNode_x;
    if(isEqual)
      pSNode_x = CreateSNode(x);
    isEqual = false;
    if (pSNode->info == pSNode_y->info)
    {
      pSNode_x->pNext = pSNode;
      if (pSNode == sl.head)
        sl.head = pSNode_x;
      if (prev)
        prev->pNext = pSNode_x;
      isEqual = true;
    }
    prev = pSNode;
    pSNode = pSNode->pNext;
  }
  return true;
}
void CreateSList(SList &sl)
{
  FILE *f;
  size_t n;
  int x;
  initSlist(sl);
  if (!(f=fopen("input1.txt", "r")))
  {
    printf("Error\n");
    getch();
    exit(1);
  }
  fscanf(f, "%d", &n);
  for (size_t i = 0; i < n; i++) {
    fscanf(f, "%d", &x);
    addTail(sl, CreateSNode(x));
  }
}
void ShowNode(SNode *pSNode)
{
  printf("%d\t", pSNode->info);
}
void ShowSList(SList sl)
{
  SNode *pSNode = sl.head;
  while (pSNode)
  {
    ShowNode(pSNode);
    pSNode = pSNode->pNext;
  }
}
bool delHead(SList &sl)
{
  SNode *pSNode = sl.head;
  if (!sl.head) return false;
  sl.head = sl.head->pNext;
  if (!sl.head) sl.tail = NULL;
  delete pSNode;
  return true;
}
bool delAfter(SList &sl, SNode *p)
{
  if (p || p->pNext)
  {
    SNode *pSNode = p->pNext;
    p->pNext = pSNode->pNext;
    if (pSNode == sl.tail) sl.tail = pSNode;
    delete pSNode;
  } else return false;
  return true;
}
bool DelVal_greaterThanX(SList &sl, int x)
{
  SNode *pSNode = sl.head;
  SNode *prev = NULL;
  if (!pSNode) return false;
  while (pSNode)
  {
    if (pSNode->info > x)
    {
      if (pSNode == sl.head) delHead(sl);
      else delAfter(sl, prev);
      pSNode = sl.head;
      continue;
    }
    prev = pSNode;
    pSNode = pSNode->pNext;
  }
}
bool DelVal_even(SList &sl)
{
  SNode *pSNode = sl.head;
  SNode *prev = NULL;
  if (!pSNode) return false;
  while (pSNode)
  {
    if (!(pSNode->info%2))
    {
      if (pSNode == sl.head) delHead(sl);
      else delAfter(sl, prev);
      pSNode = sl.head;
      continue;
    }
    prev = pSNode;
    pSNode = pSNode->pNext;
  }
}
template <typename T>
void swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}
void SelectionSort(SList &sl, bool(*compare)(const void*, const void*))
{
  SNode *pSNode;
  for (SNode *p = sl.head; p != sl.tail; p = p->pNext) {
    pSNode = p;
    for (SNode *q = p->pNext; q != NULL; q = q->pNext) {
      if (compare(pSNode, q)) pSNode = q;
    }
    if (pSNode != p) swap(pSNode->info, p->info);
  }
}
bool compare_asc(const void *a, const void *b)
{
  SNode *p1 = (SNode*)a;
  SNode *p2 = (SNode*)b;
  return p1->info > p2->info;
}
bool compare_desc(const void *a, const void *b)
{
  SNode *p1 = (SNode*)a;
  SNode *p2 = (SNode*)b;
  return p1->info < p2->info;
}
bool checkPrimeNumber(ItemType x)
{
  if (x<2) return false;
  for (size_t i = 2; i < sqrt(x); i++) return false;
  return true;
}
int countVal_isPrimeNumber(SList &sl)
{
  SNode *pSNode = sl.head;
  size_t d=0;
  if (!pSNode) return false;
  while (pSNode)
  {
    if (checkPrimeNumber(pSNode->info))
      d++;
    pSNode = pSNode->pNext;
  }
  return d;
}
bool checkSquareNumber(ItemType x)
{
  int a = sqrt(x);
  if (a*a == x) return true;
  return false;
}
int sumVal_isSquareNumber(SList &sl)
{
  SNode *pSNode = sl.head;
  size_t d=0;
  if (!pSNode) return false;
  while (pSNode)
  {
    if (checkSquareNumber(pSNode->info))
      d += pSNode->info;
    pSNode = pSNode->pNext;
  }
  return d;
}
SNode *FindVal_(SList sl, bool isMax = true) //default find max
{
    SNode *pSNode = sl.head;
    SNode *tmp = sl.head->pNext;
    if (!pSNode) return NULL;
    while (pSNode)
    {
      if (isMax)
      {
        if (tmp->info < pSNode->info)
          tmp = pSNode;
      }else {
        if (tmp->info > pSNode->info)
          tmp = pSNode;
      }
      pSNode = pSNode->pNext;
    }
    return tmp;
}
void filter_even_odd(SList sl, SList &sl_even, SList &sl_odd)
{
  // initialization 2 singly linked list
  initSlist(sl_even);
  initSlist(sl_odd);
  SNode *pSNode = sl.head;
  if (isEmpty(sl))
  {
    printf("Danh sach rong\n");
    return;
  }
  while (pSNode)
  {
    if(pSNode->info % 2 == 0) addTail(sl_even, CreateSNode(pSNode->info));
    else addTail(sl_odd, CreateSNode(pSNode->info));
    pSNode = pSNode->pNext;
  }
}
int main()
{
  SList sl;
  CreateSList(sl);
  ShowSList(sl);
  printf("\nThem gia tri vao cuoi ds\n");
  int x;
  printf("Nhap gia tri: ");
  scanf("%d", &x);
  addTail(sl, CreateSNode(x));
  ShowSList(sl);
  printf("\nThem gia tri vao truoc gia tri y\n");
  int y;
  printf("Nhap gia tri x: ");
  scanf("%d", &x);
  printf("Nhap gia tri y: ");
  scanf("%d", &y);
  addBefore(sl, x, y);
  ShowSList(sl);
  printf("\nSap xep tang dan gia tri\n");
  SelectionSort(sl, compare_asc);
  ShowSList(sl);
  printf("\nSap xep giam dan gia tri\n");
  SelectionSort(sl, compare_desc);
  ShowSList(sl);
  printf("\nso luong so nguyen to: %d\n", countVal_isPrimeNumber(sl));
  printf("\ntong ca so chinh phuong: %d\n", sumVal_isSquareNumber(sl));
  SNode *tmp = FindVal_(sl);
  printf("\nGia tri lon nhat trong danh sach: ");
  if (tmp) ShowNode(tmp);
  else printf("\nKhong Tim thay\n");
  printf("\nGia tri nho nhat trong danh sach: ");
  tmp = FindVal_(sl, false);
  if (tmp) ShowNode(tmp);
  else printf("\nKhong Tim thay\n");
  SList sl_even, sl_odd;
  filter_even_odd(sl, sl_even, sl_odd);
  printf("\nDanh sach chan\n");
  ShowSList(sl_even);
  printf("\nDanh sach le\n");
  ShowSList(sl_odd);
  printf("\nXoa phan tu lon hon x\n");
  printf("Nhap x: ");
  scanf("%d", &x);
  DelVal_greaterThanX(sl, x);
  ShowSList(sl);
  printf("\nXoa phan tu co gia tri chan\n");
  DelVal_even(sl);
  ShowSList(sl);
  getch();
  return 0;
}
