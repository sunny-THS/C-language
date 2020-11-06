#include <stdio.h>

int main()
{
  char s[100];
  char sa[100];
  scanf("%[^\n]%*c", s);
  printf("%s\t", s);
  return 0;
}
