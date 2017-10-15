#include <config.h>
#include <stddef.h>
#include "argv-iter.h"
#include <stdlib.h>
#include <string.h>
void *new_malloc(size_t size);
void new_free(void *ptr);
void *new_malloc(size_t size);
void new_free(void *ptr)
{
    return free(ptr);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
