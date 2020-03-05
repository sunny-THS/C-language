#include<iostream>
using namespace std;
int vT_MAX(int a, int& max) {
  int i = 0, vt=i, tmp;
  max = a%10;
  while (a!=0) {
    a/=10;
    i++;
    tmp = a%10;
    if (max<tmp && vt!=i) {
      max = tmp;
      vt = i;
    }
  }
  return vt;
}
int main() {
  int n, max;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<100&&n>999);
  switch (vT_MAX(n, max)) {
    case 0: cout<<"Chu so lon nhat nam o hang don vi("<<max<<')'; break;
    case 1: cout<<"Chu so lon nhat nam o hang chuc("<<max<<')'; break;
    case 2: cout<<"Chu so lon nhat nam o hang tram("<<max<<')'; break;
  }
  return 0;
}
