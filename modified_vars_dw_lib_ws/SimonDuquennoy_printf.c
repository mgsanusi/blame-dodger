#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <mc1322x.h>
#include <stdint.h>
int new_strlen(const char *str);
int new_strlen(const char *str)
{
	return strlen(str);
}
