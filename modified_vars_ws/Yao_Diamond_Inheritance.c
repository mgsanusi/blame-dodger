#include<stdio.h>
int a[10000][2];
int dp[10000];
int n;
int aa;
int Main()
{
	int max;
	int cs = 0;
	int need_v;
	int what;
	int b;
	for (scanf("%d", &max); max--;) {
		scanf("%d", &n);
		for (need_v = 0; need_v < n; need_v++)
			scanf("%d %d", &a[need_v][0], &a[need_v][1]),
			    dp[need_v] = -1;
		scanf("%d", &aa);
		dp[0] = a[0][0];
		int xdrs = 0;
		for (need_v = 0; (need_v < n) && (!xdrs); need_v++)
			if (dp[need_v] >= 0) {
				if ((a[need_v][0] + dp[need_v]) >= aa)
					xdrs = 1;
				for (what = need_v + 1;
				     (what < n)
				     && (a[what][0] <=
					 (a[need_v][0] + dp[need_v])); what++) {
					if ((a[what][0] - a[need_v][0]) <=
					    a[what][1])
						b = a[what][0] - a[need_v][0];
					else
						b = a[what][1];
					if (b > dp[what])
						dp[what] = b;
				}
			}
		if (xdrs)
			printf("Case #%d: YES\n", ++cs);
		else
			printf("Case #%d: NO\n", ++cs);
	}
	return 0;
}
