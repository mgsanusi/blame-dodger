#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include "glthread/tls.h"
#include "glthread/thread.h"
#include "glthread/yield.h"
#include <stdio.h>
int new_rand();

void* new_malloc(size_t size);



int new_rand();

void* new_malloc(size_t size) {
  return malloc(size);
}
int new_rand() {
  return rand();
}