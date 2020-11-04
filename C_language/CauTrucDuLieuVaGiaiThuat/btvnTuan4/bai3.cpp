#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef int ItemType;
struct SNode {
  ItemType info;
  SNode *pNext;
};
struct Slist {
  SNode *head;
  SNode *tail;
};
void initSlist(Slist &sl)
{
  sl.head = sl.tail = NULL;
}
SNode *createSNode(ItemType x)
{
  SNode *pNode = new SNode;
  if(!pNode)
  {
    printf("Khong du bo nho\n");
    return NULL;
  }
  pNode->info = x;
  pNode->pNext = NULL;
  return pNode;
}
bool addHead(Slist &sl, SNode *pNode)
{
  if (!pNode) return false;
  if (!sl.head) {
    sl.head = pNode;
    sl.tail = pNode;
  } else {
    pNode->pNext = sl.head;
    sl.head = pNode;
  }
  return true;
}
bool addTail(Slist &sl, SNode *pNode)
{
  if (!pNode) return false;
  if (!sl.head)
  {
    sl.head = pNode;
    sl.tail = pNode;
  } else {
    sl.tail->pNext = pNode;
    sl.tail = pNode;
  }
  return true;
}
void createSlist(Slist &sl, char *url)
{
  initSlist(sl);
  FILE *f;
  size_t n;
  int x;
  if (!(f=fopen(url, "r")))
  {
    printf("error\n");
    getch();
    exit(1);
  }
  fscanf(f, "%d", &n);
  for (size_t i = 0; i < n; i++) {
    fscanf(f, "%d", &x);
    addTail(sl, createSNode(x));
  }
}
void showNode(SNode *p)
{
  printf("%d\t", p->info);
}
void display(Slist sl)
{
  SNode *pNode = sl.head;
  if (!pNode)
  {
    printf("Danh sach rong\n");
    return;
  }
  printf("Danh sach\n");
  while (pNode) {
    showNode(pNode);
    pNode = pNode->pNext;
  }
}
void insert_X(Slist &sl, ItemType x)
{
  SNode *pNode_x = createSNode(x);
  SNode *prev = NULL;
  if (!sl.head || !pNode_x) return;
  SNode *pNode = sl.head;
  while (pNode) {
    if(pNode_x->info <= pNode->info)
    {
      pNode_x->pNext = pNode;
      if (prev) prev->pNext = pNode_x;
      if (pNode == sl.head) sl.head = pNode_x;
      return;
    }
    prev = pNode;
    pNode = pNode->pNext;
  }
}
Slist SlistRev(Slist sl)
{
  Slist SlistRev;
  SNode *p = sl.head;
  initSlist(SlistRev);
  while (p) {
    addHead(SlistRev, createSNode(p->info));
    p = p->pNext;
  }
  return SlistRev;
}
bool SlistCat(Slist &sl1, Slist sl2, ItemType x)
{
  SNode *p = sl1.head;
  if (!p)
  {
    printf("ds rong\n");
    return false;
  }
  while (p) {
    if (p->info == x)
    {
      sl2.tail->pNext = p->pNext;
      p->pNext = sl2.head;
      if (p == sl1.tail) sl1.tail = sl2.tail;
      return true;
    }
    p = p->pNext;
  }
  return false;
}
int main()
{
  Slist sl;
  createSlist(sl, "input3.txt");
  display(sl);
  printf("\nchen phan tu x vao ds nhung van giu nguyen thu tu\n");
  int x;
  printf("Nhap x: ");
  scanf("%d", &x);
  insert_X(sl, x);
  display(sl);
  printf("\nin danh sach theo thu tu giam dan\n");
  display(SlistRev(sl));
  printf("\nNoi danh sach sl2 vao sao ptu co gia tri x\n");
  Slist sl2;
  printf("khoi tao sl2\n");
  createSlist(sl2, "input3_slist2.txt");
  display(sl2);
  printf("\nNhap x: ");
  scanf("%d", &x);
  if (SlistCat(sl, sl2, x)) display(sl);
  else printf("khong tim thay x\n");
  getch();
  return 0;
}
