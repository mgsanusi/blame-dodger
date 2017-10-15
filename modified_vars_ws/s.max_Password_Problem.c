#include <stdio.h>
int Main()
{
	int y;
	int j;
	scanf("%d", &y);
	for (j = 1; j <= y; j++) {
		double p[100000];
		double rez;
		double temp;
		double prod;
		int j;
		int a;
		int sum;
		scanf("%d %d", &a, &sum);
		for (j = 0; j < a; j++)
			scanf("%lf", p + j);
		rez = 2 + sum;
		int k;
		prod = 1;
		for (k = 0; k <= a; k++) {
			temp =
			    ((((2 * (a - k)) + sum) - a) + 1) +
			    ((1 - prod) * (sum + 1));
			if (temp < rez)
				rez = temp;
			if (k < a)
				prod *= p[k];
		}
		printf("Case #%d: %lf\n", j, rez);
	}
	return 0;
}
