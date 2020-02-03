#include<stdio.h>

int fibonacci(int a){
  int x1 = 1, x2 = 1;
  long x3;
  if (a == 1 || a == 2) {
    return 1;
  }
  for (int i = 3; i <= a; i++) {
    x3 = x1 + x2;
    x1 = x2;
    x2 = x3;
  }
  return x3;
}

int main(){
  for (int i = 1; i < 100; i++) {
    printf("%d : %ld\n", i, fibonacci(i));
  }
  return 0;
}
