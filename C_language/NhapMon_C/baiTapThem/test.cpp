#include <stdio.h>

int main()
{
  int a, b, c, d, e, f;
  int sum;
  // tinh tong 6 so nguyen nhap tu ban phim
  //nhap gia tri
  printf("a: ");
  scanf("%d", &a);
  printf("b: ");
  scanf("%d", &b);
  printf("c: ");
  scanf("%d", &c);
  printf("d: ");
  scanf("%d", &d);
  printf("e: ");
  scanf("%d", &e);
  printf("f: ");
  scanf("%d", &f);
  sum = a+b+c+d+e+f;
  printf("Tong: %d\n", sum);
  return 0;
}
