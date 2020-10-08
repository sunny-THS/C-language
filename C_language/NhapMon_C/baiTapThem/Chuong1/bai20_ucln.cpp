#include<iostream>
using namespace std;

int Ucln(int x, int y) {
  // cach 1
  if (x == 0 || y == 0) {
    return x+y;
  }
  while (x != y) {
    if (x < y) {
      y-=x;
    }else {
      x-=y;
    }
  }
  return x;
  // cach 2//
  // dung thuat toan Euclid
  // de qui
  // return b ? Ucln(b, a%b) : a;
  // a%b la so du cua a va b
  // dung vong lap
  // int tmp;
  // while (b!=0) {
  //   tmp = a%b;// lay phan du
  //   a = b;
  //   b = tmp;
  // }
  // return a;
  // cach 3 //
  //
  // while (x*y!=0) {
  //   if (x<y) {
  //     y%=x;
  //   }else {
  //     x%=y
  //   }
  // }
  // return x+y;
}
int main() {
  int a, b;
  do {
    cout << "Nhap a, b: ";
    cin >> a >> b;
  } while(a < 0 || b < 0);
  cout << "GCD(" << a << ", "<< b << ")= " << Ucln(a, b);

  return 0;
}
