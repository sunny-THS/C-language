#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int ItemType;

struct SNode {
    ItemType info;
    SNode *next;
};
struct SList {
  SNode * head;
  SNode * tail;
};
void initSLNode(SList &sl) // init single list node
{
  sl.head = NULL;
  sl.tail = NULL;
}
bool isEmpty(SList sl)
{
  return !sl.head ? true : false; // if node null
}
SNode *CreateSNode(ItemType x) // create single node
{
  SNode * p = new SNode;
  if (!p) {
    printf("khong du bo nho\n");
    getch();
    return NULL;
  }
  p->info = x;
  p->next = NULL;
  return p;
}
bool addValue(SList &sl, SNode *p) // node p about info=x and *next=NULL;
{
  if(!p) return false;
  if(isEmpty(sl))
  {
    sl.head = p;
    sl.tail = p;
  }
  else {
    sl.tail->next = p;
    sl.tail = p;
  }
  return true;
}
void CreateSListNode(SList &sl)
{
  FILE *f;
  size_t n; // the length of single list node
  ItemType x; // this is a value of a node
  if (!(f=fopen("input.txt", "r")))
  {
    printf("ERROR\n");
    getch();
    exit(1);
  }
  initSLNode(sl); // initialization single node list
  fscanf(f, "%d", &n);
  for (size_t i = 0; i < n; i++) {
    fscanf(f, "%d", &x);
    addValue(sl, CreateSNode(x)); // (list, node)
  }
}
void xuat(SList sl)
{
  for (SNode *node = sl.head; node != NULL; node = node->next) {
    printf("%d\t", node->info);
  }
  printf("\n");
}
template <typename T>
void swap(T &a, T &b)
{
  T t = a;
  a = b;
  b = t;
}
bool compare_asc(const void *a, const void *b)
{
  SNode *node_a = (SNode *)a;
  SNode *node_b = (SNode *)b;
  return node_a->info > node_b->info;
}
// void InterchangeSort(SList &sl, bool(*compare)(const void *, const void *))
// {
//   if(!sl) return;
//   for (SNode *node_a = sl.head; node_a != sl.tail; node_a = node_a->next) {
//     for (SNode *node_b = node_a->next; node_b != NULL; node_b = node_b->next) {
//       if (compare(node_a, node_b))
//         swap(node_a->info, node_b->info);
//     }
//   }
// }
void	SListAppend(SList &l, SList &l2)
{
	if (l2.head == NULL) return;
	if (l.head == NULL)
		l = l2;
	else {
		l.head->next = l2.head;
		l.tail = l2.tail;
	}
	initSLNode(l2);
}

void QuickSort(SList &sl, bool(*compare)(const void *, const void *))
{
  SNode *x, *p;
  SList l_a, l_b;
  if(sl.head == sl.tail) return;
  // initialization 2 new list
  initSLNode(l_a);
  initSLNode(l_b);
  // select value á threshold
  x = sl.head;
  sl.head = x->next;
  for (SNode *i = sl.head; i != NULL; i = i->next) {
    if (compare(x, i)) addValue(l_a, i);
    else addValue(l_b, i);
  }
  QuickSort(l_a, compare);
  QuickSort(l_b, compare);
  SListAppend(sl, l_a);
	addValue(sl, x);
	SListAppend(sl, l_b);
}
int main()
{
  SList sl;
  CreateSListNode(sl);
  xuat(sl);
  QuickSort(sl, compare_asc);
  xuat(sl);
  getch();
  return 0;
}
