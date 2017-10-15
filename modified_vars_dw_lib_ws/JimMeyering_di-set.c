#include <config.h>
#include <stddef.h>
#include "di-set.h"
#include "hash.h"
#include "ino-map.h"
#include <limits.h>
#include <stdlib.h>
typedef size_t hashint;
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
