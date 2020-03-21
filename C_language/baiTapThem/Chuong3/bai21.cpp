#include<iostream>
using namespace std;
int kTTC(unsigned int a) {
  while (a!=0) {
    if (a%10%2!=0) {
      return 0;
    }
    a/=10;
  }
  return 1;
}
int kTTL(unsigned int a) {
  while (a!=0) {
    if (a%10%2==0) {
      return 0;
    }
    a/=10;
  }
  return 1;
}
int returnResult(unsigned int a) {
  if (kTTC(a)) {
    return 1;
  }
  if (kTTL(a)) {
    return -1;
  }
  return 0;
}
int lenNum_K(unsigned int a) {
  int d=0;
  while (a!=0) {
    a/=10;
    d++;
  }
  if (d>0&&d<=5) {
    return 0;
  }
  return 1;
}
int main() {
  unsigned int a;
  do {
    cout << "Nhap n: ";
    cin >> a;
  } while(lenNum_K(a));
  unsigned int tmp = returnResult(a);
  if (tmp == 1) {
    cout << "So toan chan";
  }else if (tmp == -1){
    cout << "So toan le";
  }else {
    cout << "truong hop khac";
  }
  return 0;
}
