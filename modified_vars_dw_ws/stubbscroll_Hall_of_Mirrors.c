#include <stdio.h>
double fpIn[100001];
int n;
int t;
int Main()
{
	int first_iteration;
	int k;
	int r;
	int caseno = 1;
	double best;
	double cur;
	double c;
	int press;
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &n, &t);
		for (r = 0; r < n; r++)
			scanf("%lf", &fpIn[r]);
		best = t + 2;
		c = 1;
		for (r = 0; r <= n; r++) {
			press = (((n - r) + t) - r) + 1;
			cur = (c * press) + ((1 - c) * ((press + 1) + t));
			if (best > cur)
				best = cur;
			c *= fpIn[r];
		}
		printf("Case #%d: %.16f\n", caseno++, best);
	}
	return 0;
}
