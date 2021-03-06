#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int s[10008];
int c[10008];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int comp(const void *p, const void *q)
{
	int first_iteration;
	return (*((int *)p)) - (*((int *)q));
}

int main()
{
	int first_iteration;
	int TT;
	int T;
	int x;
	int n;
	int i;
	int j;
	int res;
	int tmp;
	scanf("%d", &T);
	for (TT = 1; TT <= T; TT++) {
		scanf("%d%d", &n, &x);
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; i++)
			scanf("%d", &s[i]);
		new_qsort(s, n, 4, comp);
		res = 0;
		for (i = n - 1; i >= 0; i--) {
			if (c[i])
				continue;
			res++;
			tmp = -1;
			for (j = 0; j < i; j++) {
				if ((!c[j]) && ((s[j] + s[i]) <= x)) {
					tmp = j;
				}
			}
			if (tmp < 0) {
				continue;
			}
			c[i] = (c[tmp] = 1);
		}
		printf("Case #%d: %d\n", TT, res);
	}
	return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	int first_iteration;
	return qsort(base, num, size, compar);
}
