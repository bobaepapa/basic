#include "log_debug.h"

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
extern int (*func_ptrs[])(int, int);

// int add(int a, int b) { return a+b; }
// int sub(int a, int b) { return a-b; }
// int mul(int a, int b) { return a*b; }
// int div(int a, int b) { return a/b; }

int main()
{
  int result;
  int (*func_ptrs[])(int, int) = {add, sub, mul, div};

  for (int i = 0; i < sizeof(func_ptrs) / sizeof(func_ptrs[0]); i++) {
    result = func_ptrs[i](5, 3);
    printf("[%d] result: %d\n", i, result);
  }
}
