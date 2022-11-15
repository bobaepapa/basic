#include <stdio.h>

typedef void (*callback_type)(void);

void callback(void)
{
  printf(">> %s()\n", __func__);

  return;
}

void need_callback(callback_type f)
{
  printf(">> %s()\n", __func__);
  f();
}

int main(void)
{
  int  var  = 0;
  int* pVar = &var;

  printf(">> %s()\n", __func__);

  printf("callback=%p\n", callback);
  printf("&callback=%p\n", &callback);

  printf("&var=%p\n", &var);
  printf("var2=%p\n", pVar);

  need_callback(&callback);
  return 0;
}
