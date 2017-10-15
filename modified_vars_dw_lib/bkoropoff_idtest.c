#include "portable.h"
#include <stdio.h>
#include <ac/stdlib.h>
#include <psap.h>
#include <quipu/attr.h>
void new_exit(int status);



void new_exit(int status) {
  return exit(status);
}