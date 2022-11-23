#include <stdio.h>
#include <stdlib.h>

void calc_len(void *buf)
{
  printf("length buf=%lu\n", sizeof(buf));
}


int main()
{
  unsigned short* pBuf = (unsigned short*) malloc(1024);
  unsigned short aBuf[1024];
  printf("Start\n");
  
  printf("length pBuf=%lu\n", sizeof(pBuf));
  printf("length aBuf=%lu\n", sizeof(aBuf));
  calc_len(pBuf);
  calc_len(aBuf);

  free(pBuf);
  printf("End\n");
  return 0;
}
