#include <stdio.h>
int Main()
{
	int t;
	int d;
	double w;
	double end;
	double n;
	double l;
	double a;
	scanf("%d", &t);
	for (d = 1; d <= t; d++) {
		scanf("%lf%lf%lf", &w, &end, &n);
		l = 2.0;
		a = 0.0;
		while ((n * l) < ((n - w) * (l + end))) {
			a = a + (w / l);
			l = l + end;
		}
		a = a + (n / l);
		printf("Case #%d: %.7lf\n", d, a);
	}
	return 0;
}
