#include "Stack.h"
#include "InfixToPostfix.h"

int main()
{
  InfixToPostfix a;
  a.inputInfix();
  a.ConvertPostfix();
  a.showPostfix();
  a.resultOfPostfix();
  return 1;
}
