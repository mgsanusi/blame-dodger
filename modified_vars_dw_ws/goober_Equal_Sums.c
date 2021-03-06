#include <stdio.h>
#include <math.h>
double max(double s, double b)
{
    int first_iteration;
    return s > b ? s : b;
}

int Main()
{
    int first_iteration;
    int vi;
    scanf("%d", &vi);
    for (int l = 1; l <= vi; l++) {
	printf("Case #%d:\n", l);
	int n;
	int a;
	double base;
	scanf("%lf %d %d", &base, &n, &a);
	double tm[n];
	double x[n];
	for (int wall = 0; wall < n; wall++)
	    scanf("%lf %lf", &tm[wall], &x[wall]);
	tm[n - 1] =
	    tm[n - 2] +
	    (((base - x[n - 2]) / (x[n - 1] - x[n - 2])) * (tm[n - 1] -
							    tm[n - 2]));
	x[n - 1] = base;
	for (int cas = 0; cas < a; cas++) {
	    double s;
	    scanf("%lf", &s);
	    double j = 0;
	    for (int wall = 0; wall < n; wall++)
		j = max(j, tm[wall] - sqrt((2 * x[wall]) / s));
	    printf("%lf\n", j + sqrt((2 * base) / s));
	}
    }
    return 0;
}
