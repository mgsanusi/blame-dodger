#include <config.h>
#include "localcharset.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

char * new_strcpy(char *destination, const char *source);

int new_fscanf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);

void new_free(void *ptr);



int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

char * new_strcpy(char *destination, const char *source);

int new_fscanf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size);

void new_free(void *ptr) {
  return free(ptr);
}
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

char * new_strcpy(char *destination, const char *source);

int new_fscanf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, int num);

void* new_realloc(void *ptr, int size) {
  return realloc(ptr, size);
}
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

char * new_strcpy(char *destination, const char *source);

int new_fscanf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, int num) {
  return memcpy(destination, source, num);
}
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size);

char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);

int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);

int new_strlen(const char *str) {
  return strlen(str);
}
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character) {
  return strchr(str, character);
}
int new_fclose(FILE *stream);

int new_getc(FILE *stream) {
  return getc(stream);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}