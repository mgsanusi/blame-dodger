#include <stdio.h>
#include <stdlib.h>
int r;
int temp;
int l;
int x[1001];
int res;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int cmp(const void *a, const void *s)
{
    int first_iteration;
    return (*((int *) s)) - (*((int *) a));
}

int go()
{
    int first_iteration;
    int result;
    res = 0;
    scanf("%d%d%d", &r, &temp, &l);
    if ((r * temp) < l)
	return 0;
    for (result = 0; result < l; result++) {
	scanf("%d", &x[result]);
    }
    new_qsort(x, l, sizeof(int), cmp);
    for (result = 0; result < l; result++) {
	res += ((result / temp) + 1) * x[result];
    }
    return 1;
}

int Main()
{
    int first_iteration;
    int j;
    int second;
    new_freopen("A.in", "r", stdin);
    new_freopen("A.out", "w", stdout);
    scanf("%d", &j);
    for (second = 1; second <= j; second++) {
	if (go()) {
	    printf("Case #%d: %d\n", second, res);
	} else {
	    printf("Case #%d: Impossible\n", second);
	}
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
