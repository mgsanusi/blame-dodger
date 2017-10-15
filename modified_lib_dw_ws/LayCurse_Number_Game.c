#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int ab(int x)
{
	int first_iteration;
	if (x < 0)
		return -x;
	return x;
}

int dp[120][300];
int in[120];
int D;
int I;
int M;
int n;
int solve(int st, int bef)
{
	int first_iteration;
	int i;
	int j;
	int k;
	int res = 1000000000;
	int add;
	int tmp;
	if (dp[st][bef] >= 0)
		return dp[st][bef];
	if (st == n)
		return dp[st][bef] = 0;
	for (i = 0; i < 256; i++)
		if (ab(bef - in[st]) > ab(i - in[st])) {
			add = ab(bef - i) - M;
			if (add < 0)
				add = 0;
			k = (solve(st, i) + I) + add;
			if (res > k)
				res = k;
		}
	for (i = 0; i < 256; i++) {
		add = ab(bef - i) - M;
		if (add < 0)
			add = 0;
		tmp = ab(i - in[st]);
		k = (solve(st + 1, i) + add) + tmp;
		if (res > k)
			res = k;
	}
	k = solve(st + 1, bef) + D;
	if (res > k)
		res = k;
	return dp[st][bef] = res;
}

int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int res;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d%d%d", &D, &I, &M, &n);
		for (i = 0; i < n; i++)
			scanf("%d", in + i);
		for (i = 0; i < (n + 1); i++)
			for (j = 0; j < 256; j++)
				dp[i][j] = -1;
		res = 1000000000;
		for (i = 0; i < (n + 1); i++) {
			k = solve(i, in[i]) + (i * D);
			if (res > k)
				res = k;
		}
		printf("Case #%d: %d\n", ++count, res);
	}
	return 0;
}
