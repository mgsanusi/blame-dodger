#include "k5-platform.h"
#include <sys/types.h>
#include <string.h>
int new_strlen(const char *str);
int new_strlen(const char *str)
{
    return strlen(str);
}
