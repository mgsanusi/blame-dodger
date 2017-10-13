#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXN 2000001
int a[MAXN + 1][10];

int main () {
	int _t, __t;
	int i;
	for (i = 1; i < MAXN; i++) {
		int total_deg = 1;
		while (total_deg <= i) {
			total_deg *= 10;
		}
		total_deg /= 10;
		int deg10 = 10;
		int prev10 = 1;
		int cc = 0;
		while (deg10 <= i) {
			int r = i % deg10;
			int l = i / deg10;
			if (r >= prev10) {
				assert (i < MAXN);
				assert (cc < 10);
				a[i][cc ++] = total_deg * r + l;
			}
			deg10 *= 10;
			prev10 *= 10;
			total_deg /= 10;
		}
		a[i][cc] = -1;
		int j, k;
		for (j = 0; j < cc; j++)
			for (k = j + 1; k < cc; k++) if (a[i][j] > a[i][k]) {
				int t = a[i][j]; a[i][j] = a[i][k]; a[i][k] = t;
			}
	}
	scanf ("%d\n", &_t);
	for (__t = 0; __t < _t; __t++) {
		printf ("Case #%d: ", __t + 1);
		int l, r;
		scanf ("%d%d", &l, &r);
		int res = 0;
		for (i = l; i <= r; i++) {
			int cc = 0;
			for (cc = 0; a[i][cc] != -1; cc ++) {
				if ((cc == 0 || a[i][cc] != a[i][cc - 1]) && a[i][cc] != i && a[i][cc] >= l && a[i][cc] <= r) {
					res ++;
				}
			}
		}
		assert (res % 2 == 0);
		printf ("%d\n", res / 2);
	}
	return 0;
}
