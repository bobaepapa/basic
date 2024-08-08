#include "common.h"

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

bool strcmp_safe(char* src, const char* dst, size_t max)
{
  if (src == NULL || dst == NULL || max == 0) {
    return false;
  }

  if (strlen(src) > max || strlen(dst) > max) {
    return false;
  }

  if (strlen(src) != strlen(dst)) {
    return false;
  }

  if (strncmp(src, dst, strlen(src))) {
    return false;
  }

  return true;
}



int main()
{
  warn("Start");

  char* iso_date = "2016-10-27T17:13:40Z";
  char* iso_date2 = "2016-10-27T17:13:40Z,,,,,,,,,,";
  char* iso_date3 = "2016-10-27T17:13:40Z1";
  char* iso_null = NULL;  

  // info("compare1: %d", strcmp_safe(iso_date, iso_date2, 24));
  // info("compare2: %d", strcmp_safe(iso_date, iso_null, 24));
  info("compare3: %d", strcmp_safe(iso_date, iso_date3, 1));

#if 0
  info("iso_date=%s", iso_date);
  dump(iso_date, 24, "iso");

  info("iso_date sizeof: %lu", sizeof(iso_date));
  info("iso_date strlen: %lu", strlen(iso_date));

  debug("before copy");
  dump(str_date, 32, "before copy");

  memset(str_date, 0, sizeof(str_date));
  dump(str_date, 32, "after memset");

  strncpy(str_date, iso_date, strlen(iso_date));

  debug("after copy");
  dump(str_date, 32, "after copy");

  info("str_date=%s", str_date);
  info("str_date sizeof: %lu", sizeof(str_date));
  info("str_date strlen: %lu", strlen(str_date));

#endif
  warn("End");
  return 0;
}
