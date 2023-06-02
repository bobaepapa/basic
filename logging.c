#include "common.h"

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif

void hex_dump(const void* mem, uint16_t len)
{
  size_t k = 0; // buf index

  for (uint16_t i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++) {
    // [좌측] mem 의 hex 번지 (실제 RAM 번지로 변경할 예정)
    if (i % HEXDUMP_COLS == 0) {
      PRINT_FUNC("%p: ", mem + i);
      k = 12;
    }

    // [중간] Hex 데이타 출력
    if (i < len) {
      PRINT_FUNC("%02x ", 0xFF & ((const char*)mem)[i]);
    }
    else {
      /* end of block, just aligning for ASCII dump */
      PRINT_FUNC("   ");
    }
    k += 3;

    // [우측] ASCII 문자열 출력
    if (i % HEXDUMP_COLS == (HEXDUMP_COLS - 1)) {
      for (uint16_t j = i - (HEXDUMP_COLS - 1); j <= i; j++) {
        if (j >= len) {
          /* end of block, not really printing */
          PRINT_FUNC(" ");
        }
        else if (isprint(((uint8_t*)mem)[j])) {
          /* printable char */
          PRINT_FUNC("%c", (0xFF & ((const char*)mem)[j]));
        }
        else {
          /* other char */
          PRINT_FUNC(".");
        }
      }
      PRINT_FUNC(LOGGING_NEW_LINE);
    }
  }
}
