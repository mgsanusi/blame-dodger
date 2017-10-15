#include <string.h>
#include "contiki.h"
#include <stddef.h>
#include "lib/memb.h"
void *new_memset(void *ptr, int value, int num);
void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
