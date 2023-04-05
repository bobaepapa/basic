#include "log_debug.h"
#include <time.h>

const char* type1 = "2023-04-05T01:57:20.000Z";
const char* type2 = "2023-04-05T10:57:20+0900";

uint32_t iso8601_to_unix(const char* date)
{
  struct tm tt = {
      0,
  };
  int      ignore; // ignore mili, timeoffset
  uint32_t time_offset = 0;
  uint32_t unixtime    = 0;

  debug("%s(): parsing iso8601 string %s", __func__, date);
  if (sscanf(date, "%04d-%02d-%02dT%02d:%02d:%02d.%dZ", &tt.tm_year, &tt.tm_mon, &tt.tm_mday, &tt.tm_hour, &tt.tm_min, &tt.tm_sec, &ignore) != 7) {
    if (sscanf(date, "%04d-%02d-%02dT%02d:%02d:%02d+%02d00", &tt.tm_year, &tt.tm_mon, &tt.tm_mday, &tt.tm_hour, &tt.tm_min, &tt.tm_sec, &time_offset) != 7) {
      error("%s(): parsing", __func__);
      return unixtime;
    }
    debug("timeoffset %d", ignore);
  }

  tt.tm_year -= 1900; // Year since 1900
  tt.tm_mon -= 1;     // 0-11
  tt.tm_isdst = -1;

  unixtime = time_offset ? (uint32_t)mktime(&tt) - (time_offset * 3600) : (uint32_t)mktime(&tt); // 9 hours
  debug("%s(): [%d] time_offset: %d %04d-%02d-%02dT%02d:%02d:%02dZ", __func__, unixtime, time_offset, tt.tm_year + 1900, tt.tm_mon + 1, tt.tm_mday, tt.tm_hour, tt.tm_min, tt.tm_sec);
  return unixtime;
}

int main(int argc, char* argv[])
{
  warn("Start");

  uint32_t unix1 = iso8601_to_unix(type1);
  uint32_t unix2 = iso8601_to_unix(type2);

  info("%d, type1: %s", unix1, type1);
  info("%d, type2: %s", unix2, type2);

  warn("End");
}
