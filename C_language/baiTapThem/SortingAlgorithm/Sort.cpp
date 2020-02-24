#include "Sort.h"

void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}

void SortAlgorithm::BubbleSort(int *arr, int n) {
  for (int i = 0; i < n-1; i++) {
    swapped_ = false;
    for (int j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        swapped_ = true;
      }
    }
  }
}

void SortAlgorithm::SelectionSort(int* arr, int n) {
  for (int i = 0; i < n-1; i++) {
    int min_index = i; // select index
    for (int j = i+1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    swap(arr[i], arr[min_index]);
  }
}

void SortAlgorithm::InsertionSort(int* arr, int n) {
  int temp;
  int j;
  for (int i = 1; i < n; i++) {
    temp = arr[i];
    j = i-1;
    // Insert
    while (j >= 0 && temp < arr[j]) {
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = temp;
  }
}
