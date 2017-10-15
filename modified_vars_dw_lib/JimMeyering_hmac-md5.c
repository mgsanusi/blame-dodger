#include <config.h>
#include "hmac.h"
#include "memxor.h"
#include "md5.h"
#include <string.h>

#include <stddef.h>
void * new_memset(void *ptr, int value, int num);



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}