#include<iostream>
#include<iomanip>
using namespace std;
int sum(int a) {
  static int b = 0;
  b+=a;
  return b;
}
int factorial(int a) {
  static int  b=1;
  b*=a;
  return b;
}
int main() {
  int n;
  float result;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  for (int i = 1; i <= n; i++) {
    result += sum(i)*1.0/factorial(i);
  }
  cout << setprecision(3) << result;
  return 0;
}
