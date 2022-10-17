#ifndef _DEBUG_LOG_H_
#define _DEBUG_LOG_H_

#include <stdio.h>

#define LOG_LEVEL 4
#define PRINT_FUNC printf

#define log_error(fmt, ...)                                                \
  do {                                                                     \
    if (LOG_LEVEL > 0) {                                                   \
      PRINT_FUNC("[\e[41mEROR\e[0m] %s(): " fmt, __func__, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                                    \
    }                                                                      \
  } while (0)

#define log_warn(fmt, ...)                                                 \
  do {                                                                     \
    if (LOG_LEVEL > 0) {                                                   \
      PRINT_FUNC("[\e[43mWARN\e[0m] %s(): " fmt, __func__, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                                    \
    }                                                                      \
  } while (0)

#define log_info(fmt, ...)                                 \
  do {                                                     \
    if (LOG_LEVEL > 1) {                                   \
      PRINT_FUNC("[\e[42mINFO\e[0m] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                    \
    }                                                      \
  } while (0)

#define log_debug(fmt, ...)                                \
  do {                                                     \
    if (LOG_LEVEL > 2) {                                   \
      PRINT_FUNC("[\e[45mDBUG\e[0m] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                    \
    }                                                      \
  } while (0)

#define log_trace(fmt, ...)                                                                          \
  do {                                                                                               \
    if (LOG_LEVEL > 3) {                                                                             \
      PRINT_FUNC("[\e[44mTRAC\e[0m] %s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
      PRINT_FUNC("\n");                                                                              \
    }                                                                                                \
  } while (0)

#endif
