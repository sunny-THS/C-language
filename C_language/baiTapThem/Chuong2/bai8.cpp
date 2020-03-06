#include<iostream>
#include<vector>
using namespace std;
int tachSo(int a) {
  static int i = 1;
  int b;
  a/=i;
  b = a%10;
  i*=10;
  if (!a) {
    i=1;
  }
  return b;
}
int num_len(int a) {
  int d=0;
  while (a!=0) {
    d++;
    a/=10;
  }
  return d;
}
void InsertionSort(vector<int>& a) {
  int j;
  for (int i = 1; i < a.size(); i++) {
    int key = a[i];
    j = i-1;
    while (j>=0 && a[j]>key) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
}
void sort(int a) {
  vector<int> num;
  int len = num_len(a);
  for (int i = 0; i < len; i++) {
    num.push_back(tachSo(a));
  }
  InsertionSort(num);
  for (const auto& item:num) {
    cout << item;
  }
}
int main() {
  int a;
  cout << "Nhap n: ";
  cin >> a;
  sort(a);
  return 0;
}
