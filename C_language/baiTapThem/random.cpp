#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
int random(int min, int max);

int main() {
  srand(time(0));
  int a = 0;
  while (a<10) {
    cout << random(-100, 100) << endl;
    a++;
  }
  return 0;
}
int random(int min, int max) {
  return min + rand()%(max-min+1);
}
