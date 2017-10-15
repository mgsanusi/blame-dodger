#include "cs_frbuf.h"
#include <stdio.h>
#include <stdlib.h>
#include "cs_dbg.h"
#include "test_util.h"
#include <stddef.h>
#include <stddef.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_calloc(int num, int size);
void *new_malloc(int size);
void new_free(void *ptr);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_calloc(int num, int size);
void *new_malloc(int size);
void new_free(void *ptr)
{
    return free(ptr);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_calloc(int num, int size);
void *new_malloc(int size)
{
    return malloc(size);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_calloc(int num, int size)
{
    return calloc(num, size);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
