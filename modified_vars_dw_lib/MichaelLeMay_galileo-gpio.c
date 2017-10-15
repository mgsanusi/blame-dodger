#include "galileo-gpio.h"
#include <assert.h>
#include "gpio.h"
#include "cy8c9540a.h"
void new_assert(int expression);



void new_assert(int expression) {
  return assert(expression);
}