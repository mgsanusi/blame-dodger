#include <config.h>
#include <locale.h>
#include "signature.h"
#include <langinfo.h>
#include <monetary.h>
#include <stdio.h>
#include <string.h>
#include "macros.h"
#include <stdio.h>
#include <stddef.h>
char *new_strcpy (char *destination, const char *source);
int new_strcmp (const char *str1, const char *str2);
char *new_strcpy (char *destination, const char *source);
int
new_strcmp (const char *str1, const char *str2)
{
  return strcmp (str1, str2);
}

char *
new_strcpy (char *destination, const char *source)
{
  return strcpy (destination, source);
}
