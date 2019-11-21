#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 100
#define COLS 100

void nhap_R_C(int &a, int &b){
  do{
    printf("Nhap so dong: ");
    scanf("%d", &a);
    printf("Nhap so cot: ");
    scanf("%d", &b);
  }while(a<=0||b<=0||a>ROWS||b>COLS);
}
//bt tring sach
//bai 38
void nhapMaTran(int a[][COLS], int &n, int &m){
  nhap_R_C(n,m);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
      printf("a[%d][%d]= ", i, j);
      scanf("%d", &a[i][j]);
    }
}
void xuatMaTran(int a[][COLS], int n, int m){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

//bai 39
int max_of_Mattrix(int a[][COLS], int n, int m){
  int max = a[0][0];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(max<a[i][j])
        max=a[i][j];
  return max;
}

//bai 40
int tinhTongDong_i(int a[][COLS], int n, int m){
  int s=0;
  for(int i=0; i<n; i++)
    s+=a[m][i];
  return s;
}
int tinhTongCot_j(int a[][COLS], int n, int m){
  int s=0;
  for(int i=0; i<n; i++)
    s+=a[i][m];
  return s;
}

//bt tren slide
//bai 1
void xuatMang_C(int a[][COLS], int n, int m){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      printf("%d ", a[j][i]);
    printf("\n");
  }
}

//bai 2
int random(int min, int max){
  return min+ rand()%(max-min+1);
}
void nhap_GT_random(int a[][COLS], int &n, int &m){
  nhap_R_C(n,m);
  srand(time(NULL));
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      a[i][j] = random(-100,100);
}

//bai 3
void nhap_Chan(int a[][COLS], int &n, int &m){
  nhap_R_C(n,m);
  for(int i=0; i<n, i++)
    for(int j=0; j<m; j++)
      do{
        printf("a[%d][%d]= ", i, j);
        scanf("%d", &a[i][j]);
      }while(a[i][j]%2!=0);
}

//bai 4
void xuatSoLe(int a[][COLS], int n, int m){
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(a[i][j]%2!=0)
        printf("%d ", a[i][j]);
}
void xuatSoChan(int a[][COLS], int n, int m){
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(a[i][j]%2==0)
        printf("%d ", a[i][j]);
}

//bai 5
void xuatLe_ROW_k(int a[][COLS], int n, int k){
  for(int i=0; i<n; i++)
    if(a[k][i]%2==0)
      printf("%d ", a[k][i]);
}
void xuatChan_COL_k(int a[][COLS], int n, int k){
  for(int i=0; i<n; i++)
    if(a[i][k]%2!=0)
      printf("%d ", a[i][k]);
}

//bai 6
void tinhTong(int a[][COLS], int n, int m){
  int s=0;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      s+=a[i][j];
  return s;
}

//bai 7
void tinhTongCoDK(int a[][COLS], int n, int m){
  int s=0;
  for(int i=1; i<n; i+=2)
    for(int j=0; j<m; j+=2)
      if(a[i][j]%2==0)
        s+=a[i][j];
  return s;
}

//bai 8
void xuatTichTungDong(int a[][COLS], int n, int m){
  for(int i=0; i<n; i++){
    int tich=1;
    for(int j=0; j<m; j++)
      tich*=a[i][j];
    printf("Tich dong %d = %d", i+1, tich);
  }
}

//bai 9
int timMax(int a[][COLS], int n, int m){
  int max = a[0][0];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(max<a[i][j])
        max=a[i][j];
  return max;
}
int timMin(int a[][COLS], int n, int m){
  int min = a[0][0];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(min>a[i][j])
        min=a[i][j];
  return min;
}

//bai 10
int timMax_ROW_k(int a[][COLS], int n, int m){
  int max a[k][0];
  for(int i=0; i<n; i++)
    if(max<a[k][i])
      max= a[k][i];
return max;
}
