#include "setup.h"
#include <stddef.h>
#include <string.h>
#include "strtok.h"
char *new_strchr (char *str, int character);
char *
new_strchr (char *str, int character)
{
  return strchr (str, character);
}
