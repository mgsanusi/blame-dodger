#include <stdio.h>
#include <string.h>
#include "cystring.h"
#include "cysort.h"
FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
