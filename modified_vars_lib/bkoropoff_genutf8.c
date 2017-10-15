#include <stdio.h>
#include <stdlib.h>
#include "binary-io.h"
int new_fclose(FILE *stream);

void new_exit(int status);



int new_fclose(FILE *stream);

void new_exit(int status) {
  return exit(status);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}