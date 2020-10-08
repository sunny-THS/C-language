#include<iostream>
#include<time.h>
using namespace std;

int main() {
  time_t rawTime;
  while (1) {
    system("cls");
    time(&rawTime);
    cout << ctime(&rawTime);
  }
  return 0;
}
