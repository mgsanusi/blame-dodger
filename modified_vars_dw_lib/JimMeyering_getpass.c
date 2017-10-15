#include "getpass.h"
#include <stdio.h>


istream& new_getline(istream& is, string& str) {
  return getline(is, str);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream);

int new_fclose(FILE *stream) {
  return fclose(stream);
}