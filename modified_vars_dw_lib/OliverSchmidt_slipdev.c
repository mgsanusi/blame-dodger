#include "uip.h"
#include "slipdev.h"
#include <string.h>  /* For memcpy() */

#include <stddef.h>
void * new_memcpy(void *destination, const void *source, int num);



void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}