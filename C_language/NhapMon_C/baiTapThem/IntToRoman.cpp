#include <iostream>
#include <string>
using namespace std;

int demso(int n)
{
  int d = 0;
  while (n!=0)
  {
    d++;
    n/=10;
  }
  return d;
}
string intToRoman(int n)
{
  string s;
  int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
  string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  int i = sizeof(num)/sizeof(*num);
  while(n>0)
  {
    int div = n/num[i];
    n %= num[i];
    while(div--) s += sym[i];
    i--;
  }
  return s;
}

int main()
{
  int n = 3549;
  cout << intToRoman(n);
  return 0;
}
