#include <iostream>
using namespace std;
struct phanSo {
  int tu;
  int mau;
};
typedef struct phanSo PS;
void Nhap_PS(PS &ps) {
  cout << "Nhap tu so: ";
  cin >> ps.tu;
  cout << "Nhap mau so: ";
  cin >> ps.mau;
}
void Xuat_PS(PS ps) {
  cout << ps.tu << "/" << ps.mau;
}
PS Sum(PS ps1, PS ps2) {
  PS result;
  result.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
  result.mau = ps1.mau*ps2.mau;
  return result;
}
int Ucln(int a, int b) {
  if (a==0||b==0) {
    return a+b;
  }
  while (a*b!=0) {
    if (a>b) {
      a%=b;
    }else {
      b%=a;
    }
  }
  return a+b;
}
void toi_Gian_PS(PS &ps) {
  int a = Ucln(ps.tu, ps.mau);
  ps.tu/=a;
  ps.mau/=a;
}
// operator overloading
PS operator + (PS ps1, PS ps2) {
  PS result;
  result.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
  result.mau = ps1.mau*ps2.mau;
  return result;
}
istream& operator >> (istream &in, PS &ps) {
  cout << "Nhap tu so: ";
  in >> ps.tu;
  cout << "Nhap mau so: ";
  in >> ps.mau;
  cout << endl;
  return in;
}
ostream& operator << (ostream &out, PS ps) {
  out << ps.tu*1.0/ps.mau << " = " << ps.tu << "/" << ps.mau ;
  return out;
}

int main() {
  cout << Ucln(4, 1);
  PS ps1;
  PS ps2;
  PS ps3;
  // Nhap_PS(ps1);
  // Nhap_PS(ps2);
  // Nhap_PS(ps3);
  cin >> ps1 >> ps2 >> ps3;
  // PS x = Sum(ps1, ps2);
  PS x = ps1 + ps2 + ps3;
  toi_Gian_PS(x);
  cout << x;

  return 0;
}
