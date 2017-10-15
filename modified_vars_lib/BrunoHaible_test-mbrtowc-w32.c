#include <config.h>
#include <wchar.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

#include <stddef.h>
void * new_memset(void *ptr, int value, size_t num);

int new_atoi(const char *str);



void * new_memset(void *ptr, int value, size_t num);

int new_atoi(const char *str) {
  return atoi(str);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}