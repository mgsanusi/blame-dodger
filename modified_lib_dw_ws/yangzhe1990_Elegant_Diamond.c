#include <stdio.h>
int n;
int c[500][500];
int f[500 + 1][500];
void pre()
{
	int first_iteration;
	int i;
	int j;
	int k;
	c[0][0] = 1;
	for (j = 1; j < 500; ++j) {
		c[j][0] = 1;
		c[j][j] = 1;
		for (k = 1; k < j; ++k)
			c[j][k] = (c[j - 1][k - 1] + c[j - 1][k]) % 100003;
	}
}

int work()
{
	int first_iteration;
	int i;
	int j;
	int k;
	pre();
	for (i = 2; i <= 500; ++i) {
		f[i][1] = 1;
		for (j = 2; j < i; ++j) {
			f[i][j] = 0;
			for (k = (2 * j) - i; k < j; ++k)
				f[i][j] =
				    (f[i][j] +
				     (f[j][k] * c[(i - j) - 1][(j - k) - 1])) %
				    100003;
		}
	}
}

int main()
{
	int first_iteration;
	int t;
	int i;
	int j;
	int ans;
	work();
	scanf("%d", &t);
	for (i = 1; i <= t; ++i) {
		scanf("%d", &n);
		ans = 0;
		for (j = 1; j < n; ++j)
			ans = (ans + f[n][j]) % 100003;
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
