#include "log_debug.h"

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif

#if 1
#define HEXDUMP_MAXLEN 80
void dump(void* mem, unsigned int len)
{
  char     buf[HEXDUMP_MAXLEN];
  unsigned index;

  unsigned int i, j;

  for (i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++) {
    /* print offset */
    if (i % HEXDUMP_COLS == 0) {
      // PRINT_FUNC("0x%06x: ", i);
      memset(buf, 0, HEXDUMP_MAXLEN);
      sprintf(&buf[0], "%p: ", mem + i);
      index = strlen(buf);
    }

    /* print hex data */
    if (i < len) {
      // PRINT_FUNC("%02x ", 0xFF & ((char*)mem)[i]);
      sprintf(&buf[index], "%02x ", 0xFF & ((char*)mem)[i]);
    }
    else /* end of block, just aligning for ASCII dump */
    {
      // PRINT_FUNC("   ");
      sprintf(&buf[index], "   ");
    }
    index += 3;

    /* print ASCII dump */
    if (i % HEXDUMP_COLS == (HEXDUMP_COLS - 1)) {
      for (j = i - (HEXDUMP_COLS - 1); j <= i; j++) {
        if (j >= len) /* end of block, not really printing */
        {
          // putchar(' ');
          sprintf(&buf[index], " ");
          index++;
        }
        else if (isprint(((char*)mem)[j])) /* printable char */
        {
          // putchar(0xFF & ((char*)mem)[j]);
          sprintf(&buf[index], "%c", (0xFF & ((char*)mem)[j]));
          index++;
        }
        else /* other char */
        {
          // putchar('.');
          sprintf(&buf[index], ".");
          index++;
        }
      }
      // putchar('\n');
      PRINT_FUNC("%s [%d]\n", buf, index);
    }
  }
}
#else
void hexdump(void* mem, unsigned int len)
{
  unsigned int i, j;

  for (i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++) {
    /* print offset */
    if (i % HEXDUMP_COLS == 0) {
      PRINT_FUNC("0x%06x: ", i);
    }

    /* print hex data */
    if (i < len) {
      PRINT_FUNC("%02x ", 0xFF & ((char*)mem)[i]);
    }
    else /* end of block, just aligning for ASCII dump */
    {
      PRINT_FUNC("   ");
    }

    /* print ASCII dump */
    if (i % HEXDUMP_COLS == (HEXDUMP_COLS - 1)) {
      for (j = i - (HEXDUMP_COLS - 1); j <= i; j++) {
        if (j >= len) /* end of block, not really printing */
        {
          putchar(' ');
        }
        else if (isprint(((char*)mem)[j])) /* printable char */
        {
          putchar(0xFF & ((char*)mem)[j]);
        }
        else /* other char */
        {
          putchar('.');
        }
      }
      putchar('\n');
    }
  }
}
#endif
