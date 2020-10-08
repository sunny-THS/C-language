#include<iostream>
using namespace std;
int Ucln(int a, int b) {
  int tmp;
  while (b!=0) {
    tmp = a%b;
    a = b;
    b = tmp;
  }
  return a;
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
