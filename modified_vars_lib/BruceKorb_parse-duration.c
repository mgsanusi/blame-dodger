#include <config.h>

#include <stddef.h>
#include "parse-duration.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {


long
long
time_t new_time(time_t *timer);
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);



int new_isspace(int c);

int new_isdigit(int c);

void * new_memcpy(void *destination, const void *source, size_t num);
 int new_strtol(const char* str, char** endptr, int base);

time_t new_time(time_t *timer);
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);



int new_isspace(int c);

int new_isdigit(int c);

void * new_memcpy(void *destination, const void *source, size_t num);
 int new_strtol(const char* str, char** endptr, int base) {
  return strtol(str, endptr, base);
}
time_t new_time(time_t *timer);
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);



int new_isspace(int c);

int new_isdigit(int c);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
time_t new_time(time_t *timer);
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);



int new_isspace(int c);

int new_isdigit(int c) {
  return isdigit(c);
}
time_t new_time(time_t *timer);
size_t new_strlen(const char *str);
char * new_strchr(char *str, int character);



int new_isspace(int c) {
  return isspace(c);
}
time_t new_time(time_t *timer) {
  return time(timer);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
char * new_strchr(char *str, int character) {
  return strchr(str, character);
}