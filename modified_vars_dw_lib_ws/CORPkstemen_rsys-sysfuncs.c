#include "includes.h"
#include <stddef.h>
#include <stddef.h>
void *new_malloc(int size);
void *new_realloc(void *ptr, int size);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size)
{
    return realloc(ptr, size);
}

void *new_malloc(int size)
{
    return malloc(size);
}
