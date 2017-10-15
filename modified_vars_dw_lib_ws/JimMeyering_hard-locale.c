#include <config.h>
#include "hard-locale.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>
int new_strcmp(const char *str1, const char *str2);
int new_strcmp(const char *str1, const char *str2)
{
	return strcmp(str1, str2);
}
