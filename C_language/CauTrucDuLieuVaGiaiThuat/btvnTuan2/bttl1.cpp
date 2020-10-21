#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define MAXSIZE 15
void NhapNgauNhien(int *a, int &n);
void Xuat(int *a, int n);
int random(int min = -100, int max = 100);
int LinearSearch(int *a, int n, int x);
void InterchangeSort(int *a, int n, bool ascending = true);
void SelectionSort(int *a, int n, bool ascending = true);
void QuickSort(int *a, int l, int r, bool ascending = true);
template <class T>
void Swap(T &a, T &b);
int BinarySearch(int *a, int n, int x);

void main()
{
	srand(time(0));
	int arr[MAXSIZE], n, x;
	NhapNgauNhien(arr, n);
	Xuat(arr, n);
	printf("\nTim x(vi tri tim thay dau tien)\n");
	printf("Nhap x: ");
	scanf("%d", &x);
	size_t tmp = LinearSearch(arr, n, x);
	if (tmp != -1) printf("Gia tri can tim: %d\nTai vi tri: %d\n", arr[tmp], tmp+1);
	else printf("Khong Co gia tri trong mang\n");
	printf("\nSap xep tang dan(InterchangeSort)\n");
	InterchangeSort(arr, n); // asending
	Xuat(arr, n);
	printf("\nSap xep giam dan(InterchangeSort)\n");
	InterchangeSort(arr, n, false); // desending
	Xuat(arr, n);
	printf("\nTim x(vi tri tim thay dau tien)\n");
	printf("Nhap x: ");
	scanf("%d", &x);
	tmp = BinarySearch(arr, n, x);
	if (tmp != -1) printf("Gia tri can tim: %d\nTai vi tri: %d\n", arr[tmp], tmp + 1);
	else printf("Khong Co gia tri trong mang\n");
	printf("\nSap xep tang dan(SelectionSort)\n");
	SelectionSort(arr, n); // asending
	Xuat(arr, n);
	printf("\nSap xep giam dan(SelectionSort)\n");
	SelectionSort(arr, n, false); // desending
	Xuat(arr, n);
	printf("\nSap xep tang dan(QuickSort)\n");
	QuickSort(arr, 0, n-1); // asending
	Xuat(arr, n);
	printf("\nSap xep giam dan(QuickSort)\n");
	QuickSort(arr, 0, n - 1, false); // desending
	Xuat(arr, n);
	getch();
}
void NhapNgauNhien(int *a, int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		a[i] = random(); // min = -100 -- max = 100
	}
}
void Xuat(int *a, int n)
{
	printf("\nMang cua ban la\n");
	for (size_t i = 0; i < n; i++)
	{
		printf("%2d\t", a[i]);
	}
}
int random(int min, int max)
{
	return min + rand() % (max-min+1);
}
int LinearSearch(int *a, int n, int x)
{
	if (n < 2) return -1;
	for (size_t i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}
template <class T>
void Swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
void InterchangeSort(int *a, int n, bool ascending)
{
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			if (ascending)
			{
				if (a[i] > a[j])
					Swap(a[i], a[j]);
			}
			else {
				if (a[i] < a[j])
					Swap(a[i], a[j]);
			}
		}
	}
}
int BinarySearch(int *a, int n, int x)
{
	int l = 0, r = n-1;
	while (l<=r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x)
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
void SelectionSort(int *a, int n, bool ascending)
{
	for (size_t i = 0; i < n-1; i++)
	{
		int t = i;

		for (size_t j = i+1; j < n; j++)
		{
			if (ascending)
			{
				if (a[t] > a[j]) t = j;
			}
			else if (a[t] < a[j]) t = j;
		}
		if (t!=i) Swap(a[t], a[i]);
	}
}
void QuickSort(int *a, int l, int r, bool ascending)
{
	if (l >= r) return;
	bool check = ascending;
	size_t mid = (l + r) / 2;
	int i = l;
	int j = r;
	int x = a[mid];
	do
	{
		if (check)
		{
			while (a[i] < x)
				i++;
			while (a[j] > x)
				j--;
		}
		else {
			while (a[i] > x)
				i++;
			while (a[j] < x)
				j--;
		}
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	QuickSort(a, l, j, check);
	QuickSort(a, i, r, check);
}
