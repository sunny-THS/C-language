#include<iostream>
#include<math.h>
using namespace std;

int Sum(int x, int y) {
  return x + y;
}
int Sub(int x, int y) {
  return x - y;
}
int Mul(int x, int y) {
  return x * y;
}
float Div(int x, int y) {
  float a = x;
  return a / y;
}
int main() {
  int x, y;
  cout << "Nhap 2 so x, y: ";
  cin >> x >> y;
  cout << "Ket qua la: " <<endl;
  cout << "x + y= " << Sum(x, y) << endl;
  cout << "x - y= " << Sub(x, y) << endl;
  cout << "x * y= " << Mul(x, y) << endl;
  cout << "x / y= " << floorf(Div(x, y)) << endl;
  return 0;
}
