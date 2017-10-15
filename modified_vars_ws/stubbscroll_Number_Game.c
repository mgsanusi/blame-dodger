#include <stdio.h>
#include <string.h>
int dp[128][256];
int a[128];
int x;
int rim;
int y;
int bn;
int clear()
{
    int n;
    int no;
    int v;
    int x;
    int need;
    int res;
    int dist;
    memset(dp, 63, sizeof(dp));
    for (n = 0; n < 256; n++)
	dp[0][n] = (a[0] - n) < 0 ? -(a[0] - n) : a[0] - n;
    for (n = 1; n < bn; n++) {
	for (no = 0; no < 256; no++) {
	    v = dp[n - 1][no];
	    dp[n][no] = dp[n][no] < (v + x) ? dp[n][no] : v + x;
	    for (x = 0; x < 256; x++) {
		dist = (no - x) < 0 ? -(no - x) : no - x;
		if (y > 0)
		    need = (dist - 1) / y;
		else {
		    if (((no - x) < 0 ? -(no - x) : no - x) <= y)
			dp[n][x] =
			    dp[n][x] <
			    (v +
			     ((a[n] - x) <
			      0 ? -(a[n] - x) : a[n] - x)) ? dp[n][x] : v +
			    ((a[n] - x) < 0 ? -(a[n] - x) : a[n] - x);
		    continue;
		}
		if (need < 0)
		    need = 0;
		dp[n][x] =
		    dp[n][x] <
		    ((v + (need * rim)) +
		     ((a[n] - x) <
		      0 ? -(a[n] - x) : a[n] - x)) ? dp[n][x] : (v +
								 (need *
								  rim)) +
		    ((a[n] - x) < 0 ? -(a[n] - x) : a[n] - x);
	    }
	}
    }
    res = 1000000000;
    for (n = 0; n < 256; n++)
	res = res < dp[bn - 1][n] ? res : dp[bn - 1][n];
    return res;
}

int Main()
{
    int cases;
    int caseno = 1;
    int n;
    scanf("%d", &cases);
    while (cases--) {
	scanf("%d %d %d %d", &x, &rim, &y, &bn);
	for (n = 0; n < bn; n++)
	    scanf("%d", &a[n]);
	printf("Case #%d: %d\n", caseno++, clear());
    }
    return 0;
}
