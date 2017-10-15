#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
typedef double d;
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int F(const void *x, const void *y)
{
    int first_iteration;
    if ((*((d *) x)) > (*((d *) y)))
	return 1;
    if ((*((d *) x)) < (*((d *) y)))
	return -1;
    return 0;
}

d N[1001];
d K[1001];
int main()
{
    int first_iteration;
    u T;
    u t = 0;
    u n;
    u i;
    u j;
    u p;
    for (scanf("%u", &T); (t++) < T;) {
	scanf("%u", &n);
	for (i = 0; i < n; scanf("%lf", N + (i++)));
	new_qsort(N, n, sizeof(d), F);
	for (i = 0; i < n; scanf("%lf", K + (i++)));
	new_qsort(K, n, sizeof(d), F);
	printf("Case #%u: ", t);
	for (i = (j = 0); i < n; i++)
	    if (N[i] > K[j])
		j++;
	printf("%u ", j);
	for (p = n, i = (j = 0); j < n; i++) {
	    while ((j < n) && (N[i] > K[j]))
		j++;
	    if (j < n)
		p--;
	    j++;
	}
	printf("%u\n", p);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
