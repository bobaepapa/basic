#include "flash-layer.h"

#include <stdio.h>
#include <stdlib.h>

static struct my_flash* flash_inst = NULL;

void stflash_init(void)
{
  printf("%s()\n", __func__);
}

void stflash_read(void)
{
  printf("%s()\n", __func__);
}

void stflash_write(void)
{
  printf("%s()\n", __func__);
}

void xxflash_init(void)
{
  printf("%s()\n", __func__);
}

void xxflash_read(void)
{
  printf("%s()\n", __func__);
}

void xxflash_write(void)
{
  printf("%s()\n", __func__);
}

struct my_flash* flash_getHandle(enum flash_type type)
{
  flash_inst = (struct my_flash*)malloc(sizeof(struct my_flash));
  if (type == ST_FLASH) {
    flash_inst->init  = stflash_init;
    flash_inst->write = stflash_write;
    flash_inst->read  = stflash_read;
  }
  else if (type == XX_FLASH) {
    flash_inst->init  = xxflash_init;
    flash_inst->write = xxflash_write;
    flash_inst->read  = xxflash_read;
  }
  else {
    return NULL;
  }
  return flash_inst;
}
