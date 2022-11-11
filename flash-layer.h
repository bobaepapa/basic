#ifndef _FLASH_H_
#define _FLASH_H_

struct my_flash {
  void (*init)(void);
  void (*read)(void);
  void (*write)(void);
};

enum flash_type {
  ST_FLASH = 0,
  XX_FLASH
};

extern struct my_flash* flash_getHandle(enum flash_type type);

#endif //
