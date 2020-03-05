#include<iostream>
using namespace std;
int kTSHT(int a) {
  int t=0;
  for (int i = 1; i <= a/2; i++) {
    if (a%i==0) {
      t+=i;
    }
  }
  if (t==a) {
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
  if (kTSHT(n)) {
    cout << "So hoan thien";
  }else {
    cout << "khong phai la so hoan thien";
  }
  return 0;
}
