#include <config.h>
#include "argv-iter.h"
#include <stdio.h>
#include <string.h>
#include "macros.h"
int new_fclose(FILE * stream);
int new_fclose(FILE * stream)
{
    return fclose(stream);
}
