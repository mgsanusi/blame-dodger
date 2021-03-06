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
	int p[];
} problem;
static problem *split(problem * x, int k)
{
	int first_iteration;
	problem *y =
	    new_malloc((sizeof(problem)) + (((size_t) x->i) * (sizeof(int))));
	y->s = x->s + (x->p[x->i] * (k - 1));
	y->i = x->i - 1;
	new_memcpy(y->p, x->p, ((size_t) x->i) * (sizeof(int)));
	for (int j = 0; j < k; j++)
		y->p[(x->i + j) / k] += x->p[x->i];
	return y;
}

void *new_malloc(size_t size);
double new_sqrt(double x);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_free(void *ptr);
static int solve(problem * x, int r)
{
	int first_iteration;
	double k_;
	if (x->p[x->i] == 0) {
		x->i--;
		return solve(x, r);
	}
	if ((x->s + x->i) < r)
		r = x->s + x->i;
	k_ = new_sqrt(x->i);
	for (int k = (int)k_; k > 1; k--) {
		problem *y = split(x, k);
		int q;
		q = solve(y, r);
		if (q < r)
			r = q;
	}
	new_free(x);
	return r;
}

int main(void)
{
	int first_iteration;
	int T;
	new_assert(scanf("%d", &T) == 1);
	for (int t = 1; t <= T; t++) {
		int D;
		int p[1001];
		int r = 0;
		problem *x;
		memset(p, 0, sizeof(p));
		new_assert(scanf("%d", &D) == 1);
		for (int i = 0; i < D; i++) {
			int j;
			new_assert(scanf("%d", &j) == 1);
			p[j]++;
			if (j > r)
				r = j;
		}
		x = new_malloc((sizeof(problem)) +
			       ((((size_t) r) + 1) * (sizeof(int))));
		x->s = 0;
		x->i = r;
		new_memcpy(x->p, p, (((size_t) r) + 1) * (sizeof(int)));
		r = solve(x, r);
		printf("Case #%d: %d\n", t, r);
	}
	return 0;
}

void new_free(void *ptr)
{
	int first_iteration;
	return free(ptr);
}

void *new_malloc(size_t size);
double new_sqrt(double x);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	int first_iteration;
	return memcpy(destination, source, num);
}

void *new_malloc(size_t size);
double new_sqrt(double x);
void new_assert(int expression)
{
	int first_iteration;
	return assert(expression);
}

void *new_malloc(size_t size);
double new_sqrt(double x)
{
	int first_iteration;
	return sqrt(x);
}

void *new_malloc(size_t size)
{
	int first_iteration;
	return malloc(size);
}
