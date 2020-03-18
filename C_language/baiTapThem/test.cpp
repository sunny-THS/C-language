#include<iostream>
#include<cmath>
using namespace std;
int main() {
  int x;
  float f;
  cout << "Nhap x: ";
  cin >> x;

  if (x<0)
    f = sin(x)*cos(5*x);
  else if (x==0)
    f = 0;
  else
    f = exp(x)*(pow(5, x)/(x+5));

  cout << f;
  system("pause>nul");
  return 0;
}
