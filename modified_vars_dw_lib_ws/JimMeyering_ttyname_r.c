#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stddef.h>
int new_strlen(const char *str);
void *new_memcpy(void *destination, const void *source, int num);
int new_strlen(const char *str);
void *new_memcpy(void *destination, const void *source, int num)
{
    return memcpy(destination, source, num);
}

int new_strlen(const char *str)
{
    return strlen(str);
}
