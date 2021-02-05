#include <iostream>
using namespace std;

int main()
{
  int a[] = {1,5,3,4,5,6};
  int i = 1;
  a[i]++;
  cout << i << ' ' << a[i] << endl;
  a[i++];
  cout << i << ' ' << a[i];
  return 0;
}
