#include "common.h"

typedef enum {
  CONTROLLER_Boot,
  CONTROLLER_Standby,
  CONTROLLER_Charging,
  CONTROLLER_DisCharging,
  CONTROLLER_Emergency,
  CONTROLLER_Fault,
  CONTROLLER_Finish,

  CONTROLLER_SEQ_MAX,
} CONTROLLER_SEQ_e;

void calc_len(void* buf)
{
  printf("length buf=%lu\n", sizeof(buf));
}

int main()
{
  unsigned short* pBuf = (unsigned short*)malloc(1024);
  unsigned short  aBuf[1024];
  printf("Start\n");

  printf("length pBuf=%lu\n", sizeof(pBuf));
  printf("length aBuf=%lu\n", sizeof(aBuf));
  info("sizeof enum=%d\n", sizeof(CONTROLLER_SEQ_e));
  calc_len(pBuf);
  calc_len(aBuf);

  free(pBuf);
  printf("End\n");
  return 0;
}
