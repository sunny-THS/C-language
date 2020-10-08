#include<iostream>
#include<iomanip>
using namespace std;
float fraction(int n) {
  return 1.0/n;
}
int main() {
  int n;
  float result=0;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  cout << "S(x)= ";
  for (int i = 1; i <= n; i++) {
    result += fraction(i);
    if (i == 1) {
      cout << i;
    }else {
      cout << "1/" << i;
    }
    if (i<n) {
      cout << " + ";
    }
  }
  cout << "= " << setprecision(3) << result;
  return 0;
}
