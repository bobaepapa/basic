#include "log_debug.h"

#define CONDITION 2

bool is_expired(int goal)
{
  return (goal < CONDITION) || (goal >= CONDITION && goal % 2);
}

int main(void)
{
  warn("START");

  for (int i = 0; i < 10; i++) {
    info("%d result: %d", i, is_expired(i));
  }

  warn("END");
}
