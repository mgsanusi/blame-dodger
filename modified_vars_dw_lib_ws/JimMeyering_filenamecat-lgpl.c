#include <config.h>
#include "filenamecat.h"
#include <stdlib.h>
#include <string.h>
#include "dirname.h"
#include <stddef.h>
#include <stddef.h>
void *new_malloc(int size);
void *new_memcpy(void *destination, const void *source, int num);
void *new_malloc(int size);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}

void *new_malloc(int size)
{
	return malloc(size);
}
