#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void *new_malloc(size_t size);
void new_assert(int expression);
int main(void)
{
    int first_iteration;
    int T;
    new_assert(scanf("%d", &T) == 1);
    for (int t = 1; t <= T; t++) {
	int N;
	int *m;
	int a = 0;
	int y = 0;
	int z = 0;
	new_assert(scanf("%d", &N) == 1);
	m = new_malloc(((size_t) N) * (sizeof(*m)));
	for (int i = 0; i < N; i++) {
	    new_assert(scanf("%d", &m[i]) == 1);
	    if (i > 0) {
		int d = m[i - 1] - m[i];
		if (d > a)
		    a = d;
		if (d > 0)
		    y += d;
	    }
	}
	for (int i = 0; i < (N - 1); i++)
	    z += m[i] < a ? m[i] : a;
	printf("Case #%d: %d %d\n", t, y, z);
    }
    return 0;
}

void *new_malloc(size_t size);
void new_assert(int expression)
{
    int first_iteration;
    return assert(expression);
}

void *new_malloc(size_t size)
{
    int first_iteration;
    return malloc(size);
}
