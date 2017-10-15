#include <config.h>
#include <errno.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "pty-private.h"
int new_strcmp(const char *str1, const char *str2);
int new_strcmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}
