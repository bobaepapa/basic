#ifndef _SINGLETON_H_
#define _SINGLETON_H_

typedef struct nvram {
  void (*read)(void);
  void (*write)(void);
} nvram_t;

nvram_t *get_nvram();
int nvram_init();

#endif
