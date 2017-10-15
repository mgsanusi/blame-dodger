#include "contiki.h"
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include "rest-engine.h"
#include "dev/radio-sensor.h"
int new_strlen(const char *str);
int new_snprintf(char *s, int n, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, int num);
int new_strlen(const char *str);
int new_snprintf(char *s, int n, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, int num)
{
	return strncmp(str1, str2, num);
}

int new_strlen(const char *str)
{
	return strlen(str);
}
