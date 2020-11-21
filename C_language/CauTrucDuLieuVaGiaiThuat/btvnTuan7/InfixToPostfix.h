#ifndef INFIXTOPOSTFIX_H_
  #define INFIXTOPOSTFIX_H_
  #include "Stack.h"
  #include <string.h>
  #define SIZE 50
  class InfixToPostfix
  {
    private:
      Stack<char> root_;
      Stack<int> evaluatePostfix_;
      char Infix_[SIZE];
      char Postfix_[SIZE];
    public:
      InfixToPostfix() { }
      void inputInfix()
      {
        cout << "infix: ";
        cin >> Infix_;
      }
      bool is_operator(char sb)
      {
        if (sb=='^' || sb=='+' || sb=='-' || sb=='*' || sb=='/') return true;
        return false;
      }
      bool is_digit(char c)
      {
        if ( c>='0' && c<='9' ) return true;
        return false;
      }
      bool is_alpha(char c)
      {
        if ( (c>='a'&&c<='z') || \
             (c>='A'&&c<='Z') \
           ) return true;
        return false;
      }
      bool is_characters(char c)
      {
        if ( is_alpha(c) || is_digit(c) ) return true;
        return false;
      }
      int precedence(char sb)
      {
        if (sb=='^') return 3;
        if(sb=='*' || sb=='/') return 2;
        if(sb=='+' || sb=='-') return 1;
        return 0;
      }
      void ConvertPostfix()
      {
        int i_Infix=0, i_Postfix=0;
        char x;
        root_.push('(');
        strcat(Infix_, ")");
        char item = Infix_[i_Infix];
        while (item != '\0') {
          if (item == '(') {
            root_.push(item);
          }else if (is_characters(item)) {
            Postfix_[i_Postfix++] = item;
          }else if (is_operator(item)) {
            x = root_.pop();
            while (is_operator(x) && precedence(x) >= precedence(item)) {
              Postfix_[i_Postfix++] = x;
              x = root_.pop();
            }
            root_.push(x);
            root_.push(item);
          }else if (item == ')') {
            x = root_.pop();
            while (x != '(') {
              Postfix_[i_Postfix++] = x;
              x = root_.pop();
            }
          }else {
            cout << "\nInvalid infix Expression.\n";
            getchar();
            exit(1);
          }
          Postfix_[i_Postfix++] = ' ';
          item = Infix_[++i_Infix];
        } // end while loop
        if (!root_.is_Empty()) {
          cout << "\nInvalid infix Expression.\n";
          getchar();
          exit(1);
        }
        Postfix_[i_Postfix] = '\0';
      }
      char *getPostfix()
      {
        return Postfix_;
      }
      void showPostfix()
      {
        printf("%s\n", Postfix_);
      }
      int evaluatePostfix()
      {
        if (!is_characters(Postfix_[0])) return -1;
        size_t i = 0;
        for (; Postfix_[i]; i++) {
          if (Postfix_[i] == 32) continue;
          else if (is_digit(Postfix_[i])) {
            int a = 0;
            while (is_digit(Postfix_[i])) {
              a = a*10 +(Postfix_[i] - '0');
              i++;
            }
            i--;
            evaluatePostfix_.push(a);
          }else if (is_operator(Postfix_[i])) {
            int val1 = evaluatePostfix_.pop();
            int val2 = evaluatePostfix_.pop();
            int tmp;
            switch (Postfix_[i]) {
              case '+': tmp = val2 + val1; break;
              case '-': tmp = val2 - val1; break;
              case '*': tmp = val2 * val1; break;
              case '/': tmp = val2 / val1; break;
            }
            evaluatePostfix_.push(tmp);
          }else return -1;
        }// end for loop
        return evaluatePostfix_.pop();
      }
      void resultOfPostfix()
      {
        printf("Result: %d\n", evaluatePostfix());
      }
  };
#endif //INFIXTOPOSTFIX_H_
