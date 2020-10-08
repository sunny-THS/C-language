#include<iostream>
using namespace std;

int main() {
  int n, result=0, a=1;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  cout << "S(x)= ";
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++)
      a *= -1;
    result += i*a;
    cout << a*i;
    if (i%2==0 && i<n) {
      cout << '+';
    }
    a=1;
  }
  cout << "= " << result;

  return 0;
}
