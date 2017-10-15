#include "contiki.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include "rest-engine.h"
#include "dev/temperature-sensor.h"
int new_strlen(const char *str);

int new_snprintf(char *s, int n, const char *format, ...);

int new_abs(int x);



int new_strlen(const char *str);

int new_snprintf(char *s, int n, const char *format, ...);

int new_abs(int x) {
  return abs(x);
}
int new_strlen(const char *str) {
  return strlen(str);
}