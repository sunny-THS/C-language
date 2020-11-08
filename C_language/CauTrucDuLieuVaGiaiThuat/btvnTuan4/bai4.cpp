#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef int ItemType;
struct SNode {
  ItemType info;
  SNode *next;
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
  SNode *p_SNode = new SNode;
  if (!p_SNode)
  {
    printf("Khong du bo nho\n");
    return NULL;
  }
  p_SNode->info = x;
  p_SNode->next = NULL;
  return p_SNode;
}
bool addTail(Slist &sl, SNode *p_SNode)
{
  if (!p_SNode) return false;
  if (!sl.head) sl.head = sl.tail = p_SNode;
  else {
    sl.tail->next = p_SNode;
    sl.tail = p_SNode;
  }
  return true;
}
void createSlist(Slist &sl, char *fileName)
{
  initSlist(sl);
  FILE *f;
  int x, n;
  if (!(f=fopen(fileName, "r")))
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
void ShowNode(SNode *p_SNode)
{
  printf("%d\t", p_SNode->info);
}
void display(Slist sl)
{
  SNode *p_SNode = sl.head;
  if (!p_SNode)
  {
    printf("Ds rong\n");
    return;
  }
  printf("\ndanh sach\n");
  while (p_SNode) {
    ShowNode(p_SNode);
    p_SNode = p_SNode->next;
  }
}
void mix_sl1_sl2_asc(Slist &sl, Slist sl1, Slist sl2)
{
  initSlist(sl);
  SNode *p_SNode = sl.head;
  SNode *p_SNode1 = sl1.head;
  SNode *p_SNode2 = sl2.head;
  while (p_SNode1 && p_SNode2) {
    if (p_SNode1->info <= p_SNode2->info)
    {
      addTail(sl, createSNode(p_SNode1->info));
      p_SNode1 = p_SNode1->next;
    }
    else {
      addTail(sl, createSNode(p_SNode2->info));
      p_SNode2 = p_SNode2->next;
    }
  
}
int main()
{
  Slist sl, sl1, sl2;
  createSlist(sl1, "input4_sl1.txt");
  createSlist(sl2, "input4_sl2.txt");
  display(sl1);
  display(sl2);
  printf("\nds duoc tron tang");
  mix_sl1_sl2_asc(sl, sl1, sl2);
  display(sl);
  getch();
  return 0;
}
