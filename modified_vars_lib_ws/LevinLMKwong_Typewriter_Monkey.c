#include<stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int check(int n, int *tmp, int len)
{
	int ii;
	for (ii = len - 1; ii >= 0; ii--) {
		if (tmp[ii] <= n) {
			n -= tmp[ii];
		}
	}
	if (n == 0)
		return 1;
	else
		return 0;
}

int Main()
{
	new_freopen("C.in", "r", stdin);
	new_freopen("C.out", "w", stdout);
	int t;
	int c;
	int d;
	int v;
	int ii;
	int j;
	int y;
	int end;
	int tmp[30];
	int f[30];
	int a;
	int temp;
	scanf("%d", &t);
	for (end = 1; end <= t; end++) {
		scanf("%d %d %d", &c, &d, &v);
		for (ii = 0; ii < d; ii++) {
			scanf("%d", &tmp[ii]);
		}
		a = 0;
		for (ii = 1; ii <= v; ii++) {
			if (!check(ii, tmp, d + a)) {
				a++;
				tmp[(d + a) - 1] = ii;
				for (j = 0; j < (d + a); j++) {
					for (y = j; y < (d + a); y++) {
						if (tmp[j] > tmp[y]) {
							temp = tmp[j];
							tmp[j] = tmp[y];
							tmp[y] = temp;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", end, a);
	}
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
