#include<iostream>
using namespace std;
int Ucln(int a, int b) {
  return b ? Ucln(a, a%b) : a;
}
int main() {
  int x, y;
  do {
    cout << "Nhap x, y: ";
    cin >> x >> y;
  } while(x<0 || y<0);


  return 0;
}
