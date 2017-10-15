#include "contiki.h"
#include "settings.h"

#include <stddef.h>
#include "dev/eeprom.h"
#include <stdio.h>
void * new_memset(void *ptr, int value, int num);



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}