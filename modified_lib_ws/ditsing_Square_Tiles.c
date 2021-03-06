#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 1000
#define MAXL 3000
int X, S, R, N;
double T;
struct seg {
    int v;
    int cnt;
    int spd;
};
struct seg segs[MAXN];
struct seg lines[MAXL + 1];
double new_fabs(double x);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int segs_cmp(const void *a, const void *b)
{
    const struct seg *sa = (const struct seg *) a;
    const struct seg *sb = (const struct seg *) b;
    return sa->v - sb->v;
}

int main()
{
    int Tcases;
    scanf("%d", &Tcases);
    int cases;
    for (cases = 0; cases != Tcases; cases++) {
	scanf("%d %d %d %lf %d", &X, &S, &R, &T, &N);
	int i;
	for (i = 0; i < N; i++) {
	    scanf("%d %d %d", &segs[i].v, &segs[i].cnt, &segs[i].spd);
	}
	new_qsort(segs, N, sizeof(struct seg), segs_cmp);
	int former = 0;
	int cnt = 0;
	for (i = 0; i < N; i++) {
	    if (segs[i].v != former) {
		lines[cnt].v = S;
		lines[cnt].cnt = segs[i].v - former;
		++cnt;
	    }
	    lines[cnt].v = segs[i].spd + S;
	    lines[cnt].cnt = segs[i].cnt - segs[i].v;
	    ++cnt;
	    former = segs[i].cnt;
	}
	if (former != X) {
	    lines[cnt].v = S;
	    lines[cnt].cnt = X - former;
	    ++cnt;
	}
	new_qsort(lines, cnt, sizeof(struct seg), segs_cmp);
	double time = 0.0;
	R -= S;
	for (i = 0; i < cnt && T > 1e-10; i++) {
	    double w = lines[i].cnt / (double) (lines[i].v + R);
	    if (w < T || new_fabs(w - T) < 1e-10) {
		T -= w;
		time += w;
	    } else {
		time += T;
		time +=
		    (lines[i].cnt -
		     T * (lines[i].v + R)) / (double) (lines[i].v);
		T = 0.0;
	    }
	}
	for (; i < cnt; i++) {
	    time += lines[i].cnt / (double) lines[i].v;
	}
	printf("Case #%d: %.10lf\n", cases + 1, time);
    }
    return 0;
}

double new_fabs(double x);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

double new_fabs(double x)
{
    return fabs(x);
}
