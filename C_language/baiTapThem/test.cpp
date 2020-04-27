#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
  fstream filein;
  string a;
  filein.open("log.txt", ios::in);

  if (!filein.eof()) {
    getline(filein, a);
  }
  cout << a;
  return 0;
}
