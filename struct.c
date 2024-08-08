#include "common.h"

struct eth {
	uint8_t dst[6]; // 6
	uint8_t src[6]; // 12
	uint16_t etype; // 14
	uint8_t payload[0];
} __attribute__((packed));


int main()
{

  struct eth *eth; 

  info("sizeof struct eth =%ld", sizeof(struct eth));
  info("sizeof eth* =%ld", sizeof(*eth) );
  return 0;
}
