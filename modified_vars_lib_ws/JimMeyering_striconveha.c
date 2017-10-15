#include <config.h>
#include "striconveha.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "malloca.h"
#include <stddef.h>
#include <stddef.h>
#include "c-strcase.h"
#include "striconveh.h"
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
void *new_memcpy(void *destination, const void *source, size_t num);
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size)
{
	return malloc(size);
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}
