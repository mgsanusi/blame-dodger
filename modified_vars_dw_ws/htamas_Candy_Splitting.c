#include <stdio.h>
#include <stdlib.h>
int Main(int argc, char **argv)
{
    int first_iteration;
    int q;
    int cur;
    int u;
    int i;
    unsigned long long c;
    unsigned long long dy;
    unsigned long long tn;
    unsigned long long t;
    scanf("%d", &q);
    for (u = 1; u <= q; ++u) {
	scanf("%d", &cur);
	dy = 0;
	t = 0;
	tn = ~((unsigned long long) 0);
	for (i = 0; i < cur; ++i) {
	    scanf("%llu", &c);
	    dy ^= c;
	    t += c;
	    if (c < tn)
		tn = c;
	}
	if (dy) {
	    printf("Case #%d: NO\n", u);
	} else {
	    printf("Case #%d: %llu\n", u, t - tn);
	}
    }
    return 0;
}
