#include "portable.h"
#include <stdio.h>
#include <ac/stdlib.h>
#include <ac/setproctitle.h>
#include <ac/string.h>
#include <ac/stdarg.h>
int new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source);
int new_strlen(const char *str);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

int new_strlen(const char *str)
{
    return strlen(str);
}
