#include <stdarg.h>
#include "segger-rtt.h"
int new_putchar(int character);


int SEGGER_RTT_vprintf(unsigned BufferIndex, const char * sFormat, va_list * pParamList);

int
new_putchar(int c)
{
  SEGGER_RTT_Write(0, &c, 1);
  return c;
}

int
printf(const char *fmt, ...)
{
  int res;
  va_list ap;
  va_start(ap, fmt);
  res = SEGGER_RTT_vprintf(0, fmt, &ap);
  va_end(ap);
  return res;
}



int new_putchar(int character) {
  return putchar(character);
}