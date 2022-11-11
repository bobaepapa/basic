#include <stdio.h>
#include <stdlib.h>

#include "singleton.h"

void nvram_read()
{
  printf("nvram_read()\n");
}

void nvram_write()
{
  printf("nvram_write()\n");
}

nvram_t* get_nvram(void)
{
  static nvram_t* instance = NULL;

  if (instance == NULL) {
    instance = malloc(sizeof(nvram_t));
    instance->read = nvram_read;
    instance->write = nvram_write;
  }
  return instance;
}
