#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include "glthread/lock.h"
#include "glthread/thread.h"
#include "glthread/yield.h"
#include <stdio.h>
int new_rand();

void * new_memcpy(void *destination, const void *source, size_t num);



int new_rand();

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
int new_rand() {
  return rand();
}