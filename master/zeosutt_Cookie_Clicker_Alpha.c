#include <stdio.h>

#define MAX_ARY 3000
#define min(a, b) (((a) < (b)) ? (a) : (b))

double sum[MAX_ARY];

int main(void) {
	int i, j, k;
	int t;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		double c, f, x, ans;

		scanf("%lf %lf %lf", &c, &f, &x);

		sum[0] = 0.0;
		for (j = 1; j < MAX_ARY; j++)
			sum[j] = sum[j - 1] + c / (2 + f * (j - 1));
		for (j = 0; j < MAX_ARY; j++)
			sum[j] += x / (2 + f * j);

		ans = 1e200;
		for (j = 0; j < MAX_ARY; j++)
			ans = min(ans, sum[j]);

		printf("Case #%d: %.7f\n", i, ans);
	}

	return 0;
}
