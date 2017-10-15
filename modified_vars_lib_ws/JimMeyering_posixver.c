#include <config.h>
#include "posixver.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
long
long int new_strtol(const char *str, char **endptr, int base);
int new_strtol(const char *str, char **endptr, int base)
{
    return strtol(str, endptr, base);
}
