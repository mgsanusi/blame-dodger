#include <config.h>
#include "progname.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/stat.h>
#include "relocatable.h"
char *new_strchr (char *str, int character);
int new_strlen (const char *str);
char *new_strcpy (char *destination, const char *source);
void *new_memcpy (void *destination, const void *source, int num);
void new_free (void *ptr);
int new_memcmp (const void *ptr1, const void *ptr2, int num);
char *new_strchr (char *str, int character);
int new_strlen (const char *str);
char *new_strcpy (char *destination, const char *source);
void *new_memcpy (void *destination, const void *source, int num);
void new_free (void *ptr);
int
new_memcmp (const void *ptr1, const void *ptr2, int num)
{
  return memcmp (ptr1, ptr2, num);
}

char *new_strchr (char *str, int character);
int new_strlen (const char *str);
char *new_strcpy (char *destination, const char *source);
void *new_memcpy (void *destination, const void *source, int num);
void
new_free (void *ptr)
{
  return free (ptr);
}

char *new_strchr (char *str, int character);
int new_strlen (const char *str);
char *new_strcpy (char *destination, const char *source);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}

char *new_strchr (char *str, int character);
int new_strlen (const char *str);
char *
new_strcpy (char *destination, const char *source)
{
  return strcpy (destination, source);
}

char *new_strchr (char *str, int character);
int
new_strlen (const char *str)
{
  return strlen (str);
}

char *
new_strchr (char *str, int character)
{
  return strchr (str, character);
}
