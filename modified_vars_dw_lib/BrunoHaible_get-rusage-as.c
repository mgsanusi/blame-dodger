#include <config.h>

#include <stddef.h>
#include "resource-ext.h"
#include <errno.h> /* errno */
#include <stdlib.h> /* size_t, abort */
#include <fcntl.h> /* open, O_RDONLY */
#include <unistd.h> /* getpagesize, read, close */
#include "vma-iter.h"
#include <stdio.h>
void* new_malloc(int size);



void* new_malloc(int size) {
  return malloc(size);
}