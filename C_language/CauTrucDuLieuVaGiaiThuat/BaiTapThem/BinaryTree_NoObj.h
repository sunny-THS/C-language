#ifndef BTREE_H_
  #define BTREE_H_
  #include <stdio.h>
  #include <conio.h> // getch()
  #include <stdlib.h> // exit()
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
  TNode CreateTNode (ItemType x)
  {
    TNode *p = new TNode;
    if (!p) return NULL;
    p->info = x;
    p->l = p->r = NULL;
    return p;
  }

#endif // BTREE_H_
