#include "tunala.h"
int new_isdigit(int c);

int new_atoi(const char *str);



int new_isdigit(int c);

int new_atoi(const char *str) {
  return atoi(str);
}
int new_isdigit(int c) {
  return isdigit(c);
}