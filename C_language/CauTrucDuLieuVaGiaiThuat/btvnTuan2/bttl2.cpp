#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
void NhapNgauNhien(int a[][MAX], int &n);
void Xuat(int a[][MAX], int n);
int random(int min = -100, int max = 100);
int *LinearSearch(int a[][MAX], int n, int x);
void SortAscending_R(int a[][MAX], int n);
void SortDescending_C(int a[][MAX], int n);
void Sort_DCC(int a[][MAX], int n, bool ascending = true);
template <typename T>
void Swap(T &a, T &b);
void SelectionSort(int *a, int n, bool ascending = true);
// void ziczacSort(int a[][MAX], int n);
// void ChuyenMang(int A[][100], int m, int n, int B[], int &p);
// void SapXep1Chieu(int *a, int n);

int main()
{
	srand(time(0));

	int a[MAX][MAX];
	int c_l; // dong va cot
	int x;
	NhapNgauNhien(a, c_l);
	Xuat(a, c_l);
	printf("\nTim x\n");
	printf("Nhap x: ");
	scanf("%d", &x);
	int *tmp = LinearSearch(a, c_l, x);
	if (tmp[0]==-1) printf("Khong Tim thay\n");
	else printf("hang: %d -- cot: %d", tmp[0]+1, tmp[1]+1);
	printf("\nSap xep tang dan theo dong\n");
	SortAscending_R(a, c_l);
	Xuat(a, c_l);
	printf("\nSap xep giam dan theo cot\n");
	SortDescending_C(a, c_l);
	Xuat(a, c_l);
	printf("\nSap xep tang dan duong cheo chinh\n");
	Sort_DCC(a, c_l); // ascending
	Xuat(a, c_l);
	printf("\nSap xep giam dan duong cheo chinh\n");
	Sort_DCC(a, c_l, false);  // descending
	Xuat(a, c_l);
	// ziczacSort(a, c_l);
	// Xuat(a, c_l);
	getch();
	return 0;
}
void NhapNgauNhien(int a[MAX][MAX], int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			a[i][j] = random(); // min = -100 -- max = 100
		}
	}
}
void Xuat(int a[MAX][MAX], int n)
{
	printf("Mang cua ban la\n");
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf("%4d\t", a[i][j]);
		}
		printf("\n");
	}
}
int random(int min, int max)
{
	return min + rand() % (max - min + 1);
}
int *LinearSearch(int a[MAX][MAX], int n, int x)
{
	static int index[2] = { -1, -1 };
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (a[i][j] == x)
			{
				index[0] = i; // is hang
				index[1] = j; // is cot
				return index;
			}
		}
	}
	return index;
}
// ________  _________  ___      ___ ________
//|\   __  \|\___   ___\\  \    /  /|\   ___  \
//\ \  \|\ /\|___ \  \_\ \  \  /  / | \  \\ \  \
// \ \   __  \   \ \  \ \ \  \/  / / \ \  \\ \  \
//  \ \  \|\  \   \ \  \ \ \    / /   \ \  \\ \  \
//   \ \_______\   \ \__\ \ \__/ /     \ \__\\ \__\
//    \|_______|    \|__|  \|__|/       \|__| \|__|
// btvn 3456,  bai 3 4
template <typename T>
void Swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
void SelectionSort(int *a, int n, bool ascending)
{
	for (size_t i = 0; i < n-1; i++) {
		size_t index = i;
		for (size_t j = i+1; j < n; j++) {
			if (ascending) {
				if (a[index]>a[j]) index = j;
			}else if (a[index]<a[j]) index = j;
		}
		if (index != i)
			Swap(a[index], a[i]);
	}
}
void SortAscending_R(int a[][MAX], int n) // selectionSort
{
	for (size_t i = 0; i < n; i++) {
		SelectionSort(a[i], n);
	}
}

void SortDescending_C(int a[][MAX], int n)
{
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n-1; j++) {
			size_t max = j;
			for (size_t k = j+1; k < n; k++) {
				if(a[max][i] < a[k][i]) max = k;
			}
			if (max!=j)
				Swap(a[max][i], a[j][i]);
		}
	}
}
void Sort_DCC(int a[][MAX], int n, bool ascending)
{
	for (size_t i = 0; i < n-1; i++) { // interchangeSort
		for (size_t j = i+1; j < n; j++) {
			if (ascending) {
				if (a[i][i] > a[j][j]) Swap(a[i][i], a[j][j]);
			}else if (a[i][i] < a[j][j]) Swap(a[i][i], a[j][j]);
		}
	}
}
// void ChuyenMang(int A[][MAX], int m, int n, int B[], int &p)
// {
//     p = m*n;    //p là số phần tử của mảng B
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             B[i*n + j] = A[i][j];
// }
// void SapXep1Chieu(int *a, int n)
// {
//     for (int i = 0; i < n - 1; i++)
//         for (int j = i + 1; j < n; j++)
//             if (a[i] > a[j])
//             {
//                 Swap(a[i], a[j]);
//             }
// }
// void ziczacSort(int a[][MAX], int n)
// {
// 	int B[100];
//     int p;
//     ChuyenMang(a,n,n,B,p);
//     SapXep1Chieu(B,p);
//     int vt = 0;
//     int trai, phai;
//     trai = 1;
//     phai = 1;
//     int i = 0, j = 0;
//     a[i][j] = B[vt++];
//     do
//     {
//         if (j == n - 1)
//             i++;
//         else
//             j++;
//         a[i][j] = B[vt++];
//         printf("A[%d][%d] = %d\n",i,j,a[i][j]);
//         while (i < n - 1 && j > 0)
//         {
//             i++;
//             j--;
//             a[i][j] = B[vt++];
//             printf("A[%d][%d] = %d\n",i,j,a[i][j]);
//         }
//         if (i == n - 1)
//             j++;
//         else
//             i++;
//         a[i][j] = B[vt++];
//         printf("A[%d][%d] = %d\n",i,j,a[i][j]);
//         while (i > 0 && j < n - 1)
//         {
//             i--;
//             j++;
//             a[i][j] = B[vt++];
//             printf("A[%d][%d] = %d\n",i,j,a[i][j]);
//         }
//
//     } while (i < n - 1 || j < n - 1);
// }
