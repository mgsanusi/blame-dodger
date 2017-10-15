#include <stdio.h>
int result();
int n;
char map[200][200];
int sqr(int k)
{
	return k * k;
}

int Main()
{
	int t;
	int p;
	int tcase;
	int k;
	scanf("%d\n", &t);
	for (p = 1; p <= t; ++p) {
		scanf("%d", &n);
		gets(map[0]);
		for (tcase = 1; tcase < (2 * n); ++tcase)
			gets(map[tcase]);
		printf("Case #%d: %d\n", p, sqr(result()) - sqr(n));
	}
}

inline int abs(int l)
{
	return l > 0 ? l : -l;
}

inline int different(int a, int b, int p)
{
	if ((a <= 0) || (a >= (2 * n)))
		return 0;
	if ((a <= n) && ((b < (n - a)) || (b >= ((n + a) - 1))))
		return 0;
	if ((a > n) && ((b < (a - n)) || (b >= (((3 * n) - a) - 1))))
		return 0;
	return map[a][b] != p;
}

int check(int l, int r, int *q)
{
	int node;
	int tcase;
	int t;
	*q = 0;
	for (node = 1; node < (2 * n); ++node) {
		if (node <= n)
			for (tcase = n - node; tcase < ((n + node) - 1);
			     ++tcase) {
				t = abs(node - l) + abs(r - tcase);
				if (t > (*q))
					*q = t;
				if (different
				    ((2 * l) - node, tcase, map[node][tcase]))
					return 0;
				if (different
				    (node, (2 * r) - tcase, map[node][tcase]))
					return 0;
				if (different
				    ((2 * l) - node, (2 * r) - tcase,
				     map[node][tcase]))
					return 0;
		} else
			for (tcase = node - n; tcase < (((3 * n) - node) - 1);
			     ++tcase) {
				t = abs(node - l) + abs(r - tcase);
				if (t > (*q))
					*q = t;
				if (different
				    ((2 * l) - node, tcase, map[node][tcase]))
					return 0;
				if (different
				    (node, (2 * r) - tcase, map[node][tcase]))
					return 0;
				if (different
				    ((2 * l) - node, (2 * r) - tcase,
				     map[node][tcase]))
					return 0;
			}
	}
	(*q)++;
	return 1;
}

int result()
{
	int node;
	int tcase;
	int k;
	int min;
	min = (3 * n) - 2;
	for (node = 1; node < (2 * n); ++node)
		for (tcase = 0; tcase < ((2 * n) - 1); ++tcase)
			if (check(node, tcase, &k) && (k < min))
				min = k;
	return min;
}
