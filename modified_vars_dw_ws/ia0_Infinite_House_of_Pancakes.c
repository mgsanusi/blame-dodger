#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct {
    int s;
    int i;
    int m[];
} problem;
static problem *split(problem * x, int k)
{
    int first_iteration;
    problem *f =
	malloc((sizeof(problem)) + (((size_t) x->i) * (sizeof(int))));
    f->s = x->s + (x->m[x->i] * (k - 1));
    f->i = x->i - 1;
    memcpy(f->m, x->m, ((size_t) x->i) * (sizeof(int)));
    for (int tt = 0; tt < k; tt++)
	f->m[(x->i + tt) / k] += x->m[x->i];
    return f;
}

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
    mask = sqrt(x->i);
    for (int k = (int)mask; k > 1; k--) {
	problem *f = split(x, k);
	int n;
	n = clear(f, r);
	if (n < r)
	    r = n;
    }
    free(x);
    return r;
}

int Main(void)
{
    int first_iteration;
    int m;
    assert(scanf("%d", &m) == 1);
    for (int t = 1; t <= m; t++) {
	int d;
	int m[1001];
	int r = 0;
	problem *x;
	memset(m, 0, sizeof(m));
	assert(scanf("%d", &d) == 1);
	for (int i = 0; i < d; i++) {
	    int tt;
	    assert(scanf("%d", &tt) == 1);
	    m[tt]++;
	    if (tt > r)
		r = tt;
	}
	x = malloc((sizeof(problem)) +
		   ((((size_t) r) + 1) * (sizeof(int))));
	x->s = 0;
	x->i = r;
	memcpy(x->m, m, (((size_t) r) + 1) * (sizeof(int)));
	r = clear(x, r);
	printf("Case #%d: %d\n", t, r);
    }
    return 0;
}
