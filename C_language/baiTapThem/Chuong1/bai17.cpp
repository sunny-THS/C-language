#include<iostream>
using namespace std;
int getMax_N(int n) {
  int tmp;
  int max = n%10;
  while (n<0) {
    n/=10;
    tmp = n%10;
    if (tmp == 9) {
      return tmp;
    }
    if (max < tmp) {
      max = tmp;
    }
  }
  return max;
}
int main() {
  long n;
  cout << "Nhap n: ";
  cin >> n;
  cout << "Max: " << getMax_N(n);

  return 0;
}
