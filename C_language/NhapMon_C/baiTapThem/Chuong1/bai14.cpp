#include<iostream>
using namespace std;
int pow(int x, int y) {
  int a=1;
  for (int i = 0; i < y; i++) {
    a *= x;
  }
  return a;
}
int main() {
  int x, y;
  cout << "Nhap x, y: ";
  cin >> x >> y;
  cout << pow(x, y);
  return 0;
}
