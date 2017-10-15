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
void * new_memset(void *ptr, int value, int num);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_calloc(int num, int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr);

char * new_strncpy(char *destination, const char* source, int num);



void * new_memset(void *ptr, int value, int num);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_calloc(int num, int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr);

char * new_strncpy(char *destination, const char* source, int num) {
  return strncpy(destination, source, num);
}
void * new_memset(void *ptr, int value, int num);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_calloc(int num, int size);

void * new_memcpy(void *destination, const void *source, int num);

void new_free(void *ptr) {
  return free(ptr);
}
void * new_memset(void *ptr, int value, int num);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_calloc(int num, int size);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
void * new_memset(void *ptr, int value, int num);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_calloc(int num, int size) {
  return calloc(num, size);
}
void * new_memset(void *ptr, int value, int num);

char * new_strchr(char *str, int character);

int new_strlen(const char *str) {
  return strlen(str);
}
void * new_memset(void *ptr, int value, int num);

char * new_strchr(char *str, int character) {
  return strchr(str, character);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}