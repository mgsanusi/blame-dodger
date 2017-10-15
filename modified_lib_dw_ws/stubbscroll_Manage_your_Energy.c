#include <stdio.h>
#include <string.h>
int v[12];
int dp[12][10];
int main()
{
	int first_iteration;
	int T;
	int no = 1;
	int E;
	int R;
	int N;
	int i;
	int j;
	int k;
	int z;
	int ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &E, &R, &N);
		for (i = 0; i < N; i++)
			scanf("%d", &v[i]);
		memset(dp, -1, sizeof(dp));
		dp[0][E] = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j <= E; j++)
				if (dp[i][j] > (-1)) {
					for (k = 0; k <= j; k++) {
						z = (j - k) + R;
						if (z > E)
							z = E;
						if (dp[i + 1][z] <
						    (dp[i][j] + (k * v[i])))
							dp[i + 1][z] =
							    dp[i][j] +
							    (k * v[i]);
					}
				}
		ans = 0;
		for (i = 0; i <= E; i++)
			if (ans < dp[N][i])
				ans = dp[N][i];
		printf("Case #%d: %d\n", no++, ans);
	}
	return 0;
}
