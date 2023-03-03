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
  log_warn("Start");

  char* iso_date = "2016-10-27T17:13:40Z";

  log_info("iso_date=%s", iso_date);
  log_dump(iso_date, 24);

  log_info("iso_date sizeof: %lu", sizeof(iso_date));
  log_info("iso_date strlen: %lu", strlen(iso_date));

  log_debug("before copy");
  log_dump(str_date, 32);

  memset(str_date, 0, sizeof(str_date));
  log_dump(str_date, 32);

  strncpy(str_date, iso_date, strlen(iso_date));

  log_debug("after copy");
  log_dump(str_date, 32);

  log_info("str_date=%s", str_date);
  log_info("str_date sizeof: %lu", sizeof(str_date));
  log_info("str_date strlen: %lu", strlen(str_date));

  log_warn("End");
  return 0;
}
