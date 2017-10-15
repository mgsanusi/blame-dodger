#include <config.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include "safe-alloc.h"
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
void *new_calloc(size_t num, size_t size);
void *new_malloc(size_t size);
void *new_realloc(void *ptr, size_t size);
void *new_calloc(size_t num, size_t size);
void *new_malloc(size_t size);
void *new_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void *new_calloc(size_t num, size_t size);
void *new_malloc(size_t size)
{
    return malloc(size);
}

void *new_calloc(size_t num, size_t size)
{
    return calloc(num, size);
}
