#include <stdio.h>

int main()
{
  int n;
  int sum=0;
  printf("Nhap n: ");
  scanf("%d", &n);
  sum += n%10;
  n/=10;
  sum += n%10;
  n/=10;
  sum += n%10;
  n/=10;
  sum += n%10;
  n/=10;
  sum += n%10;
  n/=10;
  printf("Tong: %d\n", sum);
  return 0;
}
