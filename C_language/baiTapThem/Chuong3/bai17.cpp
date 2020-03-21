#include<iostream>
using namespace std;
class demCL {
  private:
    int chan, le;
  public:
    demCL(unsigned int a) {
      chan = 0;
      le = 0;
      while(a!=0) {
        if (a%10%2==0) {
          chan++;
        }else {
          le++;
        }
        a/=10;
      }
    }
    getC() {return chan;}
    getL() {return le;}
};
int lenNum_K(unsigned int a) {
  int d=0;
  while (a!=0) {
    a/=10;
    d++;
  }
  if (d<=5 && d>0) {
    return 0;
  }
  return 1;
}
int main() {
  unsigned int a;
  do {
    cout << "nhap a: ";
    cin >> a;
  } while(lenNum_K(a));
  demCL dem(a);
  cout << "chan: " << dem.getC() << endl;
  cout << "le: " << dem.getL();
  return 0;
}
