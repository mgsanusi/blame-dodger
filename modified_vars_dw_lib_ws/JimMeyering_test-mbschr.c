#include <config.h>
#include <string.h>
#include <locale.h>
#include "macros.h"
char *new_strchr(char *str, int character);
char *new_strchr(char *str, int character)
{
	return strchr(str, character);
}
