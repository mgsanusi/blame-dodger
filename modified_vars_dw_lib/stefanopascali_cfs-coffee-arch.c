#include "cfs-coffee-arch.h"
#include <stdio.h>
#include <stdio.h>

#include <stddef.h>

#include <stddef.h>
#include "cfs/cfs.h"
#include "cfs/cfs-coffee.h"
#include "lib/crc16.h"
#include "lib/random.h"
#include <stdio.h>
void * new_memset(void *ptr, int value, int num);

void * new_memcpy(void *destination, const void *source, int num);



void * new_memset(void *ptr, int value, int num);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}