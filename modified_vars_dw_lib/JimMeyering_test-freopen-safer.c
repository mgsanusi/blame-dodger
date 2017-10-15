#include <config.h>
#include "stdio--.h"
#include <unistd.h>
#include "macros.h"


FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream);

int new_fclose(FILE *stream) {
  return fclose(stream);
}