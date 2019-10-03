#include<stdio.h>
#include<conio.h>

void main() {
  int cd, cr;
  printf("Nhap chieu dai va chieu rong: ");
  scanf("%d%d", &cd, &cr);
  for(int i=0;i<cr;i++){
    for(int j=0;j<cd;j++){
      printf("* ");
    }
    printf("\n");
  }
  getch();
}
