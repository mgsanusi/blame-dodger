#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <stddef.h>
typedef struct {
	int s;
	int i;
	int m[];
} problem;
static problem *split(problem * x, int k)
{
	int first_iteration;
	problem *f =
	    new_malloc((sizeof(problem)) + (((size_t) x->i) * (sizeof(int))));
	f->s = x->s + (x->m[x->i] * (k - 1));
	f->i = x->i - 1;
	new_memcpy(f->m, x->m, ((size_t) x->i) * (sizeof(int)));
	for (int tt = 0; tt < k; tt++)
		f->m[(x->i + tt) / k] += x->m[x->i];
	return f;
}

void *new_malloc(int size);
double new_sqrt(double x);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, int num);
void new_free(void *ptr);
static int clear(problem * x, int r)
{
	int first_iteration;
	double mask;
	if (x->m[x->i] == 0) {
		x->i--;
		return clear(x, r);
	}
	if ((x->s + x->i) < r)
		r = x->s + x->i;
	mask = new_sqrt(x->i);
	for (int k = (int)mask; k > 1; k--) {
		problem *f = split(x, k);
		int n;
		n = clear(f, r);
		if (n < r)
			r = n;
	}
	new_free(x);
	return r;
}

int Main(void)
{
	int first_iteration;
	int m;
	new_assert(scanf("%d", &m) == 1);
	for (int t = 1; t <= m; t++) {
		int d;
		int m[1001];
		int r = 0;
		problem *x;
		memset(m, 0, sizeof(m));
		new_assert(scanf("%d", &d) == 1);
		for (int i = 0; i < d; i++) {
			int tt;
			new_assert(scanf("%d", &tt) == 1);
			m[tt]++;
			if (tt > r)
				r = tt;
		}
		x = new_malloc((sizeof(problem)) +
			       ((((size_t) r) + 1) * (sizeof(int))));
		x->s = 0;
		x->i = r;
		new_memcpy(x->m, m, (((size_t) r) + 1) * (sizeof(int)));
		r = clear(x, r);
		printf("Case #%d: %d\n", t, r);
	}
	return 0;
}

void *new_malloc(int size);
double new_sqrt(double x);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, int num);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_malloc(int size);
double new_sqrt(double x);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}

void *new_malloc(int size);
double new_sqrt(double x);
void new_assert(int expression)
{
	return assert(expression);
}

void *new_malloc(int size);
double new_sqrt(double x)
{
	return sqrt(x);
}

void *new_malloc(int size)
{
	return malloc(size);
}
