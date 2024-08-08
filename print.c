#include "common.h"
#include <locale.h>

int main()
{
  warn("Start");

  uint32_t value = 123001;

  // setlocale(LC_ALL, ""); 
  info("value: %.3f", (float)value / 1000.0f);

  float result = (float)value / 1000.0f;
  info("result: %f", result);

  warn("End");
  return 0;
}
