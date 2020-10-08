#include<iostream>
using namespace std;

int main() {
  int n, tmp;
  cout << "Nhap n: ";
  cin >> n;
  tmp = n;
  if (tmp<0) {
    tmp*=-1;
  }
  cout << '|' << n << "| = " << tmp; 
  return 0;
}
