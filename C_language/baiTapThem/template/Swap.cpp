#include<iostream>
using namespace std;
template <class /*hoac dung typename*/ Type>
class SetValue {
  private:
    Type a, b;
  public:
    SetValue(Type a, Type b): a(a), b(b) { }
    void Swap() {
      Type t = this->a;
      this->a = this->b;
      this->b = t;
    }
    void print() {
      cout << a << ", " << b << endl;
    }
};
int main() {
  int a, b;
  cout << "Nhap a, b: ";
  cin >> a >> b;
  SetValue<int> setValue(a, b);
  setValue.print();
  setValue.Swap();
  setValue.print();
  return 0;
}
