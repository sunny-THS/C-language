#include<iostream>
using namespace std;
int sum(int a) {
  static int b = 0;
  b+=a;
  return b;
}
int main() {
  int n, result=0;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  for (int i = 0; i<=n; i++) {
    result += sum(i);
  }
  cout << result;

  return 0;
}
