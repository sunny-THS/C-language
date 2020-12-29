#include "BinaryTree_Obj.h"

typedef int ItemType;

int insert_int (const void *a, const void *b)
{
  TNode<ItemType> *p_root = (TNode<ItemType>*)a;
  TNode<ItemType> *p_x = (TNode<ItemType>*)b;
  if (p_root->info == p_x->info) return 0;
  return p_root->info > p_x->info ? -1 : 1;
}
void showNode(const void *a)
{
  TNode<ItemType> *root = (TNode<ItemType>*)a;
  printf("%d\t", root->info);
}

template <class ItemType>
void createBTree(BTree<ItemType> &t, char *FileName)
{
  FILE *f;
  ItemType x;
  if (!(f=fopen(FileName, "r")))
  {
    printf("File khong ton tai\n");
    getch();
    exit(1);
  }
  while (!feof(f))
  {
    fscanf(f, "%d", &x);
    t.insert(x, insert_int);
  }
}

int main()
{
  char FileName[10] = "input.txt";
  BTree<ItemType> t; // default: int
  createBTree<ItemType>(t, FileName);
  t.show(showNode);
  return 0;
}
