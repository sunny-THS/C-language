#include <iostream>
#include <conio.h>

void InsertionSort(int arr[], int n)
{
   int j = 0;
   for (int i = 1; i < n; i++)
   {
       int key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void Show(int arr[], int n)
{
   for (int i=0; i < n; i++)
     std::cout << arr[i] <<" ";
}


int main()
{
    int arr[] = {123, 113, 133, 53, 63};
    int n = sizeof(arr)/sizeof(arr[0]);

    InsertionSort(arr, n);
    Show(arr, n);
    _getch();
    return 0;
}
