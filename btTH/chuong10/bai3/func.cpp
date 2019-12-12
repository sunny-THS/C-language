#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct SinhVien{
  char mssv[11];
  char tenSv[50];
  float diemT;
  float diemL;
  float diemH;
}SV;

void nhapTT_SV(SV &a);
void xuatTT_SV(SV a);

void xuatTT_SV(SV a){
  printf("%s\t%s\t%.2f\t%.2f\t%.2f\n", a.mssv, a.tenSv, a.diemT, a.diemL, a.diemH);
}
void nhapTT_SV(SV &a){
  FILE *f;
  f= fopen("text.txt","rt");
  fgets(a.mssv,12,f);
  fgets(a.tenSv, 51, f);
  fscanf(f, "%f", &a.diemT);
  fscanf(f, "%f", &a.diemL);
  fscanf(f, "%f", &a.diemH);
  fclose(f);
}
