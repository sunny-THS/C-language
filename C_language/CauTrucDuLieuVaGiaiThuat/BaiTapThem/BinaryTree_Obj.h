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
  class BTree {
    public:
      BTree() { root = NULL; } // init

      ~BTree() { }

      TNode *CreateTNode(ItemType x)
      {
        TNode *p = new TNode;
        if (!p)
        {
          printf("Khong du bo nho\n");
        }
        p->info = x;
        p->l = p->r = NULL;
        return p;
      }

      int insert(ItemType x)
      {
        return insert(root, CreateTNode(x));
      }
      TNode *FindNode_X(ItemType x)
      {
        return FindNode_X(x, root);
      }
      void createBTree(char *FileName)
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
          insert(x);
        }
      }
      void Show()
      {
        return Show(root);
      }
    private:
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
      TNode *FindNode_X(ItemType x, TNode *root)
      {
        if (!root) return NULL;
        if (root->info == x) return root;
        if (root->info < x) return FindNode_X(x, root->r);
        return FindNode_X(x, root->l);
      }
      void Show(TNode *p)
      {
        if (!p) return;
        printf("%4d", p->info);
        Show(p->l);
        Show(p->r);
      }
      TNode *root;
  };
#endif // BTREE_H_
