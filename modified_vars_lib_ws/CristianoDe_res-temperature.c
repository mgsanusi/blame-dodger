#include "contiki.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "rest-engine.h"
#include "dev/temperature-sensor.h"
size_t new_strlen(const char *str);
int new_snprintf(char *s, size_t n, const char *format, ...);
int new_abs(int x);
size_t new_strlen(const char *str);
int new_snprintf(char *s, size_t n, const char *format, ...);
int new_abs(int x)
{
    return abs(x);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}
