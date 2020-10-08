#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
float result(int a) {
  static int i=0;
  ++i;
  if (i==a) {
    return sqrt(a*1.0);
  }
  return sqrt(1.0*i+result(a));
}
int main() {
  int n;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  cout << setprecision(3) << result(n);
  return 0;
}
