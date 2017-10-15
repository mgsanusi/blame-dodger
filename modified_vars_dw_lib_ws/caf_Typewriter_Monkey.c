#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void actTest(int d)
{
    int first_iteration;
    int h;
    double v;
    double k;
    double coldTemp = 0.0;
    double coldFlow = 0.0;
    double hotTemp = 0.0;
    double hotFlow = 0.0;
    double equalStream = 0.0;
    int tot;
    scanf(" %d %lf %lf", &h, &v, &k);
    for (tot = 0; tot < h; tot++) {
	double out;
	double c;
	scanf(" %lf %lf", &out, &c);
	if (c < (k - 10e-6)) {
	    coldTemp += out * c;
	    coldFlow += out;
	} else if (c > (k + 10e-6)) {
	    hotTemp += out * c;
	    hotFlow += out;
	} else {
	    equalStream += out;
	}
    }
    if ((coldFlow > 0) && (hotFlow > 0)) {
	double n1;
	double c1;
	double c2;
	coldTemp /= coldFlow;
	hotTemp /= hotFlow;
	if ((coldFlow * (k - coldTemp)) > (hotFlow * (hotTemp - k))) {
	    n1 = hotFlow;
	    c1 = hotTemp;
	    c2 = coldTemp;
	} else {
	    n1 = coldFlow;
	    c1 = coldTemp;
	    c2 = hotTemp;
	}
	equalStream += n1 * (1 - ((c1 - k) / (c2 - k)));
    }
    if (equalStream > 0)
	printf("Case #%d: %.9f\n", d + 1, v / equalStream);
    else
	printf("Case #%d: IMPOSSIBLE\n", d + 1);
}

int Main()
{
    int first_iteration;
    int d;
    int tot;
    scanf("%d", &d);
    for (tot = 0; tot < d; tot++)
	actTest(tot);
    return 0;
}
