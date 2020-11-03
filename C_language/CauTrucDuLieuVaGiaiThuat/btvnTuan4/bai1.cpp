#include <stdio.h>
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
void initSlist(SList &sl) // intitialization a singly linked list
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
  }
  sl.tail->pNext = pSNode;
  sl.tail = pSNode;
  return true;
}
bool addBefore(SList &sl, SNode *pSNode_x, ItemType y)
{
  SNode *pSNode_y = CreateSNode(y);
  SNode *pSNode = sl.head;
  if (!pSNode) return false;
  if (isEmpty(sl))
  {
    sl.head =  pSNode;
    sl.tail = pSNode;
  }
  while (pSNode!=sl.tail)
  {
    if (pSNode->pNext->info == pSNode_y->info)
    {
      pSNode_x->pNext = pSNode->pNext;
      pSNode->pNext = pSNode_x;
    }
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
void ShowSList(SList sl)
{
  SNode *pSNode = sl.head;
  while (pSNode)
  {
    printf("%d\t", pSNode->info);
    pSNode = pSNode->pNext;
  }
}
int main()
{
  SList sl;
  CreateSList(sl);
  ShowSList(sl);
  printf("\nThem gia tri\n");
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
  addBefore(sl, CreateSNode(x), y);
  ShowSList(sl);

  getch();
  return 0;
}
