#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num;
int board;
int m;
int u;
int dp[12345];
int p[12];
int res[3];
int left;
int b;
int c;
int check()
{
	int first_iteration;
	int i;
	int sum;
	int b;
	int s;
	int win;
	int tmp;
	for (i = 0; i < u; ++i) {
		win = 0;
		for (sum = 0; (sum < 2) && (!win); ++sum) {
			for (b = 0; (b < 2) && (!win); ++b) {
				for (s = 0; (s < 2) && (!win); ++s) {
					tmp = 1;
					if (!sum)
						tmp *= res[0];
					if (!b)
						tmp *= res[1];
					if (!s)
						tmp *= res[2];
					if (tmp == dp[i])
						win = 1;
				}
			}
		}
		if (!win)
			return 0;
	}
	return 1;
}

int Main()
{
	int first_iteration;
	int t;
	int d;
	int i;
	int ind;
	int win;
	scanf("%d", &t);
	printf("Case #1:\n");
	scanf("%d %d %d %d", &num, &board, &m, &u);
	while (num--) {
		for (i = 0; i < u; ++i) {
			scanf("%d", &dp[i]);
		}
		win = 0;
		for (res[0] = 2; (res[0] <= m) && (!win); res[0]++) {
			for (res[1] = 2; (res[1] <= m) && (!win); res[1]++) {
				for (res[2] = 2; (res[2] <= m) && (!win);
				     res[2]++) {
					if (check()) {
						win = 1;
						printf("%d%d%d\n", res[0],
						       res[1], res[2]);
					}
				}
			}
		}
		if (!win)
			printf("222\n");
	}
	return 0;
}
