#include <config.h>
#include "fwriteerror.h"
#include <errno.h>
#include <stdbool.h>


FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream);

int new_fclose(FILE *stream) {
  return fclose(stream);
}