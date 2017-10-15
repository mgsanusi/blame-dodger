#include <alloca.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
typedef int (*compar_fn_t) (const void *, const void *);
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);


void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void* new_realloc(void *ptr, size_t size);

int new_strncmp(const char *str1, const char *str2, size_t num);



size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);


void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void* new_realloc(void *ptr, size_t size);

int new_strncmp(const char *str1, const char *str2, size_t num) {
  return strncmp(str1, str2, num);
}
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);


void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void* new_realloc(void *ptr, size_t size) {
  return realloc(ptr, size);
}
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);


void* new_malloc(size_t size);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);


void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
char * new_strchr(char *str, int character) {
  return strchr(str, character);
}