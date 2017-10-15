#include <config.h>
#include "chdir-long.h"
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
istream& new_getline(istream& is, string& str);
int new_fclose(FILE *stream);

void new_assert(int expression);


void new_exit(int status);



istream& new_getline(istream& is, string& str);
int new_fclose(FILE *stream);

void new_assert(int expression);


void new_exit(int status) {
  return exit(status);
}
istream& new_getline(istream& is, string& str) {
  return getline(is, str);
}
int new_fclose(FILE *stream);

void new_assert(int expression) {
  return assert(expression);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}