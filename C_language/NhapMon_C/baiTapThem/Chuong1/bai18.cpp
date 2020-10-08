#include<iostream>
using namespace std;
int demUocChan(int n) {
  int d=0;
  for (int i=1; i<=n/2; i++) {
    if (n%i == 0 && i%2==0) {
      d++;
    }
  }
  return d;
}
int main() {
  int n;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  cout << demUocChan(n);
  return 0;
}
