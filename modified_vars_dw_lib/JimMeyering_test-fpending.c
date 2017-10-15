#include <config.h>
#include "fpending.h"
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
void new_exit(int status);



void new_exit(int status) {
  return exit(status);
}