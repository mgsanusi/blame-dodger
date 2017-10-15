#include <config.h>
#include <stdio.h>
#include <string.h>
#include "sha1.h"
#include <stddef.h>
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}
