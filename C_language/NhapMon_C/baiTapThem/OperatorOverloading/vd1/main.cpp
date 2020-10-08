#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct sinhVien {
  string mssv;
  string tenSv;
  float diem;
};
typedef struct sinhVien SINHVIEN;
void nhap_Thong_Tin_SV(SINHVIEN &sv) {
  fflush(stdin);
  cout << "Nhap mssv: ";
  getline(cin, sv.mssv);

  fflush(stdin);
  cout << "Nhap ten sinh vien: ";
  getline(cin, sv.tenSv);

  cout << "Nhap diem: ";
  cin >> sv.diem;
}
void xuat_Thong_Tin_1_Sv(SINHVIEN sv) {
  cout << "Ma so sinh vien: " << sv.mssv << endl;
  cout << "Ten sinh vien: " << sv.tenSv << endl;
  cout << "Diem: " << sv.diem;
}
// operator overloading
istream& operator >> (istream &in, SINHVIEN &sv) {
  fflush(stdin);
  cout << "Nhap mssv: ";
  getline(in, sv.mssv);

  fflush(stdin);
  cout << "Nhap ten sinh vien: ";
  getline(in, sv.tenSv);

  cout << "Nhap diem: ";
  in >> sv.diem;
  return in;
}
ostream& operator << (ostream &out, SINHVIEN sv) {
  out << "Ma so sinh vien: " << sv.mssv << endl;
  out << "Ten sinh vien: " << sv.tenSv << endl;
  out << "Diem: " << sv.diem;
  return out;
}

int main() {
  SINHVIEN sv;
  cout << "\n\n\t\tNHAP THONG TIN SINH VIEN" << endl;
  // nhap_Thong_Tin_SV(sv);
  cin >> sv;
  cout << "\n\n\t\tXUAT THONG TIN SINH VIEN" << endl;
  // xuat_Thong_Tin_1_Sv(sv);
  cout << sv;

  return 0;
}
