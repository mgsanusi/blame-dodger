#include "portable.h"
#include <stdio.h>
#include <ac/stdlib.h>
#include <ac/setproctitle.h>
#include <ac/string.h>
#include <ac/stdarg.h>
size_t new_strlen (const char *str);
char *new_strcpy (char *destination, const char *source);
size_t new_strlen (const char *str);
char *
new_strcpy (char *destination, const char *source)
{
  return strcpy (destination, source);
}

size_t
new_strlen (const char *str)
{
  return strlen (str);
}
