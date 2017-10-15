#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int k[10008];
int l[10008];
int comp(const void *p, const void *x2)
{
    int first_iteration;
    return (*((int *) p)) - (*((int *) x2));
}

int Main()
{
    int first_iteration;
    int gssCMaReplayDet;
    int t;
    int b;
    int n;
    int i;
    int tn;
    int res;
    int tmp;
    scanf("%d", &t);
    for (gssCMaReplayDet = 1; gssCMaReplayDet <= t; gssCMaReplayDet++) {
	scanf("%d%d", &n, &b);
	memset(l, 0, sizeof(l));
	for (i = 0; i < n; i++)
	    scanf("%d", &k[i]);
	qsort(k, n, 4, comp);
	res = 0;
	for (i = n - 1; i >= 0; i--) {
	    if (l[i])
		continue;
	    res++;
	    tmp = -1;
	    for (tn = 0; tn < i; tn++) {
		if ((!l[tn]) && ((k[tn] + k[i]) <= b)) {
		    tmp = tn;
		}
	    }
	    if (tmp < 0) {
		continue;
	    }
	    l[i] = (l[tmp] = 1);
	}
	printf("Case #%d: %d\n", gssCMaReplayDet, res);
    }
    return 0;
}
