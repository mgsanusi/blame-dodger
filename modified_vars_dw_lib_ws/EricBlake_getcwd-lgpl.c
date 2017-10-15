#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
typedef int dummy;
void *new_malloc(int size);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr);
void *new_malloc(int size);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_malloc(int size);
void *new_realloc(void *ptr, int size)
{
	return realloc(ptr, size);
}

void *new_malloc(int size)
{
	return malloc(size);
}
