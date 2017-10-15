#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


long
long
int new_toupper(int c);

int new_isspace(int c);

int new_isalpha(int c);
 int new_strtol(const char* str, char** endptr, int base);

int new_toupper(int c);

int new_isspace(int c);

int new_isalpha(int c);
 int new_strtol(const char* str, char** endptr, int base) {
  return strtol(str, endptr, base);
}
int new_toupper(int c);

int new_isspace(int c);

int new_isalpha(int c) {
  return isalpha(c);
}
int new_toupper(int c);

int new_isspace(int c) {
  return isspace(c);
}
int new_toupper(int c) {
  return toupper(c);
}