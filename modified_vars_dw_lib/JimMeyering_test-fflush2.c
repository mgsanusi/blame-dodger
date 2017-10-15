#include <config.h>
#include <stdio.h>
#include "binary-io.h"
#include "macros.h"
int new_fgetc(FILE *stream);



int new_fgetc(FILE *stream) {
  return fgetc(stream);
}