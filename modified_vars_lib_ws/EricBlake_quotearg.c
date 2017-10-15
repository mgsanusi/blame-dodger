#include <config.h>
#include "quotearg.h"
#include "xalloc.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include "gettext.h"
#include <stddef.h>
#include <stddef.h>
size_t new_strlen(const char *str);
void *new_memset(void *ptr, int value, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t new_strlen(const char *str);
void *new_memset(void *ptr, int value, size_t num);
void new_free(void *ptr);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return memcmp(ptr1, ptr2, num);
}

size_t new_strlen(const char *str);
void *new_memset(void *ptr, int value, size_t num);
void new_free(void *ptr)
{
	return free(ptr);
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}
