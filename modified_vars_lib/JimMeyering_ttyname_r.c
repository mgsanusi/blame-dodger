#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#include <stddef.h>
size_t new_strlen(const char *str);

void * new_memcpy(void *destination, const void *source, size_t num);



size_t new_strlen(const char *str);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}