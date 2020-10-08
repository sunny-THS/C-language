#include<iostream>
using namespace std;
int square(int a) {
  return a*a;
}
int main() {
  int n, result=0;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  cout << "S(x)= ";
  for (int i = 1; i <= n; i++) {
    result += square(i);
    cout << i << "^2 ";
    if (i<n) {
      cout << "+ ";
    }
  }
  cout << "= " << result;

  return 0;
}
