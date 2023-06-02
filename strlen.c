#include "common.h"

const char* system_get_version_string(void)
{
  // return def2str(VERSION);
  return "1.0.0-alpha10";
}

int main()
{
  char *a = NULL;
  char *b = "123";

  char str_buf[32] = {0,};
  //info("strlen b: %lu", strlen(b));
  //info("strlen a: %lu", strlen(a));
  
  char *version = system_get_version_string();
  info("len : %lu", strlen(version));

  // char *ver = strtok(version, "-");
  // dump(ver, 32);
  
  // info("ver: %s", ver);

  snprintf(str_buf, 5, "M:%s",system_get_version_string());

  dump(str_buf, 32, "buf");
  hex_dump(str_buf, 32);
}
