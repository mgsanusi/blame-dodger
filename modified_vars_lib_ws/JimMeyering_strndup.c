#include <config.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
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
