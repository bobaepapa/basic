#include "common.h"


char* str_in_data = "1.0.0-alpha10";
const char* get_version_string(void)
{
  // return def2str(VERSION);
  return "1.0.0-alpha10";
}

int check_stack(int a, int b)
{
  char test [ 128 ];
  int c = a + b ;
  return c;
}

int main()
{
  char *a = NULL;
  char *b = "123";

  char str_buf[32] = {0,};
  memset(str_buf, 0xff, 32);
  dump(str_buf, 32, "buf");
  //info("strlen b: %lu", strlen(b));
  //info("strlen a: %lu", strlen(a));
  
  char *version = get_version_string();

  // XXX: DIE
  memset(version, 0, 0x100);

  info("%s : %lu", version, strlen(version));
  dump(version, 32, "version");


  info("c: %d", check_stack( 3, 5));
  
  info("%s : %lu", version, strlen(version));
  dump(version, 32, "version");
  // info("str_buf len: %d", sizeof(str_buf));

  // sprintf(str_buf, "M:%s", "1.0.0sddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
  // snprintf(str_buf, sizeof(str_buf), "M:%s","1.0.0");

  // dump(str_buf, 32, "buf");
}
