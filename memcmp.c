#include "log_debug.h"

int main(void)
{
  warn("START");

  uint8_t card_number[9] = {
      0,
  };
  if (memcmp(card_number, "\x00\x00\x00\x00\x00\x00\x00\x00", 8) == 0) {
    info("mem matched");
  }
  else {
    info("mem NOT matched");
  }

  warn("END");
}
