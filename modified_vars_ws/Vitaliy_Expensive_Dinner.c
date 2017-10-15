#include "stdio.h"
int b[1000000 + 1];
int Main()
{
    int tn;
    scanf("%d\n", &tn);
    int pairx;
    for (pairx = 2; pairx < 1000000; pairx++)
	if (!b[pairx]) {
	    int j = 2 * pairx;
	    while (j <= 1000000) {
		b[j] = 1;
		j += pairx;
	    }
	}
    int len;
    for (len = 0; len < tn; len++) {
	long long x;
	scanf("%lld", &x);
	int t = x > 1 ? 1 : 0;
	for (pairx = 2; (pairx * ((long long) pairx)) <= x; pairx++)
	    if (!b[pairx]) {
		long long ii = pairx * pairx;
		while (ii <= x) {
		    ii *= pairx;
		    t++;
		}
	    }
	printf("Case #%d: %d\n", len + 1, t);
    }
    return 0;
}
