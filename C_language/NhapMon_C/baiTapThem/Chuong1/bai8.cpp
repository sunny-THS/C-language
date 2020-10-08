#include<iostream>
using namespace std;
int main() {
  int n, result = 0;
  do {
    cout << "Nhap n";
    cin >> n;
  } while(n<0);
  cout << "S(x)= ";
  for (int i = 0; i <= n; i++) {
    result += 2*i+1;
    cout << 2*i+1;
    if (i<n) {
      cout << '+';
    }
  }
  cout << "= " << result;

  return 0;
}
