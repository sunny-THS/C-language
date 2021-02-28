#include <iostream>
#include <string>
using namespace std;

int main()
{
  int *a = new int[5];
  for (size_t i = 0; i < 5; i++) {
    a[i] = i;
  }
  cout << *(a+2);
  return 1;
}
