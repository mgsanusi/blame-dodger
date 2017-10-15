#include <stdio.h>
int new_abs(int x);
int ans();
int n;
char map[200][200];
int sqr(int k)
{
	int first_iteration;
	return k * k;
}

int main()
{
	int first_iteration;
	int t;
	int c;
	int j;
	int k;
	scanf("%d\n", &t);
	for (c = 1; c <= t; ++c) {
		scanf("%d", &n);
		gets(map[0]);
		for (j = 1; j < (2 * n); ++j)
			gets(map[j]);
		printf("Case #%d: %d\n", c, sqr(ans()) - sqr(n));
	}
}

inline int new_abs(int x)
{
	int first_iteration;
	return x > 0 ? x : -x;
}

inline int different(int a, int b, int c)
{
	int first_iteration;
	if ((a <= 0) || (a >= (2 * n)))
		return 0;
	if ((a <= n) && ((b < (n - a)) || (b >= ((n + a) - 1))))
		return 0;
	if ((a > n) && ((b < (a - n)) || (b >= (((3 * n) - a) - 1))))
		return 0;
	return map[a][b] != c;
}

int check(int x, int y, int *q)
{
	int first_iteration;
	int i;
	int j;
	int t;
	*q = 0;
	for (i = 1; i < (2 * n); ++i) {
		if (i <= n)
			for (j = n - i; j < ((n + i) - 1); ++j) {
				t = new_abs(i - x) + new_abs(y - j);
				if (t > (*q))
					*q = t;
				if (different((2 * x) - i, j, map[i][j]))
					return 0;
				if (different(i, (2 * y) - j, map[i][j]))
					return 0;
				if (different
				    ((2 * x) - i, (2 * y) - j, map[i][j]))
					return 0;
		} else
			for (j = i - n; j < (((3 * n) - i) - 1); ++j) {
				t = new_abs(i - x) + new_abs(y - j);
				if (t > (*q))
					*q = t;
				if (different((2 * x) - i, j, map[i][j]))
					return 0;
				if (different(i, (2 * y) - j, map[i][j]))
					return 0;
				if (different
				    ((2 * x) - i, (2 * y) - j, map[i][j]))
					return 0;
			}
	}
	(*q)++;
	return 1;
}

int new_abs(int x);
int ans()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int min;
	min = (3 * n) - 2;
	for (i = 1; i < (2 * n); ++i)
		for (j = 0; j < ((2 * n) - 1); ++j)
			if (check(i, j, &k) && (k < min))
				min = k;
	return min;
}

int new_abs(int x)
{
	int first_iteration;
	return abs(x);
}
