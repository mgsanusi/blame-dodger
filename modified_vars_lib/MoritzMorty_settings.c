#include "contiki.h"
#include "settings.h"

#include <stddef.h>
#include "dev/eeprom.h"
#include <stdio.h>
void * new_memset(void *ptr, int value, size_t num);



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}