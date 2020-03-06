#include<iostream>
using namespace std;

int kT_NamNhuan(int y) {
  if (y%400==0 || y%4==0 && y%100!=0) {
    return 1;
  }
  return 0;
}
int kT_Date(int d, int m, int y) {
  switch (m) {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
    {
      if (d<=31) {
        return 1;
      }
      return 0;
    }
    case 4:case 6:case 9:case 11:
    {
      if (d<=30) {
        return 1;
      }
      return 0;
    }
    case 2:
    {
      if (kT_NamNhuan(y) && d<=29) {
        return 1;
      }else if(!kT_NamNhuan(y) && d<=28) {
        return 1;
      }
      return 0;
    }
  }
  return 0;
}
int main() {
  int day, month, year;
  do {
    cout << "Nhap ngay, thang, nam: ";
    cin >> day >> month >> year;
  } while(day<=0 || day>31 || month<=0 || month>12 || year<=0);
  if (kT_Date(day, month, year)) {
    cout << "Success";
  }else {
    cout << "Fail";
  }

  return 0;
}
