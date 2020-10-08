#include<iostream>
using namespace std;
int kiemTra_N(int n) {
  if (n>5) {
    return n+=2;
  }
  return 0;
}
int main() {
  int n;
  cout << "Nhap n: ";
  cin >> n;
  cout << kiemTra_N(n);

  return 0;
}
