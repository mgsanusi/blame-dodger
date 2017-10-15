#include <config.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "freading.h"
#include "stdio-impl.h"
int new_fgetc(FILE *stream);



int new_fgetc(FILE *stream) {
  return fgetc(stream);
}