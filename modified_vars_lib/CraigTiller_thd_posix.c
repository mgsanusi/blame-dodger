#include <grpc/support/port_platform.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/thd.h>
#include <grpc/support/useful.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
void* new_malloc(size_t size);

void new_free(void *ptr);



void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(size_t size) {
  return malloc(size);
}