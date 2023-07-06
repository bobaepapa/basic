#include "common.h"

/** Encode v as a 32-bit little endian quantity into buf. */
static inline void write32_le(uint32_t v, uint8_t buf[4])
{
  *buf++ = v & 0xff;
  *buf++ = (v >> 8) & 0xff;
  *buf++ = (v >> 16) & 0xff;
  *buf   = (v >> 24) & 0xff;
}

static inline void write32_be(uint32_t v, uint8_t buf[4])
{
  *buf++ = (v >> 24) & 0xff;
  *buf++ = (v >> 16) & 0xff;
  *buf++ = (v >> 8) & 0xff;
  *buf = v & 0xff;
}
static inline uint32_t read_float_le(const uint8_t buf[4])
{
  union {
    float   number;
    uint8_t bytes[4];
  } float_data;

  float_data.bytes[3] = buf[0];
  float_data.bytes[2] = buf[1];
  float_data.bytes[1] = buf[2];
  float_data.bytes[0] = buf[3];

  return (uint32_t)(float_data.number);
}

uint32_t byte_to_float(uint8_t data_1, uint8_t data_2, uint8_t data_3, uint8_t data_4)
{
  union {
    float   number;
    uint8_t bytes[4];
  } float_data;

  float_data.bytes[3] = data_1;
  float_data.bytes[2] = data_2;
  float_data.bytes[1] = data_3;
  float_data.bytes[0] = data_4;

  return (uint32_t)(float_data.number);
}

int main()
{
  warn("Start");

  uint8_t data[4] = {
      0,
  };

  float v = 500;
  dump(&v, 4, "v");

  uint32_t u = 500;
  dump(&u, 4, "u");

  write32_be(v, data);
  dump(data, 4, "BE");
  write32_le(v, data);
  dump(data, 4, "LE");


  data[3] = 0x00;
  data[2] = 0x00;
  data[1] = 0xfa;
  data[0] = 0x43;
  info("read float: %d", read_float_le(data));
  warn("End");

  return 0;
}
