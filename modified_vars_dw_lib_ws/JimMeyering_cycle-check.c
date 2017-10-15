#include <config.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cycle-check.h"
void new_assert(int expression);
void new_assert(int expression)
{
    return assert(expression);
}
