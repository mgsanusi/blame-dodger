#include "k5-platform.h"
#include "profile.h"
#include "prof_int.h"
int new_strcmp(const char *str1, const char *str2);
void new_assert(int expression);
int new_strcmp(const char *str1, const char *str2);
void new_assert(int expression)
{
	return assert(expression);
}

int new_strcmp(const char *str1, const char *str2)
{
	return strcmp(str1, str2);
}
