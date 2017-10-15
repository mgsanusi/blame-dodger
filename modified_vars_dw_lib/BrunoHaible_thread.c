#include <config.h>

#include <stddef.h>
#include "glthread/thread.h"
#include <stdlib.h>
#include "glthread/lock.h"
#include <pthread.h>
#include <process.h>
void* new_malloc(int size);

void new_free(void *ptr);



void* new_malloc(int size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(int size) {
  return malloc(size);
}