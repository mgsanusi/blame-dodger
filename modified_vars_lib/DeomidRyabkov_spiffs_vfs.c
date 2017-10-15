#include <spiffs_vfs.h>
#include <errno.h>
#include <stdio.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
#include <common/base64.h>
#include <common/cs_dbg.h>
typedef char sizeof_file_meta_is_wrong
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);

char * new_strchr(char *str, int character);


void* new_calloc(size_t num, size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void new_free(void *ptr);

char * new_strncpy(char *destination, const char* source, size_t num);



size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);

char * new_strchr(char *str, int character);


void* new_calloc(size_t num, size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void new_free(void *ptr);

char * new_strncpy(char *destination, const char* source, size_t num) {
  return strncpy(destination, source, num);
}
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);

char * new_strchr(char *str, int character);


void* new_calloc(size_t num, size_t size);

void * new_memcpy(void *destination, const void *source, size_t num);

void new_free(void *ptr) {
  return free(ptr);
}
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);

char * new_strchr(char *str, int character);


void* new_calloc(size_t num, size_t size);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
size_t new_strlen(const char *str);
void * new_memset(void *ptr, int value, size_t num);

char * new_strchr(char *str, int character);


void* new_calloc(size_t num, size_t size) {
  return calloc(num, size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
void * new_memset(void *ptr, int value, size_t num);

char * new_strchr(char *str, int character) {
  return strchr(str, character);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}