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
float tinhDTB(SV a);
void xepLoai(SV a);

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
float tinhDTB(SV a){
  return (float)(a.diemT+a.diemH+a.diemL)/3;
}
void xepLoai(SV a){
  float dtb = tinhDTB(a);
  printf("Xep loai: ");
  if(dtb>=8){
    orintf("Gioi");
  }else if(dtb>=6.5){
    printf("Kha");
  }else if(dtb>=5){
    printf("Trung Binh");
  }else{
    printf("Yeu");
  }
}
