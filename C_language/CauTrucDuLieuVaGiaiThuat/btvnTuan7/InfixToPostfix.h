#ifndef INFIXTOPOSTFIX_H_
  #define INFIXTOPOSTFIX_H_
  #include "Stack.h"
  #include <string.h>
  #include <cmath>
  #define SIZE 50
  class InfixToPostfix
  {
    private:
      Stack<char> root_;
      Stack<float> evaluatePostfix_;
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
            if (Infix_[i_Infix+2] == '\0') break;
            Postfix_[i_Postfix++] = ' '; // dinh dang cho dep
            x = root_.pop();
            while (is_operator(x) && precedence(x) >= precedence(item)) {
              Postfix_[i_Postfix++] = x;
              x = root_.pop();
            }
            root_.push(x);
            root_.push(item);
            Postfix_[i_Postfix++] = ' ';// tach so hang khi gap toan tu
          }else if (item == ')') {
            x = root_.pop();
            while (x != '(') {
              Postfix_[i_Postfix++] = ' ';// dinh dang cho dep
              Postfix_[i_Postfix++] = x;
              x = root_.pop();
            }
          }else {
            cout << "\nInvalid infix Expression.\n";
            getch();
            exit(1);
          }
          item = Infix_[++i_Infix];
        } // end while loop
        if (!root_.is_Empty()) {
          cout << "\nInvalid infix Expression.\n";
          getch();
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
        printf("Postfix: %s\n", Postfix_);
      }
      float evaluatePostfix()
      {
        if (!is_characters(Postfix_[0])) throw "Fail!";
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
            float val1 = evaluatePostfix_.pop();
            float val2 = evaluatePostfix_.pop();
            float tmp;
            switch (Postfix_[i]) {
              case '+': tmp = val2 + val1; break;
              case '-': tmp = val2 - val1; break;
              case '*': tmp = val2 * val1; break;
              case '/': tmp = val2 / val1; break;
              case '^': tmp = pow(val2, val1);
            }
            evaluatePostfix_.push(tmp);
          }else throw "Fail! Press any key to continue . . .";
        }// end for loop
        return evaluatePostfix_.pop();
      }
      void resultOfPostfix()
      {
        try
        {
          printf("Result: %.2f\n", evaluatePostfix());
        }
        catch(const char *msg)
        {
          printf("Result: %s\n", msg);
        }
      }
  };
#endif //INFIXTOPOSTFIX_H_
