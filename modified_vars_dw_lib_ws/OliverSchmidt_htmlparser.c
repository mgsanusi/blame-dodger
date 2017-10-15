#include <string.h>
#include "contiki.h"
#include <stddef.h>
#include <stddef.h>
#include "html-strings.h"
#include "www.h"
#include "htmlparser.h"
#include <stdio.h>
char *new_strcpy(char *destination, const char *source);
char *new_strncpy(char *destination, const char *source, int num);
int new_strncmp(const char *str1, const char *str2, int num);
char *new_strcpy(char *destination, const char *source);
char *new_strncpy(char *destination, const char *source, int num);
int new_strncmp(const char *str1, const char *str2, int num)
{
	return strncmp(str1, str2, num);
}

char *new_strcpy(char *destination, const char *source);
char *new_strncpy(char *destination, const char *source, int num)
{
	return strncpy(destination, source, num);
}

char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}
