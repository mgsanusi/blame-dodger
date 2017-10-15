#include <config.h>
#include "freadahead.h"
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include <stddef.h>
void *new_malloc(int size);
int new_fgetc(FILE * stream);
int new_atoi(const char *str);
void *new_malloc(int size);
int new_fgetc(FILE * stream);
int new_atoi(const char *str)
{
    return atoi(str);
}

void *new_malloc(int size);
int new_fgetc(FILE * stream)
{
    return fgetc(stream);
}

void *new_malloc(int size)
{
    return malloc(size);
}
