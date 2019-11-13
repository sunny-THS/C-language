#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 1000
void nhapMang(int a[], int &n){
  int chon;
  printf("Nhap gia tri cua mang: ");
  scanf("%d", &n);
  printf("Chon phuong thuc:\n");
  printf("1. Nhap tu ban phim\n");
  printf("2. Phat sinh ngau nhien\n");
  do {
    printf("Chon: ");
    scanf("%d", &chon);
  } while(chon!=2&&chon!=1);
  if (chon==1) {
    for (int i = 0; i < n; i++) {
      printf("a[%d]= ", i);
      scanf("%d", &a[i]);
    }
  }else {
    for (int i = 0; i < n; i++) {
      a[i] = -100 + rand()%(100-(-100)+1);
    }
  }
}
void main(){
  int chon, soBai=37, stt=0, arr[MAX_SIZE], n;
  nhapMang(arr, n);
  do {
    for (int i = 1; i <= soBai; i++) {
      if (i>=23&&i<=37) {
        printf("%d. Bai %d\t", ++stt, i);
        if (i%5==0) {
          printf("\n");
        }
      }
    }
    printf("\nChon: ");
    scanf("%d", &chon);
    switch (chon) {
      case 1: {
        printf("Chon vi tri muon xoa: ");
        scanf("%d", &c);
	      break;
      }
      case 2: {}
      case 3: {}
      case 4: {}
      case 5: {}
      case 6: {}
      case 7: {}
      case 8: {}
      case 9: {}
      case 10: {}
      case 11: {}
      case 12: {}
      case 13: {}
      case 14: {}
      case 15: {}
    }
    printf("\n+=====+=======================+\n");
    stt=0;
  } while(chon!=0);
}
