#include "contiki.h"
#include <string.h>
#include "bme280.h"

#include <stddef.h>
#include "bme280-arch.h"
#include "lib/sensors.h"
void * new_memset(void *ptr, int value, size_t num);



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}