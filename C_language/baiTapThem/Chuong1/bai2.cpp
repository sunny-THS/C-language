#include<iostream>
using namespace std;

int main() {
  int n;
  cout << "Nhap so nguyen n: ";
  cin >> n;
  if (n%2 == 0)
    cout << "Chan";
  else
    cout << "Le";
  
  return 0;
}
