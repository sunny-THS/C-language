#include<iostream>
using namespace std;
template<class Type>
//

//
///    bug

//
///
class Max_Min {
  private:
    Type a, b;
  public:
    Max_Min(int a, int b): a(a), b(b) { };
    Max_Min(float a, float b): a(a), b(b) { };
    Type getMax() {
      return a>b?a:b;
    }
    Type getMin() {
      return a<b?a:b;
    }
    void printMaxMin() {
      cout << "Max: " << getMax() << endl;
      cout << "Min: " << getMin() << endl;
    }
};
template<class Type>
int main() {
  Type a, b;
  cout << "Nhap a, b: ";
  cin >> a >> b;

  return 0;
}
