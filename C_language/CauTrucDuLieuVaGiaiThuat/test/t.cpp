#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Date
{
  int d, m, y;
};
struct NhanVien
{
  char mssv[15], hoten[30];
  Date ngaySinh;
  float luong;
  char gioiTinh[5];
};
typedef NhanVien ItemType;
struct TNode
{
  ItemType info;
  TNode *left;
  TNode *right;
};
struct BTree {
  TNode *root;
};
void init(BTree &bt)
{
  bt.root = NULL;
}
TNode *CreateTNode(ItemType x)
{
  TNode *p = new TNode;
  if (!p)
  {
    printf("Khong du bo nho\n");
    getch();
    return NULL;
  }
  p->info = x;
  p->left = p->right = NULL;
  return p;
}
int insert(TNode *&p, TNode *x)
{
  if (!x) return 0;
  if (!p)
  {
    p = x;
    return 1;
  }
  if (p->info.mssv == x->info.mssv) return 0;
  return p->info.mssv > x->info.mssv? insert(p->left, x):\
                                      insert(p->right, x);
}
void createBTree(BTree &bt, char *FileName)
{
  init(bt);
  FILE *f;
  ItemType x;
  if (!(f=fopen(FileName, "r")))
  {
    printf("File khong ton tai\n");
    getch();
    exit(1);
  }
  int n;
  fscanf(f, "%d", &n);
  for (size_t i = 0; i < n; i++) {
    fscanf(f, "%s", x.mssv);
    fscanf(f, "%s", x.hoten);
    fscanf(f, "%d", &x.ngaySinh.d);
    fscanf(f, "%d", &x.ngaySinh.m);
    fscanf(f, "%d", &x.ngaySinh.y);
    fscanf(f, "%f", &x.luong);
    fscanf(f, "%s", &x.gioiTinh);
    insert(bt.root, CreateTNode(x));
  }
  fclose(f);
}
void showNode(TNode *p)
{
  printf("%s %20s %5d/%2d/%4d %10.f %s\n", \
    p->info.mssv, p->info.hoten, \
    p->info.ngaySinh.d, p->info.ngaySinh.m, p->info.ngaySinh.y, \
    p->info.luong, p->info.gioiTinh \
  );
}
void show(TNode *p)
{
  if (!p) return;
  showNode(p);
  show(p->left);
  show(p->right);
}
int main()
{
  BTree bt;
  createBTree(bt,"input.txt");
  show(bt.root);
  return 1;
}
