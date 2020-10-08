#include<iostream>
using namespace std;
int sum(int a=1, int b=0, int c=1) {
  return a+b+c;
}

int main() {
  cout << sum() << endl;
  cout << sum(2,3) << endl;
  cout << sum(2) << endl;
  return 0;
}
