#include "common.h"

int main()
{
  int i = 0;
  info("Start");

  for( i = 1; i <= 256; i ++ ) {
    printf("%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n",
        i, i, i, i, i, i, i, i, i, i, i, i, i, i, i, i);
  }

  info("End\n");
  return 0;
}
