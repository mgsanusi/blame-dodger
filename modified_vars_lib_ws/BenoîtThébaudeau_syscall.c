#include <stdlib.h>
#include <stddef.h>
#include "../ff.h"
void *new_malloc(size_t size);
void *new_malloc(size_t size)
{
    return malloc(size);
}
