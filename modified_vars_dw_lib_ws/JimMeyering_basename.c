#include <config.h>
#include "dirname.h"
#include <string.h>
#include "xalloc.h"
#include "xstrndup.h"
#include <stddef.h>
void *new_memcpy(void *destination, const void *source, int num);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}
