#ifndef _DEBUG_LOG_H_
#define _DEBUG_LOG_H_

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LOG_LEVEL  4
#define PRINT_FUNC printf

#define error(fmt, ...)                                                \
  do {                                                                     \
    if (LOG_LEVEL > 0) {                                                   \
      PRINT_FUNC("[\e[41mEROR\e[0m] %s(): " fmt, __func__, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                                    \
    }                                                                      \
  } while (0)

#define warn(fmt, ...)                                                 \
  do {                                                                     \
    if (LOG_LEVEL > 0) {                                                   \
      PRINT_FUNC("[\e[44mWARN\e[0m] %s(): " fmt, __func__, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                                    \
    }                                                                      \
  } while (0)

#define info(fmt, ...)                                 \
  do {                                                     \
    if (LOG_LEVEL > 1) {                                   \
      PRINT_FUNC("[\e[32mINFO\e[0m] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                    \
    }                                                      \
  } while (0)

#define debug(fmt, ...)                     \
  do {                                          \
    if (LOG_LEVEL > 2) {                        \
      PRINT_FUNC("[DBUG] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                         \
    }                                           \
  } while (0)

#define trace(fmt, ...)                                                                          \
  do {                                                                                               \
    if (LOG_LEVEL > 3) {                                                                             \
      PRINT_FUNC("[\e[35mTRAC\e[0m] %s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                                                              \
    }                                                                                                \
  } while (0)


void dump(void* mem, unsigned int len);

#endif
