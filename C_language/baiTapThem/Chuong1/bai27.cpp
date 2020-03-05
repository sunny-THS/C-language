#include<iostream>
#include<iomanip>
using namespace std;
int factorial(int a) {
  static int b = 1;
  b*=a;
  return b;
}
int main() {
  int n;
  float result=0;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  for (int i=1; i<=n; i++) {
    result += 1.0/factorial(i);
  }
  cout << setprecision(3) << result;
  return 0;
}
