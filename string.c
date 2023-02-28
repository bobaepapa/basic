#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char str_date[24];

int main()
{
  printf("Start\n");
  
  char* iso_date = "2016-10-27T17:13:40Z";

  printf("iso_date=%s\n", iso_date);
  printf("iso_date sizeof =%d\n", sizeof(iso_date));
  printf("iso_date strlen =%d\n", strlen(iso_date));

  strncpy(str_date, iso_date, strlen(iso_date));

  printf("str_date=%s\n", str_date);
  printf("str_date sizeof =%d\n", sizeof(str_date));
  printf("str_date strlen =%d\n", strlen(str_date));

  printf("End\n");
  return 0;
}
