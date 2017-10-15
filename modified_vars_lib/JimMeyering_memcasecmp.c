#include <config.h>
#include "memcasecmp.h"
#include <ctype.h>
#include <limits.h>
int new_toupper(int c);



int new_toupper(int c) {
  return toupper(c);
}