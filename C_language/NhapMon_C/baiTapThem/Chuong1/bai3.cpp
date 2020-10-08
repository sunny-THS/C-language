#include<iostream>
using namespace std;

int main() {
  int a, b, c;
  cout << "Nhap 3 canh cua tam giac: ";
  cin >> a >> b >> c;

  if (a<b+c && b<a+c && c<a+b) {
    if (a==b || a==c || b==c) {
      if (a==b && b==c) {
        cout << "Tam giac deu" << endl;
      }else if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b) {
        cout << "Tam giac vuong can" << endl;
      }else {
        cout << "Tam giac can" << endl;
      }
    }else if (a*a==b*b+c*c || b*b==c*c+a*a || c*c==b*b+a*a) {
      cout << "Tam giac vuong" << endl;
    }else if (a*a>b*b+c*c || b*b>a*a+c*c || c*c>a*a+b*b) {
      cout << "Tam gia tu" << endl;
    }else {
      cout << "Tam giac thuong" << endl;
    }
  }else {
    cout << "Khong phai 3 canh cua tam giac" << endl; 
  }

  return 0;
}
