#include <stdlib.h>
#include <alloca.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>
typedef int dummy;
char * new_strchr(char *str, int character);

void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void* new_realloc(void *ptr, size_t size);



char * new_strchr(char *str, int character);

void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
char * new_strchr(char *str, int character);

void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
char * new_strchr(char *str, int character);

void* new_malloc(size_t size) {
  return malloc(size);
}
char * new_strchr(char *str, int character) {
  return strchr(str, character);
}