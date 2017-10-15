#include "contiki.h"
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include "rest-engine.h"
#include "dev/radio-sensor.h"
size_t new_strlen(const char *str);
int new_snprintf(char *s, size_t n, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, size_t num);
size_t new_strlen(const char *str);
int new_snprintf(char *s, size_t n, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, size_t num)
{
    return strncmp(str1, str2, num);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}
