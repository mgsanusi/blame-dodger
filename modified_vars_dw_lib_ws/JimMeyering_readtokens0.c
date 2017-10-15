#include <config.h>
#include <stdlib.h>
#include "readtokens0.h"
int new_fgetc(FILE * stream);
int new_fgetc(FILE * stream)
{
    return fgetc(stream);
}
