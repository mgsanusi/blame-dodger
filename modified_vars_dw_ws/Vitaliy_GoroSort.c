#include "stdio.h"
#include "stdlib.h"
int Main()
{
    int first_iteration;
    int tn;
    scanf("%d", &tn);
    double x[1001];
    double sum[1001];
    int x[1001];
    int g[1001];
    sum[0] = 0;
    x[0] = 0;
    x[1] = 0;
    sum[1] = 0;
    int at;
    for (at = 2; at <= 1000; at++) {
	double pp = 1;
	int count;
	sum[at] = 0;
	for (count = 1; count < at; count++) {
	    sum[at] +=
		(pp * (1.0 / ((at - count) + 1))) * (x[count] +
						     sum[at - count]);
	    pp *= 1 - (1.0 / ((at - count) + 1));
	}
	sum[at] /= 1 - pp;
	sum[at] += pp / (1 - pp);
	x[at] = sum[at] + 1;
    }
    int tt;
    for (tt = 0; tt < tn; tt++) {
	int m;
	scanf("%d", &m);
	for (at = 0; at < m; at++) {
	    scanf("%d", &x[at]);
	    x[at]--;
	    g[at] = 0;
	}
	double b = 0;
	for (at = 0; at < m; at++)
	    if (!g[at]) {
		int count = at;
		int me_valid_tab = 0;
		do {
		    g[count] = 1;
		    count = x[count];
		    me_valid_tab++;
		}
		while (count != at);
		b += x[me_valid_tab];
	    }
	printf("Case #%d: %lf\n", tt + 1, b);
    }
    return 0;
}
