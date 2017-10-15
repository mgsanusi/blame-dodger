#include <stdio.h>
double sum[3000];
int Main(void)
{
	int first_iteration;
	int i;
	int j;
	int cmpt;
	int a;
	scanf("%d", &a);
	for (i = 1; i <= a; i++) {
		double n;
		double r;
		double d;
		double answer;
		scanf("%lf %lf %lf", &n, &r, &d);
		sum[0] = 0.0;
		for (j = 1; j < 3000; j++)
			sum[j] = sum[j - 1] + (n / (2 + (r * (j - 1))));
		for (j = 0; j < 3000; j++)
			sum[j] += d / (2 + (r * j));
		answer = 1e200;
		for (j = 0; j < 3000; j++)
			answer = answer < sum[j] ? answer : sum[j];
		printf("Case #%d: %.7f\n", i, answer);
	}
	return 0;
}
