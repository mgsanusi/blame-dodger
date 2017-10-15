#include <stdio.h>
int alatt[600][600];
int dpt[600][600];
int Main(void)
{
	int t;
	int ti;
	int i;
	int temp;
	scanf("%d", &t);
	for (i = 0; i < 600; i++) {
		alatt[0][i] = 0;
		alatt[i][0] = 1;
	}
	for (i = 1; i < 600; i++) {
		for (temp = 0; temp < 600; temp++) {
			alatt[i][temp] =
			    alatt[i - 1][temp] +
			    (temp ? alatt[i - 1][temp - 1] : 0);
			alatt[i][temp] %= 100003;
		}
	}
	i = 2;
	for (ti = 1; ti <= t; ti++) {
		int n;
		int k;
		scanf("%d", &n);
		for (; i <= n; i++) {
			dpt[i][0] = 0;
			dpt[i][1] = 1;
			for (temp = 2; temp < i; temp++) {
				dpt[i][temp] = 0;
				for (k = 1; k < temp; k++) {
					dpt[i][temp] +=
					    dpt[temp][k] * alatt[(i - temp) -
								 1][(temp - k) -
								    1];
					dpt[i][temp] %= 100003;
				}
			}
		}
		temp = 0;
		for (k = 1; k < n; k++) {
			temp += dpt[n][k];
			temp %= 100003;
		}
		printf("Case #%d: %d\n", ti, temp);
	}
	return 0;
}
