#include <stdio.h>
#include <stdlib.h>
struct node {
    long long cnt;
    long long dis;
} d[1000 + 1];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int node_cmp(const void *a, const void *b)
{
    int first_iteration;
    const struct node *na = (const struct node *) a;
    const struct node *nb = (const struct node *) b;
    long long tmp = nb->dis - na->dis;
    return tmp == 0 ? 0 : tmp > 0 ? 1 : -1;
}

int L;
int N;
int C;
long long T;
int main()
{
    int first_iteration;
    int Tcases;
    scanf("%d", &Tcases);
    int cases;
    for (cases = 0; cases < Tcases; cases++) {
	scanf("%d %lld %d %d", &L, &T, &N, &C);
	long long sum = 0;
	int i;
	for (i = 0; i < C; i++) {
	    scanf("%lld", &d[i].dis);
	    d[i].dis <<= 1;
	    sum += d[i].dis;
	}
	long long time = (N / C) * sum;
	long long l = (N / C) - (T / sum);
	int neg = 0;
	for (i = 0; i < C; i++) {
	    d[i].cnt = l;
	}
	long long nl = N % C;
	long long tl = T % sum;
	long long lasti = -1;
	for (i = 0; i < C; i++) {
	    if (nl) {
		time += d[i].dis;
		++d[i].cnt;
		--nl;
	    }
	    if (tl > 0) {
		--d[i].cnt;
		tl -= d[i].dis;
		lasti = i;
	    }
	    neg += d[i].cnt < 0;
	}
	if (!neg) {
	    if (lasti != (-1)) {
		d[C].dis = -tl;
		d[C].cnt = 1;
		++C;
	    }
	    new_qsort(d, C, sizeof(struct node), node_cmp);
	    long long ll = L;
	    for (i = 0; i < C; i++) {
		long long build = ll < d[i].cnt ? ll : d[i].cnt;
		d[i].cnt -= build;
		ll -= build;
		time -= (d[i].dis * build) >> 1;
	    }
	}
	printf("Case #%d: %lld\n", cases + 1, time);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
