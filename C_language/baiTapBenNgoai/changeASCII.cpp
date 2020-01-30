#include<stdio.h>

int main(){
  char c;
  for (int i = 1; i <= 255; i++) {
    c=i;
    if (i==32) {
      printf("%d space\t", i);
      continue;
    }
    printf("%d %c\t\t", i, c);
    if (i%5==0) {
      printf("\n");
    }
  }
  return 0;
}
