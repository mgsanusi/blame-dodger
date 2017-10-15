#include <config.h>
#include "uniconv.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include <stddef.h>
#include <stddef.h>
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size);
void new_free(void *ptr)
{
    return free(ptr);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size)
{
    return malloc(size);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}
