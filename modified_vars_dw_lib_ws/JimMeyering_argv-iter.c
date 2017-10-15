#include <config.h>
#include <stddef.h>
#include "argv-iter.h"
#include <stdlib.h>
#include <string.h>
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
