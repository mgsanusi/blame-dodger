#include "segstack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, int num);
void *new_calloc(int num, int size);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, int num);
void *new_memset(void *ptr, int value, int num);
void *new_calloc(int num, int size);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, int num)
{
    return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, int num);
void *new_calloc(int num, int size);
void new_assert(int expression)
{
    return assert(expression);
}

void *new_memset(void *ptr, int value, int num);
void *new_calloc(int num, int size)
{
    return calloc(num, size);
}

void *new_memset(void *ptr, int value, int num)
{
    return memset(ptr, value, num);
}
