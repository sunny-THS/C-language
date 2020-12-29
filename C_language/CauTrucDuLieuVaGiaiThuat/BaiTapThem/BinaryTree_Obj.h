#ifndef BTREE_H_
  #define BTREE_H_
  #include <stdio.h>
  #include <conio.h>
  #include <stdlib.h>
  template <class ItemType>
  struct TNode
  {
    ItemType info;
    TNode *left;
    TNode *right;
  };
  template <class ItemType>
  class BTree
  {
    public:
      BTree() { root = NULL; }
      TNode<ItemType> *GetTNode() { return root; }
      TNode<ItemType> *CreateTNode(ItemType x)
      {
        TNode<ItemType> *p = new TNode<ItemType>;
        if (!p)
        {
          printf("Khong du bo nho\n");
          getch();
          return NULL;
        }
        p->info = x;
        p->left = NULL;
        p->right = NULL;
        return p;
      }
      int insert(ItemType x, int(*check)(const void*, const void*))
      {
         return insert(root, CreateTNode(x), check);
      }
      int deleted( ,int(*check)(const void*))
      {
        return deleted(root, check);
      }
      void show(void(*showNode)(const void*))
      {
        return show(root, showNode);
      }
    private:
      int deleted(TNode *&root, int(*check)(const void*, const void*))
      {
        if (!root) return 0;
        int c = check(root-, )
      }
      void show(TNode<ItemType> *root, void(*showNode)(const void*))
      {
        if (!root) return;
        showNode(root);
        show(root->left, showNode);
        show(root->right, showNode);
      }
      int insert(TNode<ItemType> *&root, TNode<ItemType> *x, int(*check)(const void*, const void*))
      {
        if (!x) return 0;
        if (!root)
        {
          root = x;
          return 1;
        }
        int c = check(root, x);
        if (c == 0) return 0;
        return c > 0 ? insert(root->right, x, check) : \
                       insert(root->left, x, check);
      }
      TNode<ItemType> *root;
  };
#endif // BTREE_H_
