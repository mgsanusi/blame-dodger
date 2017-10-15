#include <config.h>
#include "uniconv.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include "c-strcaseeq.h"
#include "striconveha.h"
#include "unistr.h"
void *new_malloc(size_t size);
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_malloc(size_t size);
void *new_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
