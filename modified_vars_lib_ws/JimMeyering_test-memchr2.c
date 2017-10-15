#include <config.h>
#include "memchr2.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include "zerosize-ptr.h"
#include "macros.h"
void *new_memset(void *ptr, int value, size_t num);
void *new_malloc(size_t size);
void *new_memset(void *ptr, int value, size_t num);
void *new_malloc(size_t size)
{
    return malloc(size);
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
