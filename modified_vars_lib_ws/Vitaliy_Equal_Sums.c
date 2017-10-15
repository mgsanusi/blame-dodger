#include <stdio.h>
#include <assert.h>
int a[10001];
int right[10001];
int val[10001];
int b[10001];
void new_assert(int expression);
int Main()
{
	int c;
	scanf("%d", &c);
	int eq;
	for (eq = 0; eq < c; eq++) {
		printf("Case #%d:", eq + 1);
		int n;
		int ok;
		int what;
		scanf("%d", &n);
		for (ok = 0; ok < n; ok++) {
			scanf("%d%d", &right[ok], &val[ok]);
		}
		val[n] = 0;
		scanf("%d", &right[n]);
		for (ok = 1; ok <= n; ok++) {
			new_assert(right[ok] >= right[ok - 1]);
		}
		b[0] = right[0];
		for (ok = 1; ok <= n; ok++) {
			b[ok] = -1;
		}
		for (ok = 1; ok <= n; ok++) {
			int full = -1;
			for (what = ok - 1; what >= 0; what--) {
				int t = b[what] - (right[ok] - right[what]);
				int r;
				if (t >= 0) {
					if (val[ok] <=
					    (right[ok] - right[what])) {
						r = val[ok];
					} else {
						r = right[ok] - right[what];
					}
					if (full < r) {
						full = r;
					}
				}
			}
			b[ok] = full;
		}
		if (b[n] >= 0)
			printf(" YES");
		else
			printf(" NO");
		printf("\n");
	}
	return 0;
}

void new_assert(int expression)
{
	return assert(expression);
}
