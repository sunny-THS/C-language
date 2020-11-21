#ifndef STACK_H_
  #define STACK_H_
  #include <iostream>
  #include <cstdio>
  #include <conio.h>
  #include <cstdlib>
  using namespace std;

  template <class ItemType>
  class Stack {
    struct StackNode {
      ItemType info;
      StackNode *next;
    };
    private:
      StackNode *top;
    public:
      Stack() { top = NULL; }
      bool is_Empty() { return !top?true:false; }
      StackNode *createNode(ItemType x)
      {
        StackNode *p_ = new StackNode;
        if (!p_)
        {
          cout << "Khong du bo nho\n";
          return NULL;
        }
        p_->info = x;
        p_->next = NULL;
        return p_;
      }
      void push(ItemType x)
      {
        StackNode *p_ = createNode(x);
        if(this->top) p_->next = this->top;
        this->top = p_;
      }
      ItemType pop()
      {
        StackNode *p_ = this->top;
        ItemType x;
        if (!p_) {
          cout << "Error\n";
          return '\0';
        }
        this->top = p_->next;
        x = p_->info;
        delete p_;
        return x;
      }
      ItemType peek()
      {
        StackNode *p_ = this->top;
        if (!p_) {
          cout << "Error\n";
          return '\0';
        }
        return p_->info;
      }
      void showStack()
      {
        StackNode *p_ = top;
        while (p_)
        {
          cout << p_->info << ' ';
          p_ = p_->next;
        }
      }
  };

#endif //STACK_H_
