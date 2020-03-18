#include<iostream>
#include<vector>
using namespace std;

class kTSoDoiXung {
  private:
    int num, lenNum;
    vector<int> a;
  public:
    kTSoDoiXung(int a) : num(a), lenNum(len()) {}
    ~kTSoDoiXung() {
      a.clear();
    }
    int len();
    int test();
    int tachSo(int num);
    void result();
};
void kTSoDoiXung::result() {
  if (test()) {
    cout << this->num << " la so doi xung";
  }else {
    cout << this->num << " khong phai la so doi xung";
  }
}
int kTSoDoiXung::tachSo(int number) {
  static int t = 1;
  static int n = 0;
  int a;
  if (n != number) {
    t = 1;
    n = number;
  }
  number/=t;
  a = number%10;
  t*=10;
  return a;
}
int kTSoDoiXung::test() {
  for (int i = 0; i < this->lenNum; i++) {
    this->a.push_back(tachSo(this->num));
  }
  for (int i = 0; i < this->lenNum/2; i++) {
    if (this->a.at(i) != this->a.at(this->lenNum-i-1)) {
      return 0;
    }
  }
  return 1;
}
int kTSoDoiXung::len() {
  static int d=0, tmp=0;
  if (tmp != this->num) {
    d=0;
    tmp = this->num;
    while(tmp!=0) {
      tmp/=10;
      d++;
    }
  }
  return d;
}
int main() {
  unsigned int a;
  cout << "Nhap n: ";
  cin >> a;
  kTSoDoiXung b(a);
  b.result();

  system("pause>nul");
  return 0;
}
