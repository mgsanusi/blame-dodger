#include <config.h>

#include <stddef.h>
#include "save-cwd.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "chdir-long.h"
#include "unistd--.h"
#include "cloexec.h"
void* new_malloc(int size);



void* new_malloc(int size) {
  return malloc(size);
}