#include<stdio.h>
#include<conio.h>

void main(){
  int a;
  printf("Nhap a: ");
  scanf("%d", &a);
  for (int i=1; i<=a; i++) {
      for(int j=1; j<= 4*a+9; j++){
          if(j<=a&&j<=i){
            printf("*");
          }else if((j>=2*a+5-(i-1)) && (j<=2*a+5+(i-1))){
              printf("*");
          }else if(j>3*a+9&&j<=4*a+9-i+1){
            printf("*");
          }else{
            printf(" ");
          }   
      }
      printf("\n");
  }
  getch();
}
