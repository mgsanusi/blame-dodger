#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "linebuffer.h"
#include "xalloc.h"
int new_getc(FILE * stream);
int new_getc(FILE * stream)
{
    return getc(stream);
}
