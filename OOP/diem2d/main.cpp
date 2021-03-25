#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Diem2D {
  float x;
  float y;
};

Diem2D nhapDiem2D(vector<Diem2D> &d, int i = -1) {
  float x, y;
  if (i!=-1)
    cout << "Nhap diem thu " << i+1 << endl;
  cout << "dx = ";
  cin >> x;
  cout << "dy = ";
  cin >> y;
  d.push_back({x, y});
}

void nhapdsDiem2D(vector<Diem2D> &d, int &n) { // bai 4b
  cout << "Nhap so diem 2d: ";
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    nhapDiem2D(d, i);
  }
}
void SetDiem(vector<Diem2D> &d, float x=0, float y=0) {
  d.push_back( { x, y } );
}

void nhapSetDiem2D(vector<Diem2D> &d, int &n) { // bai 5
  float x, y;
  cout << "Nhap so diem 2d: ";
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    if(i%3==0) {
      cout << "\nNhap dx: ";
      cin >> x;
      cout << "Nhap dy: ";
      cin >> y;
      SetDiem(d, x, y);
    }else if(i%3==1) {
      cout << "\nNhap dx: ";
      cin >> x;
      SetDiem(d, x);
    }else if(i%3==2)
      SetDiem(d);
  }
}

void xuatDiem2D(Diem2D d) {
  cout << " { " << d.x << ", " << d.y << " }" << endl;
}
void xuatdsDiem2D(vector<Diem2D> d) {
  cout << "\nCac diem 2d"<< endl;
  for (auto dd : d) {
    xuatDiem2D(dd);
  }
}

float khoangCach(Diem2D d1, Diem2D d2) {
  return sqrt( pow( (d1.x - d2.x), 2) + pow( (d1.y - d2.y), 2) );
}

void xuat2D_KhoangCach_Max (vector<Diem2D> d) {
  float max = khoangCach(d[0], d[1]);
  Diem2D d1, d2;
  for (size_t i = 0; i < d.size()-1; i++) {
    for (size_t j = i+1; j < d.size(); j++) {
      float kc = khoangCach(d[i], d[j]);
      if (max < kc) {
        max = kc;
        d1 = d[0];
        d2 = d[j];
      }
    }
  }
  cout << "2 diem co khoang cach lon nhat: " << endl;
  xuatDiem2D(d1);
  xuatDiem2D(d2);
}

int main() {
  vector<Diem2D> d;
  int n;
  // nhapdsDiem2D(d, n); // bai 4b
  nhapSetDiem2D(d, n);
  xuatdsDiem2D(d);
  xuat2D_KhoangCach_Max(d);
  return 0;
}
