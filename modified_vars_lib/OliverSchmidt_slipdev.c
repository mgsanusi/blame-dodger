#include "uip.h"
#include "slipdev.h"
#include <string.h>  /* For memcpy() */

#include <stddef.h>
void * new_memcpy(void *destination, const void *source, size_t num);



void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}