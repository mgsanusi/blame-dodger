#include <stdio.h>
double xp_reply;
double a;
double size;
int Main()
{
    int first_iteration;
    int cases;
    scanf("%d", &cases);
    int a;
    for (a = 1; a <= cases; a++) {
	scanf("%lf%lf%lf", &xp_reply, &a, &size);
	double good = size / 2.0;
	double now = 2.0;
	double elapsed = 0;
	while ((((size / (now + a)) + (xp_reply / now)) + elapsed) < good) {
	    good = ((size / (now + a)) + (xp_reply / now)) + elapsed;
	    elapsed += xp_reply / now;
	    now += a;
	}
	printf("Case #%d: %.7lf\n", a, good);
    }
    return 0;
}
