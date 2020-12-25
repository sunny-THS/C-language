#include <iostream>
using namespace std;

void veHCN(char c, int n=4, int m=6)
{
  static int i=1, j=1;
  (i>n) ? {goto exit;}: {goto print;};
  print:
    (j>m) ? {goto xuonghang;}: {goto ve;}; 
  xuonghang:
    j=1; i++;
    cout << endl;
    veHCN(c);
    goto exit;
  ve:
    (j==1 || j==m || i==1 || i==n)? cout << c : cout << ' ';
    j++;
    veHCN(c);
    goto exit;
  exit: return;
}

int main()
{
  veHCN('*');
  return 0;
}
