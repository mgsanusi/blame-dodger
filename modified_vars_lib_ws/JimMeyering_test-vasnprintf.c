#include <config.h>
#include "vasnprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include <stddef.h>
#include <stddef.h>
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return memcmp(ptr1, ptr2, num);
}

void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}
