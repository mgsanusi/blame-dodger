#include "contiki.h"
#include <string.h>

#include <stddef.h>
#include "rest-engine.h"
#include "dev/battery-sensor.h"
int new_strlen(const char *str);



int new_strlen(const char *str) {
  return strlen(str);
}