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

  char* iso_date = "2016-10-27T17:13:40Z";

  info("iso_date=%s", iso_date);
  dump(iso_date, 24);

  info("iso_date sizeof: %lu", sizeof(iso_date));
  info("iso_date strlen: %lu", strlen(iso_date));

  debug("before copy");
  dump(str_date, 32);

  memset(str_date, 0, sizeof(str_date));
  dump(str_date, 32);

  strncpy(str_date, iso_date, strlen(iso_date));

  debug("after copy");
  dump(str_date, 32);

  info("str_date=%s", str_date);
  info("str_date sizeof: %lu", sizeof(str_date));
  info("str_date strlen: %lu", strlen(str_date));

  warn("End");
  return 0;
}
