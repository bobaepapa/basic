#include "singleton.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
  int c = 2;


  switch (c) {
    case 2:
      if (c != 2) {
        printf("__%d__\n", __LINE__);
        break;
      }
      printf("__%d__\n", __LINE__);
      break;
    case 3:
      printf("__%d__\n", __LINE__);
      break;
    default:
      printf("__%d__\n", __LINE__);
      break;
  }

  printf("__%d__\n", __LINE__);

  return 0;
}
