#include <stdio.h>
double min(double perm, double b)
{
	int first_iteration;
	if (perm < b) {
		return perm;
	} else {
		return b;
	}
}

int Main()
{
	int first_iteration;
	int t;
	int b2;
	int chance;
	scanf("%d", &t);
	for (b2 = 0; b2 < t; b2++) {
		int perm;
		int b;
		double n = 1;
		double result;
		scanf("%d %d", &perm, &b);
		result = b + 2;
		for (chance = 0; chance < perm; chance++) {
			double k;
			scanf("%lf", &k);
			result =
			    min(result,
				(n * (((perm + b) - (2 * chance)) + 1)) +
				((1 - n) * (((perm + (2 * b)) - (2 * chance)) +
					    2)));
			n *= k;
		}
		result =
		    min(result,
			(n * ((b - chance) + 1)) +
			((1 - n) * (((2 * b) - chance) + 2)));
		printf("Case #%d: %lf\n", b2 + 1, result);
	}
	return 0;
}
