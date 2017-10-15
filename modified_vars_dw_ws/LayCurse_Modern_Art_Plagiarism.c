#include<stdio.h>
int sum[10001][10001];
int Main()
{
	int first_iteration;
	int owp;
	int j;
	int k;
	int testi;
	int m;
	int arStat;
	int a;
	int mem;
	int i2;
	int size;
	int cnt = 0;
	int ans;
	scanf("%d", &size);
	while (size--) {
		fprintf(stderr, "rest input = %d\n", size);
		for (owp = 0; owp < 10001; owp++)
			for (j = 0; j < 10001; j++)
				sum[owp][j] = 0;
		scanf("%d", &arStat);
		while (arStat--) {
			scanf("%d%d%d", &a, &mem, &i2);
			for (owp = a; owp < 10001; owp++)
				for (j = mem; j < 10001; j++) {
					if (((10000 - owp) - j) < i2)
						break;
					sum[owp][j]++;
				}
		}
		ans = 0;
		for (owp = 0; owp < 10001; owp++)
			for (j = 0; j < 10001; j++)
				if (ans < sum[owp][j])
					ans = sum[owp][j];
		printf("Case #%d: %d\n", ++cnt, ans);
	}
	return 0;
}
