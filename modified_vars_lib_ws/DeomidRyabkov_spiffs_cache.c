#include "spiffs.h"
#include "spiffs_nucleus.h"
#include <stddef.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num);
void *new_memset(void *ptr, int value, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}
