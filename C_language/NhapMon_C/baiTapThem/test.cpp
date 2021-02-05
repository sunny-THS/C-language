#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);
  for (size_t i = 0; i < str1.length(); i++) {
    for (size_t j = 0; j < str2.length(); j++) {
      if (str1[i] == str2[j])
      {
        str1[i] = '*';
        break;
      }
    }
  }
  cout << str1;
  return 1;
}
