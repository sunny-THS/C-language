#include <iostream>
#include <string>
#define MAX 26
using namespace std;

string Solve(string s, int n)
{
  int lower[MAX] = {0};
  int upper[MAX] = {0};
  for (int i=0; i<n; i++)
  {
    if (islower(s[i]))
    {
      lower[s[i] - 'a']++;
    }
    else if (isupper(s[i]))
    {
      upper[s[i] - 'A']++;
    }
  }

  int i = 0;
  int j = 0;

  while (i < MAX && lower[i] == 0) i++;
  while (j < MAX && upper[i] == 0) j++;

  for (int k = 0; k < n; k++)
  {
    if (islower(s[k]))
    {
      while (lower[i]==0) i++;
      s[k] = (char)(i+'a');
      lower[i]--;
    }else if (isupper(s[k]))
    {
      while (upper[j]==0) j++;
      s[k] = (char)(j+'A');
      upper[j]--;
    }
  }
  return s;
}

int main()
{
  string str = "spATChaVD";
  cout << Solve(str, str.length());
  return 0;
}
