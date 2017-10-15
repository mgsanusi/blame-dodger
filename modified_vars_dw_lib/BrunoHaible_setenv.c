#include <alloca.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
typedef int (*compar_fn_t) (const void *, const void *);
char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);

int new_strncmp(const char *str1, const char *str2, int num);



char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);

int new_strncmp(const char *str1, const char *str2, int num) {
  return strncmp(str1, str2, num);
}
char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}
char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
char * new_strchr(char *str, int character);

int new_strlen(const char *str) {
  return strlen(str);
}
char * new_strchr(char *str, int character) {
  return strchr(str, character);
}