#include <stdio.h>
#include <io.h>
#include <string.h>
char *new_strcpy(char *destination, const char *source);
char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}
