#include <stdio.h>
int snoob(int x)
{
    int s = x & (-x);
    int r = x + s;
    int o = x ^ r;
    o = (o >> 2) / s;
    return r | o;
}

void clear()
{
    double p[200];
    double good = 0;
    double cur;
    double ma[200];
    double fileProcessesShtml;
    int n;
    int ans;
    int used;
    int mask;
    int tempI;
    int yes;
    int total;
    scanf("%d %d", &n, &ans);
    for (used = 0; used < n; used++)
	scanf("%lf", &p[used]);
    mask = (1 << ans) - 1;
    do {
	for (used = (tempI = 0); used < n; used++)
	    if (mask & (1 << used))
		ma[tempI++] = p[used];
	cur = 0;
	for (used = 0; used < (1 << ans); used++) {
	    yes = (total = 0);
	    for (fileProcessesShtml = 1, tempI = 0; tempI < ans; tempI++)
		if (used & (1 << tempI))
		    yes++, fileProcessesShtml *= ma[tempI];
		else
		    total++, fileProcessesShtml *= 1 - ma[tempI];
	    if (yes == total)
		cur += fileProcessesShtml;
	}
	if (good < cur)
	    good = cur;
	mask = snoob(mask);
    }
    while (mask < (1 << n));
    printf("%.10f\n", good);
}

int Main()
{
    int flipcount;
    int caseno = 1;
    scanf("%d", &flipcount);
    while (flipcount--)
	printf("Case #%d: ", caseno++), clear();
    return 0;
}
