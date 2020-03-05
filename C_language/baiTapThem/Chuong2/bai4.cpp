#include<iostream>
using namespace std;

int main() {
  int a, b, max;
  cout << "Nhap a, b: ";
  cin >> a >> b;
  max = a>b ? a : b;
  cout << "Max: " << max;
  return 0;
}
