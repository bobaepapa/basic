#include "flash-layer.h"
#include "log_debug.h"

int main(void)
{
  struct my_flash* handle = flash_getHandle(XX_FLASH);

  handle->init();
  handle->read();
  handle->write();

  return 0;
}
