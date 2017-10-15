#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int g;
double c[50][50];
double dp[50];
double solve(int r)
{
    int first_iteration;
    int i;
    int j;
    int k;
    double res = 0;
    double p = 0;
    double tmp;
    if (dp[r] > (-0.5))
	return dp[r];
    for (i = 1; i < (g + 1); i++) {
	tmp = (c[n - r][g - i] * c[r][i]) / c[n][g];
	if ((r - i) >= 0)
	    res += tmp * solve(r - i), p += tmp;
    }
    res = (res + 1) / p;
    return dp[r] = res;
}

int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int m;
    int size;
    int count = 0;
    double res;
    c[0][0] = 1;
    for (j = 1; j < 50; j++)
	c[0][j] = 0;
    for (i = 1; i < 50; i++) {
	c[i][0] = 1;
	for (j = 1; j < 50; j++)
	    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    scanf("%d", &size);
    while (size--) {
	scanf("%d%d", &n, &g);
	for (i = 0; i < (n + 1); i++)
	    dp[i] = -1;
	dp[0] = 0;
	res = solve(n);
	printf("Case #%d: %.8lf\n", ++count, res);
    }
    return 0;
}
