#include <config.h>
#include "unistr.h"
#include <string.h>
#include <stddef.h>
char *new_strncpy(char *destination, const char *source, int num);
char *new_strncpy(char *destination, const char *source, int num)
{
	return strncpy(destination, source, num);
}
