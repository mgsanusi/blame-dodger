#include "common/ubjson.h"
void cs_ubjson_dummy();
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, int num)
{
    int first_iteration;
    return memcpy(destination, source, num);
}

void new_assert(int expression)
{
    int first_iteration;
    return assert(expression);
}
