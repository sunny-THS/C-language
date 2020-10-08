#include<iostream>
#include<vector>
using namespace std;
template<class Type>
void tachSo(Type &arr, unsigned int a){
  while (a!=0){
    arr.push_back(a%10);
    a/=10;
  }
}
void swap(int &a, int &b){
  int t = a;
  a=b;
  b=t;
}
template<class Type>
void bubbleSort(Type a) {
  bool b;
  for (int i = 0; i < a.size()-1; i++) {
    b = false;
    for (int j = 0; j < a.size()-i-1; j++) {
      if (a.at(j)>a.at(j+1)) {
        b = true;
          swap(a[j], a[j+1]);
      }
    }
    if (!b) {
      break;
    }
  }
}
void sort(unsigned int a) {
  vector<int> arr;
  tachSo(arr, a);
  bubbleSort(arr);
  for (const auto &item:arr) {
    cout << item;
  }
  arr.clean();
}
int lenNum_K(unsigned int a) {
  int d=0;
  while (a!=0) {
    a/=10;
    d++;
  }
  if (d>0&&d<=5) {
    return 0;
  }
  return 1;
}
int main() {
  unsigned int a;
  do {
    cout << "Nhap n: ";
    cin >> a;
  } while(lenNum_K(a));
  cout << "Result: ";
  sort(a);
  return 0;
}
