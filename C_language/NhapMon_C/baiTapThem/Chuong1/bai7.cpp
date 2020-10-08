#include<iostream>
using namespace std;

int main() {
  int n, result=1;
  cout << "Nhap n: ";
  cin >> n;
  cout << "P(n)= ";
  for (int i = 0; i <= n; i++) {
    result *= 2*i+1;
    cout << 2*i+1;
    if (i<n) {
      cout << '*';
    }
  }
  cout << "= " << result;
  return 0;
}
