#include <grpc/support/host_port.h>
#include <string.h>

#include <stddef.h>
#include <grpc/support/alloc.h>
#include <grpc/support/log.h>
#include <grpc/support/string_util.h>
#include "src/core/lib/support/string.h"
char * new_strchr(char *str, int character);

void * new_memcpy(void *destination, const void *source, size_t num);



char * new_strchr(char *str, int character);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
char * new_strchr(char *str, int character) {
  return strchr(str, character);
}