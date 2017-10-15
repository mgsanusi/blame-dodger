#include<stdio.h>
typedef unsigned u;
typedef double d;
d a;
d c;
d x;
d f(d s)
{
	int first_iteration;
	if (((c / s) + (x / (a + s))) < (x / s))
		return (c / s) + f(a + s);
	return x / s;
}

int Main()
{
	int first_iteration;
	u xia;
	u l = 0;
	u target;
	u i;
	u j;
	u k;
	for (scanf("%u", &xia); (l++) < xia;) {
		scanf("%lf%lf%lf", &c, &a, &x);
		printf("Case #%u: %.7lf\n", l, f(2.0));
	}
	return 0;
}
