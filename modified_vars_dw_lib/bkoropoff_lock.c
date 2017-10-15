#include "portable.h"
#include <stdio.h>

#include <stddef.h>
#include <ac/string.h>
#include <ac/socket.h>
#include <ac/time.h>
#include <ac/unistd.h>
#include <sys/file.h>
#include "slap.h"
#include <lutil.h>


FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream);

int new_fclose(FILE *stream) {
  return fclose(stream);
}