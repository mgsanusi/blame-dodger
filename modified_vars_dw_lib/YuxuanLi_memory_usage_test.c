#include <stdio.h>
#include <string.h>

#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/host_port.h>
#include <grpc/support/string_util.h>
#include <grpc/support/subprocess.h>
#include "src/core/lib/support/string.h"
#include "test/core/util/port.h"
char * new_strcpy(char *destination, const char *source);

void * new_memcpy(void *destination, const void *source, int num);



char * new_strcpy(char *destination, const char *source);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}