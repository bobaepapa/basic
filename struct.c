#include <stdio.h>

struct my_st {
  int a;
} my_st_t;
int main()
{
  my_st_t.a = 1;

  printf("my_st_t.a=%d\n", my_st_t.a);
  return 0;
}
