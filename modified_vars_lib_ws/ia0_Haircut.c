#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void *new_malloc(size_t size);
void new_assert(int expression);
int Main(void)
{
    int t;
    new_assert(scanf("%d", &t) == 1);
    for (int b = 1; b <= t; b++) {
	int cake;
	int *n;
	int outlets = 0;
	int y = 0;
	int ret = 0;
	new_assert(scanf("%d", &cake) == 1);
	n = new_malloc(((size_t) cake) * (sizeof(*n)));
	for (int i = 0; i < cake; i++) {
	    new_assert(scanf("%d", &n[i]) == 1);
	    if (i > 0) {
		int k = n[i - 1] - n[i];
		if (k > outlets)
		    outlets = k;
		if (k > 0)
		    y += k;
	    }
	}
	for (int i = 0; i < (cake - 1); i++)
	    ret += n[i] < outlets ? n[i] : outlets;
	printf("Case #%d: %d %d\n", b, y, ret);
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
