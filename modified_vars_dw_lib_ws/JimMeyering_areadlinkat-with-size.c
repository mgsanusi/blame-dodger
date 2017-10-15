#include <config.h>
#include "areadlink.h"
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
void *new_malloc(int size);
void new_free(void *ptr);
void *new_malloc(int size);
void new_free(void *ptr)
{
    return free(ptr);
}

void *new_malloc(int size)
{
    return malloc(size);
}
