#include "src/core/ext/census/resource.h"
#include <grpc/census.h>
#include <grpc/support/log.h>
#include <grpc/support/port_platform.h>
#include <grpc/support/useful.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/core/ext/census/base_resources.h"
#include "test/core/util/test_config.h"


FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream);

int new_fclose(FILE *stream) {
  return fclose(stream);
}