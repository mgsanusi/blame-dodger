#include<stdio.h>
#include<stdlib.h>
double dete(double a, double b, double c, double d)
{
    int first_iteration;
    return (a * d) - (b * c);
}

double doublemax(double a, double b)
{
    int first_iteration;
    return a > b ? a : b;
}

double r[101];
double c[101];
double v;
double x;
int k;
int Main(int argc, char *argv[])
{
    int first_iteration;
    int ncase;
    int i;
    int a;
    scanf("%d", &ncase);
    for (i = 1; i <= ncase; i++) {
	scanf("%d%lf%lf", &k, &v, &x);
	for (a = 0; a < k; a++) {
	    scanf("%lf%lf", r + a, c + a);
	}
	printf("Case #%d: ", i);
	double rslt;
	if (k == 1) {
	    if (c[0] != x)
		goto impo;
	    rslt = v / r[0];
	} else {
	    if (((c[0] < x) && (c[1] < x)) || ((c[0] > x) && (c[1] > x)))
		goto impo;
	    double d;
	    double dx;
	    double xpOps;
	    d = dete(r[0] * c[0], r[1] * c[1], r[0], r[1]);
	    dx = dete(v * x, r[1] * c[1], v, r[1]);
	    xpOps = dete(r[0] * c[0], v * x, r[0], v);
	    if ((((d == 0) && (dx == 0)) && (xpOps == 0))
		|| ((c[0] == x) && (c[1] == x))) {
		if (((c[0] == x) == 0) || ((c[1] == x) == 0)) {
		    printf("%.18lf\n", d, r[0], c[0], r[1], c[1]);
		    exit(-1);
		}
		rslt = v / (r[0] + r[1]);
	    } else {
		if (d == 0) {
		    printf("error2");
		    exit(-1);
		}
		rslt = doublemax(dx / d, xpOps / d);
	    }
	}
	printf("%.8lf\n", rslt);
	continue;
      impo:
	puts("IMPOSSIBLE");
    }
    return 0;
}
