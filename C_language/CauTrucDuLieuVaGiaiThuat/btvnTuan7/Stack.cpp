#include "Stack.h"

void *Stack::createNode(ItemType x)
{
  StackNode *p_ = new StackNode;
  if (!p)
  {
    printf("Khong du bo nho\n");
    return NULL;
  }
  p_->info = x;
  p_->info = NULL;
  return p_;
}
void Stack::push(ItemType x)
{
  init();
  StackNode *p_ = createNode(x);
  if(this->top) p_->next = this->top;
  this->top = p_;
}
ItemType Stack::pop()
{
  StackNode *p_ = this->top;
  ItemType x;
  if (!p_) {
    printf("Error\n");
    return '\0';
  }
  this->top = p_->next;
  x = p_->info;
  delete p_;
  return x;
}
ItemType Stack::peek()
{
  StackNode *p_ = this->top;
  if (!p_) {
    printf("Error\n");
    return '\0';
  }
  return p_->info;
}
