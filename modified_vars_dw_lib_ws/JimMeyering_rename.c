#include <config.h>
#include <stdio.h>
#include <stddef.h>
int new_strlen (const char *str);
void new_free (void *ptr);
int new_strncmp (const char *str1, const char *str2, int num);
int new_strlen (const char *str);
void new_free (void *ptr);
int
new_strncmp (const char *str1, const char *str2, int num)
{
  return strncmp (str1, str2, num);
}

int new_strlen (const char *str);
void
new_free (void *ptr)
{
  return free (ptr);
}

int
new_strlen (const char *str)
{
  return strlen (str);
}
