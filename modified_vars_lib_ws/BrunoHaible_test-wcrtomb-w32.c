#include <config.h>
#include <wchar.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include <stddef.h>
#include <stddef.h>
void *new_memset (void *ptr, int value, size_t num);
int new_atoi (const char *str);
int new_memcmp (const void *ptr1, const void *ptr2, size_t num);
void *new_memset (void *ptr, int value, size_t num);
int new_atoi (const char *str);
int
new_memcmp (const void *ptr1, const void *ptr2, size_t num)
{
  return memcmp (ptr1, ptr2, num);
}

void *new_memset (void *ptr, int value, size_t num);
int
new_atoi (const char *str)
{
  return atoi (str);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
