#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long merge(long long x[], long long alen, long long y[], long long blen,
		long long des[])
{
	long long s;
	long long eaten2 = 0;
	long long c = 0;
	for (s = 0; s < alen; s++) {
		for (; eaten2 < blen; eaten2++) {
			if (y[eaten2] >= x[s])
				break;
			des[c++] = y[eaten2];
		}
		des[c++] = x[s];
	}
	for (; eaten2 < blen; eaten2++)
		des[c++] = y[eaten2];
	return c;
}

void mergepart(long long x[], long long length, long long t[])
{
	if (length == 1)
		return;
	mergepart(t, length / 2, x);
	mergepart(t + (length / 2), (length + 1) / 2, x + (length / 2));
	merge(t, length / 2, t + (length / 2), (length + 1) / 2, x);
}

void mergesort(long long x[], long long length)
{
	long long *t;
	t = (long long *)malloc(length * (sizeof(long long)));
	memcpy(t, x, length * (sizeof(long long)));
	mergepart(x, length, t);
	free(t);
}

long long f[1100000];
int ptr[1100000];
int cmp(const int *x, const int *y)
{
	if ((f[*x] - f[*y]) > 0)
		return 1;
	if ((f[*x] - f[*y]) < 0)
		return -1;
	return 0;
}

int Main()
{
	int xor;
	int x[501];
	int tc;
	int j;
	int m;
	int y;
	int t;
	int testc;
	int testi;
	freopen("gcj2_3.in", "r", stdin);
	freopen("gcj2_3.out", "w", stdout);
	scanf("%d", &testc);
	for (testi = 1; testi <= testc; testi++) {
		scanf("%d", &xor);
		for (tc = 0; tc < xor; tc++)
			scanf("%d", x + tc);
		f[0] = 0;
		t = 1;
		for (tc = 0; tc < xor; tc++) {
			for (j = 0; j < t; j++)
				f[j | t] = f[j] + x[tc];
			t = t << 1;
		}
		for (tc = 0; tc < t; tc++) {
			ptr[tc] = tc;
		}
		qsort(ptr, t, sizeof(int), cmp);
		for (tc = 1; tc < t; tc++) {
			if (f[ptr[tc]] == f[ptr[tc - 1]])
				break;
		}
		printf("Case #%d:\n", testi);
		if (tc == t)
			printf("Impossible");
		else {
			y = ptr[tc - 1];
			m = 0;
			for (j = 0; y; j++, y /= 2) {
				if ((y % 2) == 0)
					continue;
				if (!m)
					m++;
				else
					printf(" ");
				printf("%d", x[j]);
			}
			printf("\n");
			y = ptr[tc];
			m = 0;
			for (j = 0; y; j++, y /= 2) {
				if ((y % 2) == 0)
					continue;
				if (!m)
					m++;
				else
					printf(" ");
				printf("%d", x[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
