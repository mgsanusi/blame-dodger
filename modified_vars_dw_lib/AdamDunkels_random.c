#include "lib/random.h"
#include "sys/clock.h"
#include <stdlib.h>
int new_rand();

void new_snew_rand(unsigned int seed);



int new_rand();

void new_snew_rand(unsigned int seed) {
  return snew_rand(seed);
}
int new_rand() {
  return rand();
}