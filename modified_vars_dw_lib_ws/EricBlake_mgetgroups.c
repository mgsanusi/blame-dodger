#include <config.h>
#include "mgetgroups.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include "getugroups.h"
#include <stddef.h>
#include "xalloc-oversized.h"
void *new_realloc(void *ptr, int size);
void new_free(void *ptr);
void *new_realloc(void *ptr, int size);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_realloc(void *ptr, int size)
{
	return realloc(ptr, size);
}
