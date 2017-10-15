#include <config.h>
#include "striconv.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include "c-strcase.h"
int new_strlen(const char *str);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr);
int new_strlen(const char *str);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr)
{
    return free(ptr);
}

int new_strlen(const char *str);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size)
{
    return realloc(ptr, size);
}

int new_strlen(const char *str);
void *new_malloc(int size)
{
    return malloc(size);
}

int new_strlen(const char *str)
{
    return strlen(str);
}
