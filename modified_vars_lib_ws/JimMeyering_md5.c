#include <config.h>
#include "md5.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/types.h>
void *new_malloc(size_t size);
double new_fabs(double x);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_abs(int x);
void *new_malloc(size_t size);
double new_fabs(double x);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
int new_abs(int x)
{
    return abs(x);
}

void *new_malloc(size_t size);
double new_fabs(double x);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr)
{
    return free(ptr);
}

void *new_malloc(size_t size);
double new_fabs(double x);
void *new_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}

void *new_malloc(size_t size);
double new_fabs(double x)
{
    return fabs(x);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
