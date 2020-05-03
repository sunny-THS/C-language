#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  a^=b;
  b^=a;
  a^=b;
}
int main() {
  int a, b;
  cout << "Nhap a, b: ";
  cin >> a >> b;
  cout << "\na = " << a << " | " << "b = " << b;
  swap(a, b);
  cout << "\na = " << a << " | " << "b = " << b;
  return 0;
}
