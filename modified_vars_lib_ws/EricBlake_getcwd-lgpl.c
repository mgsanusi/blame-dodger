#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
typedef int dummy;
void *new_malloc(size_t size);
void *new_realloc(void *ptr, size_t size);
void new_free(void *ptr);
void *new_malloc(size_t size);
void *new_realloc(void *ptr, size_t size);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_malloc(size_t size);
void *new_realloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}

void *new_malloc(size_t size)
{
	return malloc(size);
}
