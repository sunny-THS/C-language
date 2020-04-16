#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct MonHoc {
  string ten;
  float diem;
};
typedef struct MonHoc MONHOC;
struct TenSV {
  string ho, tenDem, ten;
};
typedef struct TenSV TENSV;
struct SinhVien {
  string hoTen, maSo, ngaySinh;
  vector<MONHOC> dsMonHoc;
};
typedef struct SinhVien SINHVIEN;

void Nhap_TT_1_SV(fstream &filein, SINHVIEN &sinhVien) {
  // getline(istream& is, string& str, char delim);
  getline(filein, sinhVien.hoTen, ',');
  getline(filein, sinhVien.maSo, ',');
  getline(filein, sinhVien.ngaySinh);
}
void Nhap_MonHoc_1_SV(fstream &filein, MONHOC &monhoc) {
  getline(filein, monhoc.ten, '-');
  filein >> monhoc.diem;
}
void Doc_File(fstream &filein, vector<SINHVIEN> &ds_sinhVien) {
  while (!filein.eof()) {
    string tmp;
    SINHVIEN sinhVien;
    Nhap_TT_1_SV(filein, sinhVien);
    int n;
    filein >> n;
    getline(filein, tmp);
    for (size_t i = 0; i < n; i++) {
      MONHOC monHoc;
      Nhap_MonHoc_1_SV(filein, monHoc);
      sinhVien.dsMonHoc.push_back(monHoc);
      getline(filein, tmp);
    }
    ds_sinhVien.push_back(sinhVien);
  }
}
// =========== TEST ===================
void Xuat_TT_1_SV(SINHVIEN sinhVien) {
  cout << "Ho va ten: " << sinhVien.hoTen << endl;
  cout << "Ma So Sinh Vien: " << sinhVien.maSo << endl;
  cout << "Ngay sinh: " << sinhVien.ngaySinh;
}
void Xuat_MonHoc_1_SV(MONHOC monHoc) {
  cout << "Ten mon hoc: " << monHoc.ten;
  cout << " -\t" << monHoc.diem << "d"<< endl;
}
void Xuat_TT_SV(vector<SINHVIEN> ds_sv) {
  for (size_t i = 0; i < ds_sv.size(); i++) {
    cout << "\n\t\tSINH VIEN THU " << i+1 << endl;
    Xuat_TT_1_SV(ds_sv[i]);
    cout << "\n\t\t- DANH SACH MON HOC -" << endl;
    for (size_t j = 0; j < ds_sv[i].dsMonHoc.size(); j++) {
      Xuat_MonHoc_1_SV(ds_sv[i].dsMonHoc[j]);
    }
    cout << "\n===================================================\n";
  }
}
void Xuat_TT_SV_Theo_Ten(vector<SINHVIEN> ds_SV, string ten_SV) {
  for (size_t i = 0; i < ds_SV.size(); i++) {
    TENSV tenSV;
    vector<TenSV> ten_1_SV;
    char *token = strtok(ten_1_SV[i].hoTen, " ");
    while (token != NULL) {
      
    }
  }
}
int main() {
  vector<SINHVIEN> ds_SV;
  fstream filein;
  filein.open("SINHVIEN.txt", ios::in);
  Doc_File(filein, ds_SV);
  filein.close();
  Xuat_TT_SV(ds_SV);
  return 0;
}
