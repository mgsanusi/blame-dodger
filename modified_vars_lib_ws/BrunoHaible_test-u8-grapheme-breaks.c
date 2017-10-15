#include <config.h>
#include <unigbrk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include <stddef.h>
void *new_malloc(size_t size);
void *new_malloc(size_t size)
{
	return malloc(size);
}
