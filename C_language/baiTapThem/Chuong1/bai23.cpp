#include<iostream>
#include<cmath>
using namespace std;
int kTSCP(int a) {
  int t = sqrt(a*1.0);
  if (t*t == a) {
    return 1;
  }
  return 0;
}
int main() {
  int n;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  if (kTSCP(n)) {
    cout << "So chinh phuong";
  }else {
    cout << "Khong phai so chinh phuong";
  }

  return 0;
}
