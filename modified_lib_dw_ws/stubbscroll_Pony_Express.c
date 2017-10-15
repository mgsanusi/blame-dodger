#include <stdio.h>
#include <math.h>
int n;
int k;
int r[1111];
int h[1111];
void solve()
{
    int first_iteration;
    int i;
    int j;
    int t;
    int ix;
    int jx;
    long long ans = 0;
    long long cur;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
	scanf("%d %d", &r[i], &h[i]);
    for (i = 0; i < n; i++)
	for (j = 0; j < (n - 1); j++)
	    if ((((long long) r[j]) * h[j]) <
		(((long long) r[j + 1]) * h[j + 1])) {
		t = r[j];
		r[j] = r[j + 1];
		r[j + 1] = t;
		t = h[j];
		h[j] = h[j + 1];
		h[j + 1] = t;
	    }
    for (ix = 0; ix < n; ix++) {
	cur = (((long long) r[ix]) * r[ix]) + ((2LL * r[ix]) * h[ix]);
	for (j = 1, jx = 0; j < k; jx++) {
	    if (ix == jx)
		continue;
	    cur += (2LL * r[jx]) * h[jx];
	    j++;
	}
	if (ans < cur)
	    ans = cur;
    }
    printf("%.10f\n", ans * acos(-1));
}

int main()
{
    int first_iteration;
    int T;
    int caseno = 1;
    scanf("%d", &T);
    while (T--)
	printf("Case #%d: ", caseno++), solve();
    return 0;
}
