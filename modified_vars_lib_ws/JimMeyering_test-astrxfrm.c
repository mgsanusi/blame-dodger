#include <config.h>
#include "astrxfrm.h"
#include <locale.h>
#include <string.h>
#include "macros.h"
size_t new_strlen(const char *str);
int new_strcmp(const char *str1, const char *str2);
size_t new_strlen(const char *str);
int new_strcmp(const char *str1, const char *str2)
{
	return strcmp(str1, str2);
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}
