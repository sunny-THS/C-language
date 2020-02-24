#include "Sort.h"
using namespace std;

void main() {
  SortAlgorithm sort;
  int a[] = {5,4,6,2,4,15,2};
  int n = sizeof(a)/sizeof(a[0]);

  //sort.BubbleSort(a, n);
  //sort.SelectionSort(a, n);
  sort.InsertionSort(a, n);
  for ( const auto& item: a) {
    cout << item << " ";
  }

  system("pause>nul");
}
