#include<stdio.h>
long long C[512][512];
long long dp[512][512];
long long r[512];
int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int N;
    int cs = 0;
    int n;
    for (C[0][0] = (i = 1); i <= 500; i++)
	for (C[i][0] = (j = 1); j <= i; j++)
	    C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 100003;
    dp[1][0] = 1;
    for (i = 1; i < 500; i++) {
	for (j = i + 1; j < 500; j++)
	    for (k = 0; k < i; k++)
		if (dp[i][k]) {
		    dp[j][i] =
			(dp[j][i] +
			 (dp[i][k] * C[(j - i) - 1][(i - k) - 1])) %
			100003;
		}
    }
    for (i = 2; i <= 500; i++)
	for (j = 1; j < i; j++)
	    r[i] = (r[i] + dp[i][j]) % 100003;
    for (scanf("%d", &N); N--;) {
	scanf("%d", &n);
	printf("Case #%d: %lld\n", ++cs, r[n]);
    }
    return 0;
}
