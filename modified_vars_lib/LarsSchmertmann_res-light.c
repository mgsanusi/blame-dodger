#include "contiki.h"
#include <string.h>

#include <stddef.h>
#include "rest-engine.h"
#include "dev/light-sensor.h"


size_t new_strlen(const char *str) {
  return strlen(str);
}