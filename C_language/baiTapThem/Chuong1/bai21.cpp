#include<iostream>
using namespace std;
int Ucln(int a, int b) {
  return b ? Ucln(b, a%b) : a;
}
int main() {
  int x, y, result;
  do {
    cout << "Nhap x, y: ";
    cin >> x >> y;
  } while(x<0 || y<0);
  result = (x/Ucln(x,y)) * y;
  cout << "LCM("<<x<<", "<<y<<")= "<<result;

  return 0;
}
