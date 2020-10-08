#include<iostream>
#include<iomanip>
using namespace std;
int s(int n) {
  static int a = 0;
  a += n;
  return a;
}
int main() {
  int n;
  float result;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  for (int i = 1; i <= n; i++) {
    result += 1.0/s(i);
  }
  cout << setprecision(3) << result;
  return 0;
}
