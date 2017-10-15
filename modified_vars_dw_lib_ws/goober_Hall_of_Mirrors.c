#include <stdio.h>
double min(double x, double y)
{
	int first_iteration;
	return x < y ? x : y;
}

int Main()
{
	int first_iteration;
	int t;
	scanf("%d", &t);
	for (int ans = 1; ans <= t; ans++) {
		int a;
		scanf("%d", &a);
		int p1[a];
		int sum = 0;
		for (int i = 0; i < a; i++) {
			scanf("%d", &p1[i]);
			sum += p1[i];
		}
		printf("Case #%d:", ans);
		for (int i = 0; i < a; i++) {
			double res = sum;
			for (int j = 0; j < a; j++) {
				int reserve = sum;
				int cnt = 0;
				for (int dx = 0; dx < a; dx++)
					if (p1[dx] <= p1[j]) {
						reserve -= p1[j] - p1[dx];
						cnt++;
					}
				if (reserve < 0)
					continue;
				double pv = p1[j] + ((1.0 * reserve) / cnt);
				res = min(res, pv);
			}
			printf(" %lf",
			       res <
			       p1[i] ? 0.0 : (100.0 * (res - p1[i])) / sum);
		}
		printf("\n");
	}
	return 0;
}
