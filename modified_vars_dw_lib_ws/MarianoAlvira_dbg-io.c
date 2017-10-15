#include <stdio.h>
#include <string.h>
#include "uart1.h"
#include "contiki-conf.h"
int new_puts (const char *str);
int
new_puts (const char *str)
{
  return puts (str);
}
