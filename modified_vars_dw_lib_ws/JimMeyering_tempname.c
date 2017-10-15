#include <sys/types.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/stat.h>
int new_strlen (const char *str);
void new_assert (int expression);
int new_memcmp (const void *ptr1, const void *ptr2, int num);
int new_strlen (const char *str);
void new_assert (int expression);
int
new_memcmp (const void *ptr1, const void *ptr2, int num)
{
  return memcmp (ptr1, ptr2, num);
}

int new_strlen (const char *str);
void
new_assert (int expression)
{
  return assert (expression);
}

int
new_strlen (const char *str)
{
  return strlen (str);
}
