#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct MonHoc {
  string ten;
  float diem;
};
typedef struct MonHoc MONHOC;
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
  short int len = ds_SV.size();
  for (size_t i = 0; i < len; i++) {
    if (stricmp(ten_SV.c_str(), ds_SV[i].hoTen.c_str())==0) {
      cout << "\n\t\tThong tin sinh vien" << endl;
      Xuat_TT_1_SV(ds_SV[i]);
      cout << "\n\t\t- DANH SACH MON HOC -" << endl;
      for (size_t j = 0; j < ds_SV[i].dsMonHoc.size(); j++) {
        Xuat_MonHoc_1_SV(ds_SV[i].dsMonHoc[j]);
      }
      cout << "\n===================================================\n";
    }
  }
}
string Tach_NamSinh(string str) {
  string tmp;
  short int index = str.length()-1;
  while (str[index]>='0'&&str[index]<='9') {
    tmp.insert(tmp.begin() + 0, str[index]);
    index--;
  }
  return tmp;
}
void Ghi_TT_MonHoc(fstream &fileout, MONHOC monHoc) {
  fileout << monHoc.ten << '-' << monHoc.diem;
}
void Ghi_TT_SV(fstream &fileout, SINHVIEN sv) {
  short int len = sv.dsMonHoc.size();
  fileout << sv.hoTen << ',' << sv.maSo << ',' << sv.ngaySinh << endl;
  fileout << sv.dsMonHoc.size() << endl;
  for (size_t i = 0; i < len; i++) {
    Ghi_TT_MonHoc(fileout, sv.dsMonHoc[i]);
    if (i<len-1) {
      fileout << endl;
    }
  }
}
void Luu_File_NamSinh(fstream &fileout, vector<SINHVIEN> ds, string namSinh) {
  short int d = 0;
  for (size_t i = 0; i < ds.size(); i++) {
    string tmp = Tach_NamSinh(ds[i].ngaySinh);
    if (stricmp(tmp.c_str(), namSinh.c_str())==0) {
      d++;
    }
  }
  for (size_t i = 0; i < ds.size(); i++) {
    string tmp = Tach_NamSinh(ds[i].ngaySinh);
    if (stricmp(tmp.c_str(), namSinh.c_str())==0) {
      Ghi_TT_SV(fileout, ds[i]);
      d--;
      if (d!=0) {
        fileout << endl;
      }
    }
  }
}

int main() {
  vector<SINHVIEN> ds_SV;
  // Cau 1
  fstream filein;
  filein.open("SINHVIEN.txt", ios::in);
  Doc_File(filein, ds_SV);
  // Xuat_TT_SV(ds_SV);
  // Cau 2
  string name;
  cout << "\nNhap ten sinh vien can tim: ";
  getline(cin, name);
  Xuat_TT_SV_Theo_Ten(ds_SV, name);
  // Cau 3
  fstream fileout;
  fileout.open("NAMSINH.txt", ios::out);
  string namSinh;
  cout << "Nhap nam sinh: ";
  getline(cin, namSinh);
  Luu_File_NamSinh(fileout, ds_SV, namSinh);
  fileout.close();
  filein.close();
  return 0;
}
