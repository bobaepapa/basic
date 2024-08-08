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
  *buf   = v & 0xff;
}

static inline float read_float(const uint8_t buf[4])
{
  union {
    float   number;
    uint8_t bytes[4];
  } float_data;

  float_data.bytes[3] = buf[0];
  float_data.bytes[2] = buf[1];
  float_data.bytes[1] = buf[2];
  float_data.bytes[0] = buf[3];

  return float_data.number;
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

  uint8_t f_data[4] = {
      // 0x42, 0x20, 0x00, 0x00,  // 40.0
      0x40, 0x19, 0x99, 0x9a, // 2.40
  };
  info("read float: %.3f", read_float(f_data));
  info("read float: %d", (uint32_t)read_float(f_data));

  float temp_f     = 24.770348;
  float humid_f = 37.392231;
  uint32_t temp_u = (uint32_t)(temp_f * 100);
  uint32_t humid_u = (uint32_t)(humid_f * 100);

  info("temp_f: %.3f, humud_f: %.3f", temp_f, humid_f);
  info("temp_u: %d, humud_u: %d", temp_u, humid_u);

  warn("End");

  return 0;
}
