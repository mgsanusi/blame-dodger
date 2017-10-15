#include <config.h>
#include <stdio.h>
size_t new_strlen (const char *str);
void new_free (void *ptr);
size_t new_strlen (const char *str);
void
new_free (void *ptr)
{
  return free (ptr);
}

size_t
new_strlen (const char *str)
{
  return strlen (str);
}
