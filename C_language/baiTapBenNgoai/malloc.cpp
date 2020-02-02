#include<stdio.h>
#include<stdlib.h>
struct TD {
  int x, y;
};
struct TEST {
  TD a[10];
};
int main(){
  TEST *s;
  s.a = (TEST *) malloc(15);
  printf("%d\n", s->a);
  s = (TEST *) realloc(s, 25);
  printf("%d\n", s);
  return 0;
}
