#include <string.h>
#include <stddef.h>
#include "net/mac/frame802154e-ie.h"
#include "net/net-debug.h"
void *new_memcpy(void *destination, const void *source, int num);
void *new_memcpy(void *destination, const void *source, int num)
{
    return memcpy(destination, source, num);
}
