#include <config.h>
#include "fwritable.h"
#include <stdio.h>
#include "macros.h"
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fgetc(FILE * stream);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fgetc(FILE * stream)
{
    return fgetc(stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
