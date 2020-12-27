#include "BinaryTree_Obj.h"

typedef int ItemType;

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
    t.insert(x);
  }
}

int main()
{
  char FileName[10] = "input.txt";
  BTree<ItemType> t; // default: int
  createBTree<ItemType>(t, FileName);
  t.Show();
  return 0;
}
