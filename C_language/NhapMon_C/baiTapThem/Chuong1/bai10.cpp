#include<iostream>
using namespace std;
int factorial(int n) {
  static int a = 1;
  a *= n;
  return a;
}
int main() {
  int n, result=0;
  do {
    cout << "Nhap n: ";
    cin >>  n;
  } while(n<=0);
  cout << "S(n)= ";
  for (int i = 1; i <= n; i++) {
    result += factorial(i);
    cout << i << '!';
    if (i<n) {
      cout << '+';
    }
  }
  cout << "= " << result;

  return 0;
}
