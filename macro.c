#include "common.h"


int count = 0;

#define TO_NEXT(x) (count=x == x)

bool test(void)
{
  info("count=%d", count);

  return TO_NEXT(1);
}

int main()
{
  warn("Start");
  
  bool result = test();
  
  info("result=%d", result);
  info("count=%d", count);

  warn("End");

  return 0;
}
