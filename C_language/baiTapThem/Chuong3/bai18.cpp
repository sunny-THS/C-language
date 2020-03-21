#include<iostream>
#include<cmath>
using namespace std;
int kTSNT(unsigned int a) {
  if (a<2) {
    return 0;
  }
  for (int i = 2; i < sqrt(a); i++) {
    if (a%i==0) {
      return 0;
    }
  }
  return 1;
}
int demSNT(unsigned int a) {
  int d=0;
  while (a!=0) {
    if (a%10) {
      d++;
    }
    a/=10;
  }
  return d;
}
int lenNum_K (unsigned int a) {
  int d=0;
  while (a!=0) {
    a/=10;
    d++;
  }
  if (d<0&&d>=5) {
    return 1;
  }
  return 0;
}
int main() {
  unsigned int a;
  do {
    cout << "Nhap n: ";
    cin >> a;
  } while(lenNum_K(a));
  cout << "So nguyen to: " << demSNT(a);
  return 0;
}
