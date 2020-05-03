#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Nhap so N: ";
  cin >> n;
  if (n&0) {
    cout << "\nDay la so chan";
  }else {
    cout << "\nDay la so le";
  }
  return 0;
}
