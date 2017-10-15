#include <config.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <inttypes.h>
int new_rand();
int new_rand()
{
    return rand();
}
