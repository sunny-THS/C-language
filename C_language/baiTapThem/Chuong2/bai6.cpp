#include<iostream>
using namespace std;

int main() {
  int a, b, c, tmp;
  cout << "Nhap a, b, c: ";
  cin >> a >> b >> c;
  if (a>b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  if (a>c) {
    tmp = a;
    a = c;
    c = tmp;
  }
  if (b>c) {
    tmp = b;
    b = c;
    c = tmp;
  }
  cout << "Thu tu: "<<a<<','<<b<<','<<c;
  return 0;
}
