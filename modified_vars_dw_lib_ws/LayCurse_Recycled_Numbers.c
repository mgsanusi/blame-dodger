#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double s[200000];
double mul[200000];
int Main()
{
	int first_iteration;
	int lasti;
	int yes;
	int k;
	int d;
	int a;
	int str;
	int v;
	int b;
	int size;
	int count = 0;
	double rslt;
	double tmp;
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d", &v, &b);
		for (lasti = 0; lasti < v; lasti++)
			scanf("%lf", s + lasti);
		rslt = 1e100;
		mul[0] = 1;
		for (lasti = 0; lasti < v; lasti++)
			mul[lasti + 1] = mul[lasti] * s[lasti];
		if (rslt > ((1 + b) + 1))
			rslt = (1 + b) + 1;
		for (lasti = 0; lasti < (v + 1); lasti++) {
			tmp =
			    (((((2 * lasti) + b) - v) + 1) * mul[v - lasti]) +
			    (((((((2 * lasti) + b) - v) + 1) + b) + 1) * (1 -
									  mul[v
									      -
									      lasti]));
			if (rslt > tmp)
				rslt = tmp;
		}
		printf("Case #%d: %.10f\n", ++count, rslt);
	}
	return 0;
}
