#include<iostream>

using namespace std;

int main() {
  int a, b, c, d, e, f, det, det_x, det_y;
  float x, y;
  cout << "nhap lan luot cac he so cua phuong trinh: ";
  cin >> a >> b >> e >> c >> d >> f;
  det = a*d - b*c;
  det_x = e*d - b*f;
  det_y = a*f - c*e;

  if (det == 0) {
    if (det_x==det_y && det_x==0) {
      cout << "phuong trinh vo so nghiem";
    }else {
      cout << "Phuong trinh vo nghiem";
    }
  }else {
    x = det_x*1.0/det;
    y = det_y*1.0/det;
    if (det_x%det==0) {
      cout.precision(0);
      cout << "x= " << fixed << x << endl;
    }else {
      cout.precision(2);
      cout << "x= " << fixed << x << endl;
    }
    if (det_y%det==0) {
      cout.precision(0);
      cout << "y= " << fixed << y;
    }else {
      cout.precision(2);
      cout << "y= " << fixed << y;
    }
  }

  return 0;
}
