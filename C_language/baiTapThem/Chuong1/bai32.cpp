#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float result(int a) {
  if (a==1) {
    return 1;
  }
  return sqrt(a+result(a-1)*1.0);
}
int main() {
  int n;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  cout << setprecision(3) << result(n);
  return 0;
}
