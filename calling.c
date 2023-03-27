#include "log_debug.h"


int main()
{
  int i = 0;
  warn("Start\n");

  info("%d, %d, %d", i++, i++, i++);

  warn("End\n");
  return 0;
}
