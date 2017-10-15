#include <config.h>
#include <unistd.h>
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dosname.h"
#include "filenamecat.h"
void *new_malloc(size_t size);
void new_assert(int expression);
void *new_realloc(void *ptr, size_t size);
void new_free(void *ptr);
void *new_malloc(size_t size);
void new_assert(int expression);
void *new_realloc(void *ptr, size_t size);
void new_free(void *ptr)
{
    return free(ptr);
}

void *new_malloc(size_t size);
void new_assert(int expression);
void *new_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void *new_malloc(size_t size);
void new_assert(int expression)
{
    return assert(expression);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
