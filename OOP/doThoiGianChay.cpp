#include <iostream>
#include <windows.h>
#include <limits.h>
#include <iomanip>
#include <ctime>
using namespace std;
int n=327680;
long *A=NULL;

//Đo thử thời gian của 2 Neg(x) với ~x+1 xem cái nào nhanh hơn nè
int Neg(const int & x)
{
    return -x;
}

int Neg2(int x)
{
    return -x;
}

int main()
{
    //Tạo ra mảng có 1 tỷ phần tử nhẫu nhiên
    srand(time(NULL));
    A=(long*)malloc(sizeof(long)*n);
    for (int i=0;i<n;i++)
        A[i]=rand();

    LARGE_INTEGER lFreq,lStart,lEnd;
    QueryPerformanceFrequency(&lFreq);

    //Đo điểm cho Neg
    QueryPerformanceCounter(&lStart);
    for (int i=0;i<n;i++)
        Neg(A[i]);
    QueryPerformanceCounter(&lEnd);
    cout<<"Time Neg () take : "<<setprecision(20)<<(long double)(lEnd.QuadPart-lStart.QuadPart)/lFreq.QuadPart<<endl;

    //Đo điểm cho hàm còn lại Neg2
    QueryPerformanceCounter(&lStart);
        for (int i=0;i<n;i++)
            Neg2(A[i]);
    QueryPerformanceCounter(&lEnd);
    cout<<"Time Neg2() take : "<<setprecision(20)<<(long double)(lEnd.QuadPart-lStart.QuadPart)/lFreq.QuadPart<<endl;
    system("pause");
    return 1;
}
