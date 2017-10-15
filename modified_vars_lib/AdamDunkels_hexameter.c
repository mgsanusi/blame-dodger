#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "ihx2bin.h"

#include <stddef.h>

#include <stddef.h>
size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);



void* new_malloc(size_t size);

int new_tolower(int c);

char * new_strcpy(char *destination, const char *source);

char * new_strncpy(char *destination, const char* source, size_t num);



size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);



void* new_malloc(size_t size);

int new_tolower(int c);

char * new_strcpy(char *destination, const char *source);

char * new_strncpy(char *destination, const char* source, size_t num) {
  return strncpy(destination, source, num);
}
size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);



void* new_malloc(size_t size);

int new_tolower(int c);

char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}
size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);



void* new_malloc(size_t size);

int new_tolower(int c) {
  return tolower(c);
}
size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);

int new_getc(FILE *stream);

char * new_strchr(char *str, int character);



void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
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