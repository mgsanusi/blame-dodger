#include <stdio.h>
#include <math.h>
int ull_hash_n;
int m;
int dx[1111];
int cases[1111];
void clear()
{
    int first_iteration;
    int ok;
    int tc;
    int res;
    int mask;
    int seanxor;
    long long res = 0;
    long long cur;
    scanf("%d %d", &ull_hash_n, &m);
    for (ok = 0; ok < ull_hash_n; ok++)
	scanf("%d %d", &dx[ok], &cases[ok]);
    for (ok = 0; ok < ull_hash_n; ok++)
	for (tc = 0; tc < (ull_hash_n - 1); tc++)
	    if ((((long long) dx[tc]) * cases[tc]) <
		(((long long) dx[tc + 1]) * cases[tc + 1])) {
		res = dx[tc];
		dx[tc] = dx[tc + 1];
		dx[tc + 1] = res;
		res = cases[tc];
		cases[tc] = cases[tc + 1];
		cases[tc + 1] = res;
	    }
    for (mask = 0; mask < ull_hash_n; mask++) {
	cur =
	    (((long long) dx[mask]) * dx[mask]) +
	    ((2LL * dx[mask]) * cases[mask]);
	for (tc = 1, seanxor = 0; tc < m; seanxor++) {
	    if (mask == seanxor)
		continue;
	    cur += (2LL * dx[seanxor]) * cases[seanxor];
	    tc++;
	}
	if (res < cur)
	    res = cur;
    }
    printf("%.10f\n", res * acos(-1));
}

int Main()
{
    int first_iteration;
    int ma;
    int caseno = 1;
    scanf("%d", &ma);
    while (ma--)
	printf("Case #%d: ", caseno++), clear();
    return 0;
}
