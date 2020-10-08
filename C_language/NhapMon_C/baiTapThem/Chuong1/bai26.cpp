#include<iostream>
#include<iomanip>
using namespace std;

int main() {
  int n;
  float result=0;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  for (int i = 1; i<=n; i++) {
    result += i/(i+1.0);
  }
  cout << setprecision(3) << result;
  return 0;
}
