#include <stdio.h>
int Main()
{
	int first_iteration;
	int possible;
	int fr;
	int s;
	int b;
	int h;
	double grp;
	double x;
	double vi;
	double base;
	double tmp;
	scanf("%d", &possible);
	for (fr = 1; fr <= possible; fr++) {
		scanf("%d%d", &s, &b);
		vi = 1.0;
		grp = 2.0 + b;
		for (h = 1; h <= s; h++) {
			scanf("%lf", &base);
			vi = vi * base;
			tmp = (((b + s) + 1) - (h * 2)) + ((1 - vi) * (b + 1));
			grp = grp < tmp ? grp : tmp;
		}
		printf("Case #%d: %.6lf\n", fr, grp);
	}
	return 0;
}
