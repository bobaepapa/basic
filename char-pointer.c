#include <stdio.h>
#include <stdlib.h>

// void f(char* userInput) {
//	printf("%s", userInput);
// }

// const char *
// consr * char
// char const *
// char * const

const char *const get_str0(void)
{
  return "hello 0";
}

char *const get_str1(void)
{
  return "hello 1";
}

const char *get_str2(void)
{
  return "hello 2";
}

char const *get_str3(void)
{
  return "hello 3";
}

int main()
{
  // unsigned char buf[8] = { 0x12, 0x23,};

  // printf("Hello\n");
  // f("%s%s%s%s");
  // f("%08x %08x %08x %08x %08x\n");
  // view the stack or a memory at any location, by executing code equivalent to:

  // log_info("Start\n");

  const char *str1 = "I'm string.";
  // str1 = "me too";
  // str1[2] = '1';

  char *const str2 = "I'm string.";
  // str2 = "me too";
  // str2[2] = '1';

  const char *const str3 = "I'm string.";
  // str3 = "me too";
  // str3[2] = '1';

  char const *str4 = "I'm string.";
  // str4 = "me too";
  // str4[2] = '1';

  const char *const a0 = get_str0();
  // a0 = "s";
  // a0[3] = 's';
  // printf("a0=%s\n", a0);

  char *const a1 = get_str1();
  // a1 = "s";
  // printf("a1=%s\n", a1);

  const char *a2 = get_str2();
  // a2[2] = 's';
  // printf("a2=%s\n", a2);

  // 이건 어디서 온 문법??? const char *
  // char const *a3 = get_str3();
  //	a3 = "s";
  //	a3[3] = 's';

  printf("End\n");
  return 0;
}
