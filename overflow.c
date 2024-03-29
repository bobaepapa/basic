#include "log_debug.h"

#define ADC_REFERENCE_VOLTAGE_MILLI 600u   /* 0.6V */
#define ADC_VALUE_RESOLUTION        16384u /* 14-bit */
#define ADC_GAIN                    6u     /* 1/6 */
#define ADC_CALIBRATION_INTERVAL    0x10000000u

static int16_t get_milli_volts(uint16_t adc)
{
  return (int16_t)((uint32_t)adc * ADC_REFERENCE_VOLTAGE_MILLI * ADC_GAIN / ADC_VALUE_RESOLUTION);
}

static int16_t get32_milli_volts(int32_t adc)
{
  return (int16_t)((int32_t)adc * ADC_REFERENCE_VOLTAGE_MILLI * ADC_GAIN / ADC_VALUE_RESOLUTION);
}


#define MS_TO_TICKS1(xTimeInMs) ((uint32_t)(((uint32_t)(xTimeInMs) * (uint32_t)configTICK_RATE_HZ) / (uint32_t)1000))
#define MS_TO_TICKS2(xTimeInMs) ((uint32_t)((uint32_t)(xTimeInMs) * (float) ((uint32_t)configTICK_RATE_HZ / (uint32_t)1000)))

int main()
{
  uint32_t hsum = 3303160;
  uint32_t hcnt = 50;

  printf("Overflow Test\n");

  int16_t volt   = get_milli_volts(hsum / hcnt);
  int16_t volt32 = get32_milli_volts(hsum / hcnt);

  printf("volt  : %d\n", volt);
  printf("volt32: %d\n", volt32);


  info("%u", (100*1024)/1000);
  info("%f", 100*(1024/1000));

  return 0;
}
