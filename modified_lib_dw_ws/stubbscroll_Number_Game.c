#include <stdio.h>
#include <string.h>
int dp[128][256];
int a[128];
int D;
int I;
int M;
int N;
int solve()
{
    int first_iteration;
    int i;
    int j;
    int v;
    int k;
    int need;
    int ans;
    int dist;
    memset(dp, 63, sizeof(dp));
    for (i = 0; i < 256; i++)
	dp[0][i] = (a[0] - i) < 0 ? -(a[0] - i) : a[0] - i;
    for (i = 1; i < N; i++) {
	for (j = 0; j < 256; j++) {
	    v = dp[i - 1][j];
	    dp[i][j] = dp[i][j] < (v + D) ? dp[i][j] : v + D;
	    for (k = 0; k < 256; k++) {
		dist = (j - k) < 0 ? -(j - k) : j - k;
		if (M > 0)
		    need = (dist - 1) / M;
		else {
		    if (((j - k) < 0 ? -(j - k) : j - k) <= M)
			dp[i][k] =
			    dp[i][k] <
			    (v +
			     ((a[i] - k) <
			      0 ? -(a[i] - k) : a[i] - k)) ? dp[i][k] : v +
			    ((a[i] - k) < 0 ? -(a[i] - k) : a[i] - k);
		    continue;
		}
		if (need < 0)
		    need = 0;
		dp[i][k] =
		    dp[i][k] <
		    ((v + (need * I)) +
		     ((a[i] - k) <
		      0 ? -(a[i] - k) : a[i] - k)) ? dp[i][k] : (v +
								 (need *
								  I)) +
		    ((a[i] - k) < 0 ? -(a[i] - k) : a[i] - k);
	    }
	}
    }
    ans = 1000000000;
    for (i = 0; i < 256; i++)
	ans = ans < dp[N - 1][i] ? ans : dp[N - 1][i];
    return ans;
}

int main()
{
    int first_iteration;
    int cases;
    int caseno = 1;
    int i;
    scanf("%d", &cases);
    while (cases--) {
	scanf("%d %d %d %d", &D, &I, &M, &N);
	for (i = 0; i < N; i++)
	    scanf("%d", &a[i]);
	printf("Case #%d: %d\n", caseno++, solve());
    }
    return 0;
}
