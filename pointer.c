#include "log_debug.h"

char str_date[24] = {
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
};

int main()
{
  warn("Start");
  char* p = str_date;

  info("str_date size: %lu", sizeof(str_date));
  info("p size: %lu", sizeof(p));

  warn("End");
  return 0;
}