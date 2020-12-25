#include <stdio.h>
#include <cmath>
int checkSNT(int n)
{
  if (n<2) return 0;
  for (size_t i = 2; i <= sqrt(n); i++)
    if (n%i==0) return 0;
  return 1;
}
int main()
{
  int n=0;
  for (size_t i = 0; i < 1000; i++) {
    if (checkSNT(i))
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
