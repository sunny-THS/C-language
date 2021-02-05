#include <iostream>
#include <string>
// từ a-z có 26 kí tự
#define MAX 26
using namespace std;

string Solve(string s, int n)
{
  int lower[MAX] = {0};
  int upper[MAX] = {0};
  /* 2 cái khai báo ở trên sẽ giống ở dưới
  lower [
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
  ];
  upper [
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
  ];
  */
  // kí tự dc sắp xếp khi thêm vào lower hay upper 
  for (int i=0; i<n; i++)
  {
    if (islower(s[i]))
    {
      lower[s[i] - 'a']++; // tăng giá trị có vị trí tương ứng trong mảng
    }
    else if (isupper(s[i]))
    {
      upper[s[i] - 'A']++; // tăng giá trị có vị trí tương ứng trong mảng
    }
    // s[i] - 'a' hay s[i] - 'A' đề sẽ có giá trị số nguyên trong khoảng [0-25]
  }

  int i = 0;
  int j = 0;

  // tìm đến vị trí dc lưu
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
    // (char)(i+'a') chuyển số nguyên hay kí tự
  }
  return s;
}

int main()
{
  string str = "spATChaVD";
  cout << Solve(str, str.length());
  return 0;
}
