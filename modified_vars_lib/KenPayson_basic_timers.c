#include <grpc/support/port_platform.h>
#include "src/core/lib/profiling/timers.h"
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/sync.h>
#include <grpc/support/thd.h>
#include <grpc/support/time.h>
#include <stdio.h>
#include <string.h>

#include <stddef.h>
#include "src/core/lib/support/env.h"
typedef enum { BEGIN = '{', END = '}', MARK = '.' } marker_type;
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

void new_free(void *ptr);



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size) {
  return malloc(size);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}