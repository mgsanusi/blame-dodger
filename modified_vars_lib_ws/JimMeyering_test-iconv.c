#include <config.h>
#include "signature.h"
#include <errno.h>
#include <string.h>
#include "macros.h"
#include <stddef.h>
size_t new_strlen(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t new_strlen(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}
