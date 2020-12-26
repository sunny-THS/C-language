#include "BinaryTree_Obj.h"

int main()
{
  char FileName[10] = "input.txt";
  BTree t;
  t.createBTree(FileName);
  t.Show();
  return 0;
}
