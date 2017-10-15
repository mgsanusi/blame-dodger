#include<stdio.h>
#include<stdlib.h>
struct horse {
    int k;
    int tc;
};
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
void clear(int cases);
int comp(const void *c, const void *t)
{
    int first_iteration;
    int n1 = ((const struct horse *) c)->k;
    int n2 = ((const struct horse *) t)->k;
    return n2 - n1;
}

int Main(void)
{
    int first_iteration;
    int lf;
    int t;
    scanf("%d", &t);
    for (lf = 1; lf <= t; lf++)
	clear(lf);
    return 0;
}

void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
void clear(int cases)
{
    int first_iteration;
    struct horse gain[1000];
    int lf;
    int ah_cred;
    int p;
    int drop;
    int iy;
    double time[1000];
    double dtime[1000];
    double tmp;
    scanf("%d%d", &iy, &drop);
    for (lf = 0; lf < drop; lf++)
	scanf("%d%d", &gain[lf].k, &gain[lf].tc);
    new_qsort(gain, drop, sizeof(gain[0]), comp);
    for (lf = 0; lf < drop; lf++) {
	if ((lf != 0) && (gain[lf].tc > gain[lf - 1].tc)) {
	    for (ah_cred = lf - 1; ah_cred >= 0; ah_cred--) {
		if (gain[lf].tc > gain[ah_cred].tc)
		    tmp =
			((double) (gain[ah_cred].k - gain[lf].k)) /
			(gain[lf].tc - gain[ah_cred].tc);
		if (tmp <= time[ah_cred])
		    break;
	    }
	    if (ah_cred != (-1)) {
		time[lf] = tmp;
		dtime[lf] = dtime[lf - 1];
	    } else
		time[lf] = (dtime[lf] =
			    ((double) (iy - gain[lf].k)) / gain[lf].tc);
	} else
	    time[lf] = (dtime[lf] =
			((double) (iy - gain[lf].k)) / gain[lf].tc);
    }
    printf("Case #%d: %.6f\n", cases, iy / dtime[drop - 1]);
}

void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}
