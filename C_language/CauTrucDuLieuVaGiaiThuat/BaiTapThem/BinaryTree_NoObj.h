#ifndef BTREE_H_
  #define BTREE_H_
  #include <stdio.h>
  #include <conio.h> // getch()
  #include <cstdlib> // exit()
  typedef int ItemType;
  struct TNode {
    ItemType info;
    TNode *l;
    TNode *r;
  };
  struct BTree {
    TNode *root;
  };

  void init (BTree &t) { t.root = NULL; }
  TNode *CreateTNode (ItemType x)
  {
    TNode *p = new TNode;
    if (!p) return NULL;
    p->info = x;
    p->l = p->r = NULL;
    return p;
  }
  int insert(TNode * &p, TNode *node)
  {
    if (!node) return 0; // insert fail
    if (!p)
    {
      p = node;
      return 1; // inserted
    }
    if (p->info == node->info) return 0;
    if (p->info > node->info) insert(p->l, node);
    else insert(p->r, node);
    return 1;
  }
  TNode *FindNode_X(TNode *p, ItemType x)
  {
    if (!p) return NULL;
    if (p->info == x) return p;
    if (p->info > x) return FindNode_X(p->l, x);
    return FindNode_X(p->r, x);
  }
  BTree FindNode_X_All(TNode *p, ItemType x)
  {
    BTree t;
    init(t);
    if (!p) return t;
    if (p->info == x) insert(t.root, CreateTNode(x));
    FindNode_X_All(p->l, x);
    return FindNode_X_All(p->r, x);
  }
  void createBTree(BTree &t, char *FileName)
  {
    init(t);
    ItemType x;
    FILE *f;
    if (!(f=fopen(FileName, "r")))
    {
      printf("file khong ton tai\n");
      getch();
      exit(1);
    }
    while (!feof(f))
    {
      fscanf(f, "%d", &x);
      insert(t.root, CreateTNode(x));
    }
  }
  void show(TNode *p)
  {
    if (!p) return;
    printf("%4d", p->info);
    show(p->l);
    show(p->r);
  }
#endif // BTREE_H_
