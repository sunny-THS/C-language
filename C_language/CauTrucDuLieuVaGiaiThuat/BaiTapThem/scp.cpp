#include <stdio.h>
#include <cmath>
int checkSCP(int n)
{
  int sqrt_ = sqrt(n);
  return (sqrt_*sqrt_) == n ? 1 : 0;
}
int main()
{
  int n=0;
  for (size_t i = 1; i < 1000; i++) {
    if (checkSCP(i))
    {
      printf("%d\t", i);
      if (n++ == 10)
      {
        printf("\n");
        n=0;
      }
    }
  }
  return 0;
}
