#ifndef SORT_H_
#define SORT_H_

#include<iostream>

class SortAlgorithm {
  private:
    bool swapped_;
  public:
	   void BubbleSort(int* arr, int n);
     void SelectionSort(int* arr, int n);
     void InsertionSort(int* arr, int n);
};
void swap(int& a, int& b);
#endif // SORT_H_
