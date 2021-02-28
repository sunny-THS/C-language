#include <iostream>
#include <string>
// từ a-z có 26 kí tự
#define MAX 10
using namespace std;

int *Solve(int *arr, int n)
{
  int odd[MAX] = {0};
  int even[MAX] = {0};
  /* 2 cái khai báo ở trên sẽ giống ở dưới
  odd [
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
  even [
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
    if (arr[i]%2!=0)
    {
      odd[arr[i]]++; // tăng giá trị có vị trí tương ứng trong mảng
    }
    else
    {
      even[arr[i]]++; // tăng giá trị có vị trí tương ứng trong mảng
    }
  }

  int i = 0;
  int j = 0;

  // tìm đến vị trí dc lưu
  while (i < MAX && odd[i] == 0) i++;
  while (j < MAX && even[i] == 0) j++;

  for (int k = 0; k < n; k++)
  {
    if (arr[k]%2!=0)
    {
      while (odd[i]==0) i++;
      arr[k] = i;
      odd[i]--;
    }else
    {
      while (even[j]==0) j++;
      arr[k] = j;
      even[j]--;
    }
  }
  return arr;
}

int main()
{
  int arr[] = {5,8,2,3,1,7,4};
  int *a = new int[sizeof(arr)/sizeof(int)];
  a = Solve(arr, sizeof(arr)/sizeof(int));
  for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++) {
    cout << a[i];
  }
  return 0;
}
