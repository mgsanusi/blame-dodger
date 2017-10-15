#include "test/core/statistics/census_log_tests.h"
#include <stdlib.h>
#include <grpc/support/time.h>
#include "test/core/util/test_config.h"
void new_srand (unsigned int seed);
void
new_srand (unsigned int seed)
{
  return srand (seed);
}
