#include <config.h>
#include "idcache.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include "xalloc.h"
size_t new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source);
int new_strcmp(const char *str1, const char *str2);
size_t new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source);
int new_strcmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

size_t new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}
