#include <stdio.h>
int a[2000000][8], base[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000}, i, j, k, l, s, tn, ti, x, y;
long long res;
int main()
{
	for (i = 2; i <= 7; ++i) {
		for (j = base[i - 1]; j < 2000000 && j < base[i]; ++j) {
			a[j][0] = 0;
			for (k = 1, s = j; k < i; ++k) {
				s = s / 10 + base[i - 1] * (s % 10);
				if (s >= base[i - 1] && s != j) {
					for (l = 1; l <= a[j][0] && a[j][l] != s; ++l);
					if (l > a[j][0])
						a[j][++a[j][0]] = s;
				}
			}

		}
	}
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		scanf("%d%d", &x, &y);
		for (i = x, res = 0; i <= y; ++i)
			for (j = 1; j <= a[i][0]; ++j)
				if (a[i][j] >= x && a[i][j] <= y)
					++res;
		printf("Case #%d: %lld\n", ti, res / 2);
	}
	return 0;
}
