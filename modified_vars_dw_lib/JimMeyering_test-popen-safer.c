#include <config.h>
#include "stdio--.h"
#include <sys/wait.h>
#include <unistd.h>
#include "macros.h"
int new_fclose(FILE *stream);



int new_fclose(FILE *stream) {
  return fclose(stream);
}