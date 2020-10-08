#include<iostream>
using namespace std;
int printFirstNum(int n) {
  int first;
  while (n!=0) {
    first = n%10;
    n/=10;
  }
  return first;
}
int main() {
  int n;
  do {
    cout << "Nhap n: ";
    cin >> n;
  } while(n<=0);
  cout << printFirstNum(n);
  return 0;
}
