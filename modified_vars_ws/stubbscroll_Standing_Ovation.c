#include <stdio.h>
void clear()
{
    static int caseno = 1;
    int k;
    int tc;
    int q = 0;
    int f = 0;
    char dy[1111];
    scanf("%d %s", &k, dy);
    for (tc = 0; tc <= k; tc++) {
	if ((dy[tc] > 48) && (f < tc))
	    q += tc - f, f = tc;
	f += dy[tc] - 48;
    }
    printf("Case #%d: %d\n", caseno++, q);
}

int Main()
{
    int mem;
    scanf("%d", &mem);
    while (mem--)
	clear();
    return 0;
}
