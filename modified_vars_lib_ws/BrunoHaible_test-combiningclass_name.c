#include <config.h>
#include "unictype.h"
#include <string.h>
#include "macros.h"
int new_strcmp (const char *str1, const char *str2);
int
new_strcmp (const char *str1, const char *str2)
{
  return strcmp (str1, str2);
}
