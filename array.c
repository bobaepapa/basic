#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_test(uint32_t* buf)
{

  uint32_t buf2[3] = {1, 2, 3};
  memcpy((void*)buf, (void*)buf2, buf2);
}

int main()
{
  int32_t  i       = 0;
  uint32_t buf[20] = {
      1,
  };
  printf("hello\n");

  for (i = 0; i < 20; i++) {
    printf("%02X ", buf[i]);
  }
  printf("\n");

  copy_test(buf);

  for (i = 0; i < 20; i++) {
    printf("%02X ", buf[i]);
  }
  return 0;
}
