#include <config.h>
#include "freadseek.h"
#include <stdlib.h>
#include <unistd.h>
#include "freadahead.h"
#include "freadptr.h"
#include "stdio-impl.h"
int new_fgetc(FILE *stream);



int new_fgetc(FILE *stream) {
  return fgetc(stream);
}