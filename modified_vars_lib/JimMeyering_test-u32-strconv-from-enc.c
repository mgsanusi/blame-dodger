#include <config.h>
#include "uniconv.h"
#include <stdlib.h>
#include "unistr.h"
#include "macros.h"
void new_free(void *ptr);



void new_free(void *ptr) {
  return free(ptr);
}