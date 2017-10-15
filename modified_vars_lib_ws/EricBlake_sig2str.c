#include <config.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sig2str.h"
#include <stddef.h>
long
    long
char *new_strcpy(char *destination, const char *source);
int new_strncmp(const char *str1, const char *str2, size_t num);
int new_strtol(const char *str, char **endptr, int base);
char *new_strcpy(char *destination, const char *source);
int new_strncmp(const char *str1, const char *str2, size_t num);
int new_strtol(const char *str, char **endptr, int base)
{
	return strtol(str, endptr, base);
}

char *new_strcpy(char *destination, const char *source);
int new_strncmp(const char *str1, const char *str2, size_t num)
{
	return strncmp(str1, str2, num);
}

char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}
