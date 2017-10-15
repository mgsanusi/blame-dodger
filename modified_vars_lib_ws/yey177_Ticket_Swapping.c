#include <stdio.h>
#include <stdlib.h>
typedef struct pair  {
	long long y;
	long long p;
} PAIR;
PAIR p[2008];
int stack[2008];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int comp(const void *k, const void *x)
{
	PAIR *p = (PAIR *) k;
	PAIR *q = (PAIR *) x;
	if (p->y > q->y)
		return 1;
	if (p->y < q->y)
		return -1;
	return 0;
}

int Main()
{
	int seanxor;
	int j;
	int x1;
	int deltaP;
	int outputFilePtr;
	int x;
	int t2;
	int in;
	int m;
	long long tmp;
	long long tmp2;
	long long tmp3;
	long long tmp4;
	long long o;
	long long e;
	long long pp;
	scanf("%d", &x);
	for (t2 = 1; t2 <= x; t2++) {
		tmp3 = (tmp4 = 0);
		x1 = 0;
		scanf("%d%d", &in, &m);
		for (seanxor = 0; seanxor < m; seanxor++) {
			scanf("%lld%lld%lld", &o, &e, &pp);
			tmp = e - o;
			tmp2 =
			    ((tmp * in) - ((tmp * (tmp - 1)) / 2)) % 1000002013;
			tmp3 = (tmp3 + (tmp2 * pp)) % 1000002013;
			outputFilePtr = 0;
			for (j = 0; j < x1; j++) {
				if (p[j].y == o) {
					p[j].p += pp;
					outputFilePtr = 1;
					break;
				}
			}
			if (!outputFilePtr) {
				p[x1].y = o;
				p[x1++].p = pp;
			}
			outputFilePtr = 0;
			for (j = 0; j < x1; j++) {
				if (p[j].y == e) {
					p[j].p -= pp;
					outputFilePtr = 1;
					break;
				}
			}
			if (!outputFilePtr) {
				p[x1].y = e;
				p[x1++].p = -pp;
			}
		}
		new_qsort(p, x1, sizeof(PAIR), comp);
		deltaP = 0;
		for (seanxor = 0; seanxor < x1; seanxor++) {
			if (p[seanxor].p == 0)
				continue;
			if (p[seanxor].p > 0) {
				stack[deltaP++] = seanxor;
			} else {
				outputFilePtr = 1;
				while ((p[stack[deltaP - 1]].p +
					p[seanxor].p) <= 0) {
					deltaP--;
					p[seanxor].p += p[stack[deltaP]].p;
					tmp = p[seanxor].y - p[stack[deltaP]].y;
					tmp2 =
					    ((tmp * in) -
					     ((tmp * (tmp - 1)) / 2)) %
					    1000002013;
					tmp4 =
					    (tmp4 +
					     (tmp2 *
					      (p[stack[deltaP]].p %
					       1000002013))) % 1000002013;
					p[stack[deltaP]].p = 0;
					if (deltaP == 0) {
						outputFilePtr = 0;
						break;
					}
				}
				if (outputFilePtr) {
					tmp =
					    p[seanxor].y -
					    p[stack[deltaP - 1]].y;
					tmp2 =
					    ((tmp * in) -
					     ((tmp * (tmp - 1)) / 2)) %
					    1000002013;
					tmp4 =
					    (tmp4 +
					     (tmp2 *
					      ((-p[seanxor].p) % 1000002013))) %
					    1000002013;
					p[stack[deltaP - 1]].p += p[seanxor].p;
				}
			}
		}
		printf("Case #%d: %lld\n", t2,
		       ((tmp3 + 1000002013) - tmp4) % 1000002013);
	}
	return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}
