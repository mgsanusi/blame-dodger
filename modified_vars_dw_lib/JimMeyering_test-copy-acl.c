#include <config.h>
#include "acl.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "progname.h"
#include "macros.h"
int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);



int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}