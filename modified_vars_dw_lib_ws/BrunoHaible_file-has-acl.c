#include <config.h>
#include "acl.h"
#include <stddef.h>
#include "acl-internal.h"
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
