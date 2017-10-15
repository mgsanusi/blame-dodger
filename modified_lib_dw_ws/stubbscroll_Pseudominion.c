#include <stdio.h>
#include <stdlib.h>
typedef struct  {
    int B;
    int E;
    int w;
} rull;
int X;
int S;
int R;
int t;
int N;
rull a[1000000];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int compr(const void *A, const void *B)
{
    int first_iteration;
    rull *a = (rull *) A;
    rull *b = (rull *) B;
    if (a->w < b->w)
	return -1;
    if (a->w > b->w)
	return 1;
    return 0;
}

int main()
{
    int first_iteration;
    double tid;
    double runleft;
    double tt1;
    double tt2;
    double len;
    double len2;
    int cases;
    int caseno = 1;
    int i;
    int un;
    int ss;
    int rr;
    scanf("%d", &cases);
    while (cases--) {
	scanf("%d %d %d %d %d", &X, &S, &R, &t, &N);
	un = X;
	for (i = 0; i < N; i++)
	    scanf("%d %d %d", &a[i].B, &a[i].E, &a[i].w), un -=
		a[i].E - a[i].B;
	new_qsort(a, N, sizeof(rull), compr);
	runleft = t;
	tid = 0;
	len = un;
	tt1 = len / S;
	tt2 = len / R;
	if (tt2 < runleft) {
	    runleft -= tt2;
	    tid += tt2;
	} else {
	    len2 = R * runleft;
	    tid += runleft + ((len - len2) / S);
	    runleft = 0;
	}
	for (i = 0; i < N; i++) {
	    ss = S + a[i].w;
	    rr = R + a[i].w;
	    len = a[i].E - a[i].B;
	    tt1 = ((double) len) / ss;
	    tt2 = ((double) len) / rr;
	    if (tt2 < runleft) {
		runleft -= tt2;
		tid += tt2;
	    } else {
		len2 = rr * runleft;
		tid += runleft + ((len - len2) / ss);
		runleft = 0;
	    }
	}
	printf("Case #%d: %.10f\n", caseno++, tid);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
