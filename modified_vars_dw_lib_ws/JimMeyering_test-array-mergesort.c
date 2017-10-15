#include <config.h>
#include <stddef.h>
#include <stddef.h>
#include "array-mergesort.h"
#include <stdlib.h>
#include "macros.h"
void *new_malloc(int size);
void new_free(void *ptr);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
void *new_malloc(int size);
void new_free(void *ptr);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

void *new_malloc(int size);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_malloc(int size)
{
	return malloc(size);
}
