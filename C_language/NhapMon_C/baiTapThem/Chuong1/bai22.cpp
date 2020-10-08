#include<iostream>
#include<cmath>
using namespace std;
int Kt_SNT(int a) {
  if (a < 2) {
    return 0;
  }
  for (int i = 2; i<= sqrt(a*1.0); i++) {
    if (a%i==0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int n;
  do {
    cout << "Nhap so nguyen: ";
    cin >> n;
  } while(n<0);
  if (Kt_SNT(n)) {
    cout << "So nguyen to";
  }else {
    cout << "khong phai so nguyen to";
  }
  return 0;
}
