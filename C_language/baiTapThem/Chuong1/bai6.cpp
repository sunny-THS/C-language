#include<iostream>
using namespace std;
int factorial(int n) {
  if (n==1) {
    return n;
  }
  return n * factorial(n-1);
}
int main() {
  int n;
  do {
    cout << "Nhap so giai thua: ";
    cin >> n;
  } while(n<0);
  cout << n << "!= " << factorial(n);

  return 0;
}
