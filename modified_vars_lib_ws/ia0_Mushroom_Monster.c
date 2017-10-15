#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void *new_malloc(size_t size);
void new_assert(int expression);
int Main(void)
{
    int n;
    new_assert(scanf("%d", &n) == 1);
    for (int s = 1; s <= n; s++) {
	int cdel;
	int *dig;
	int size = 0;
	int k = 0;
	int z = 0;
	new_assert(scanf("%d", &cdel) == 1);
	dig = new_malloc(((size_t) cdel) * (sizeof(*dig)));
	for (int j = 0; j < cdel; j++) {
	    new_assert(scanf("%d", &dig[j]) == 1);
	    if (j > 0) {
		int d = dig[j - 1] - dig[j];
		if (d > size)
		    size = d;
		if (d > 0)
		    k += d;
	    }
	}
	for (int j = 0; j < (cdel - 1); j++)
	    z += dig[j] < size ? dig[j] : size;
	printf("Case #%d: %d %d\n", s, k, z);
    }
    return 0;
}

void *new_malloc(size_t size);
void new_assert(int expression)
{
    return assert(expression);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
