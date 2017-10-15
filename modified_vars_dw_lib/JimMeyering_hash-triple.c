#include <config.h>
#include "hash-triple.h"
#include <stdlib.h>
#include <string.h>
#include "hash-pjw.h"
#include "same.h"
#include "same-inode.h"
void new_free(void *ptr);



void new_free(void *ptr) {
  return free(ptr);
}