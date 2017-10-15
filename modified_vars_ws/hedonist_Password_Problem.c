#include <stdio.h>
int maxn = 300;
int qsort(int a[], double s[], int dp, int c)
{
	int mida;
	int ok;
	int j;
	double midb;
	if (dp < c) {
		ok = dp;
		j = c;
		mida = a[ok];
		midb = s[ok];
		while (ok < j) {
			while ((ok < j) && (s[j] > midb))
				j--;
			a[ok] = a[j];
			s[ok] = s[j];
			if (ok < j)
				ok++;
			while ((ok < j) && (s[ok] < midb))
				ok++;
			a[j] = a[ok];
			s[j] = s[ok];
			if (ok < j)
				j--;
		}
		a[ok] = mida;
		s[ok] = midb;
		qsort(a, s, dp, ok - 1);
		qsort(a, s, ok + 1, c);
	}
	return 0;
}

int Main()
{
	int t;
	int ok;
	int j;
	int dy;
	int j1;
	double s;
	double s1;
	double a[maxn];
	int s[maxn];
	double answer[maxn];
	double c;
	scanf("%d", &t);
	for (ok = 0; ok < t; ok++) {
		s = 0;
		scanf("%d", &dy);
		for (j = 0; j < dy; j++) {
			scanf("%lf", &a[j]);
			s = s + a[j];
			s[j] = j;
		}
		qsort(s, a, 0, dy - 1);
		for (j = 0; j < dy; j++) {
			answer[s[j]] = 0;
			s1 = 0;
			for (j1 = 0; j1 < j; j1++)
				s1 = s1 + a[j1];
			for (j1 = j; j1 < dy; j1++) {
				s1 = s1 + a[j1];
				if (j1 == 0)
					continue;
				c = (((s + s1) / (j1 + 1)) - a[j]) / s;
				if ((a[j] + (c * s)) < a[j1])
					continue;
				if ((j1 < (dy - 1))
				    && ((a[j] + (c * s)) > a[j1 + 1]))
					continue;
				if (c > answer[s[j]])
					answer[s[j]] = c * 100;
			}
		}
		printf("Case #%d:", ok + 1);
		for (j = 0; j < dy; j++)
			printf(" %.5lf", answer[j]);
		printf("\n");
	}
	return 0;
}
