#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/cc3200_vfs_dev_slfs_container_meta.h"
long
long int new_strtol(const char *str, char **endptr, int base);
int new_strtol(const char *str, char **endptr, int base)
{
    return strtol(str, endptr, base);
}
