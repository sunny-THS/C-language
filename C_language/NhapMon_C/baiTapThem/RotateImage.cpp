#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;

#define MAXSIZE 100

void rotateImage(int arr[][MAXSIZE], int n);
void swap(int& a, int& b);
int random(int min, int max);
void printArr(int a[][MAXSIZE], int n);

int main() {
  srand(time(NULL));
  int n, a[MAXSIZE][MAXSIZE];
  cout << "Nhap n: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = random(-100, 100);
    }
  }
  printArr(a, n);
  rotateImage(a, n);
  cout << endl;
  printArr(a, n);
  return 0;
}

void printArr(int a[][MAXSIZE], int n) {
  // xuat mang
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(5) << a[i][j];
    }
    cout << endl;
  }
}

int random(int min, int max) {
  return min + rand()%(max-min+1);
}

void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}

void rotateImage(int arr[][MAXSIZE], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n/2; j++) {
      swap(arr[i][j], arr[i][n-j-1]);
    }
  }
}
