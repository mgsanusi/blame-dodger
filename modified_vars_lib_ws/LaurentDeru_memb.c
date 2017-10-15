#include <string.h>
#include "contiki.h"
#include <stddef.h>
#include "lib/memb.h"
void *new_memset(void *ptr, int value, size_t num);
void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}
