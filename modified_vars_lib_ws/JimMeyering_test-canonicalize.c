#include <config.h>
#include "canonicalize.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "same-inode.h"
#include "ignore-value.h"
#include "macros.h"
size_t new_strlen (const char *str);
int new_strcmp (const char *str1, const char *str2);
void new_free (void *ptr);
size_t new_strlen (const char *str);
int new_strcmp (const char *str1, const char *str2);
void
new_free (void *ptr)
{
  return free (ptr);
}

size_t new_strlen (const char *str);
int
new_strcmp (const char *str1, const char *str2)
{
  return strcmp (str1, str2);
}

size_t
new_strlen (const char *str)
{
  return strlen (str);
}
