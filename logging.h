#ifndef _LOGGING_H_
#define _LOGGING_H_

enum {
  LOG_LEVEL_NONE,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARN,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_DUMP,
  LOG_LEVEL_TRACE,
};

#define LOG_LEVEL        LOG_LEVEL_TRACE

#define __FILENAME__     (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define PRINT_FUNC       printf
#define LOGGING_NEW_LINE "\n"

#define error(fmt, ...)                                                            \
  do {                                                                             \
    if (LOG_LEVEL >= LOG_LEVEL_ERROR) {                                            \
      PRINT_FUNC("[\e[41mEROR\e[0m] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC(LOGGING_NEW_LINE);                                                \
    }                                                                              \
  } while (0)

#define warn(fmt, ...)                                                             \
  do {                                                                             \
    if (LOG_LEVEL >= LOG_LEVEL_WARN) {                                             \
      PRINT_FUNC("[\e[44mWARN\e[0m] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC(LOGGING_NEW_LINE);                                                \
    }                                                                              \
  } while (0)

#define info(fmt, ...)                                                             \
  do {                                                                             \
    if (LOG_LEVEL >= LOG_LEVEL_INFO) {                                             \
      PRINT_FUNC("[\e[32mINFO\e[0m] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC(LOGGING_NEW_LINE);                                                \
    }                                                                              \
  } while (0)

#define debug(fmt, ...)                                                 \
  do {                                                                  \
    if (LOG_LEVEL >= LOG_LEVEL_DEBUG) {                                 \
      PRINT_FUNC("[DBUG] " fmt, ##__VA_ARGS__); \
      PRINT_FUNC(LOGGING_NEW_LINE);                                     \
    }                                                                   \
  } while (0)

void hex_dump(const void* mem, uint16_t len);
#define dump(mem, len, desc)                                 \
  do {                                                       \
    if (LOG_LEVEL >= LOG_LEVEL_DUMP) {                       \
      PRINT_FUNC("[DUMP] %s", desc); \
      PRINT_FUNC(LOGGING_NEW_LINE);                          \
      hex_dump(mem, len);                                    \
    }                                                        \
  } while (0)

#define trace()                                                                                                \
  do {                                                                                                         \
    if (LOG_LEVEL >= LOG_LEVEL_TRACE) {                                                                        \
      PRINT_FUNC("[\e[35mTRAC\e[0m] %s() [%s: %d]", __func__, __FILENAME__, __LINE__); \
      PRINT_FUNC(LOGGING_NEW_LINE);                                                                            \
    }                                                                                                          \
  } while (0)

#endif
