#include "contiki.h"
#include <string.h>
#include <stddef.h>
#include "rest-engine.h"
#include "dev/leds.h"
#include <stdio.h>
int new_strncmp (const char *str1, const char *str2, int num);
int
new_strncmp (const char *str1, const char *str2, int num)
{
  return strncmp (str1, str2, num);
}
