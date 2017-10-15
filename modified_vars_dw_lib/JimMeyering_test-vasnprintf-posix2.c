#include <config.h>
#include "vasnprintf.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr);



int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr) {
  return free(ptr);
}
int new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}
int new_strlen(const char *str) {
  return strlen(str);
}