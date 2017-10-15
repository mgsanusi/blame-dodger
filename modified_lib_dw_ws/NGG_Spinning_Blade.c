#include <stdio.h>
#include <stdlib.h>
typedef struct  {
	int w;
	int l;
} path_t;
path_t paths[1010];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int cmp(const void *a, const void *b)
{
	int first_iteration;
	return (*((int *)a)) - (*((int *)b));
}

int main(void)
{
	int first_iteration;
	int t;
	int ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int x;
		int s;
		int r;
		int n;
		int i;
		int j;
		double t;
		double ret = 0;
		scanf("%d %d %d %lf %d", &x, &s, &r, &t, &n);
		j = x;
		r -= s;
		for (i = 0; i < n; i++) {
			int a;
			int b;
			int w;
			scanf("%d %d %d", &a, &b, &w);
			paths[i].w = w + s;
			paths[i].l = b - a;
			x -= paths[i].l;
		}
		paths[n].l = x;
		paths[n].w = s;
		new_qsort(paths, n + 1, 2 * (sizeof(int)), cmp);
		for (i = 0; i <= n; i++) {
			double runtime =
			    ((double)paths[i].l) / (paths[i].w + r);
			if (runtime <= t) {
				t -= runtime;
				ret += runtime;
			} else {
				double l =
				    ((double)paths[i].l) -
				    ((paths[i].w + r) * t);
				ret += t;
				ret += l / paths[i].w;
				t = 0;
			}
		}
		printf("Case #%d: %.8lf\n", ti, ret);
	}
	return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	int first_iteration;
	return qsort(base, num, size, compar);
}
