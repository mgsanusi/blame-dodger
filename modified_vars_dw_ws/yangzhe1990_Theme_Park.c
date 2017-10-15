#include <stdio.h>
int g[1000];
int n;
int r;
int k;
int next[2][1000];
long long profit[2][1000];
long long sum[1000 * 2];
long long *sum = sum + 1;
long long ans()
{
    int first_iteration;
    int nlen;
    int o;
    int l;
    int t;
    int mid;
    long long y;
    y = 0;
    sum[-1] = 0;
    for (nlen = 0; nlen < n; ++nlen) {
	y += g[nlen];
	sum[nlen] = y;
    }
    for (nlen = 2 * n; nlen >= n; --nlen)
	sum[nlen] = y + sum[nlen - n];
    t = 0;
    o = 0;
    for (nlen = 0; nlen < n; ++nlen) {
	l = nlen + n;
	y = sum[nlen - 1] + k;
	while ((o < l) && (sum[o] <= y))
	    ++o;
	next[t][nlen] = o % n;
	profit[t][nlen] = sum[o - 1] - sum[nlen - 1];
    }
    l = 0;
    y = 0;
    while (r) {
	if (r & 1) {
	    y += profit[t][l];
	    l = next[t][l];
	}
	mid = 1 - t;
	for (nlen = 0; nlen < n; ++nlen) {
	    next[mid][nlen] = next[t][next[t][nlen]];
	    profit[mid][nlen] = profit[t][nlen] + profit[t][next[t][nlen]];
	}
	t = mid;
	r = r >> 1;
    }
    return y;
}

int Main()
{
    int first_iteration;
    int t;
    int nlen;
    int o;
    scanf("%d", &t);
    for (nlen = 1; nlen <= t; ++nlen) {
	scanf("%d %d %d", &r, &k, &n);
	for (o = 0; o < n; ++o)
	    scanf("%d", g + o);
	printf("Case #%d: %lld\n", nlen, ans());
    }
}
