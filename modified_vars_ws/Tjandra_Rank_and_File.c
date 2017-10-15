#include<stdio.h>
typedef unsigned u;
u max(u s, u c)
{
	return s > c ? s : c;
}

u f[1111];
u count[1111];
u v[1111];
u testCase;
int Main()
{
	u str = 0;
	u t;
	u na;
	u nopath;
	u j;
	u k;
	u m;
	for (scanf("%u", &t); (str++) < t;) {
		scanf("%u", &na);
		for (nopath = 0; (++nopath) <= na; count[nopath] = 0)
			scanf("%u", f + nopath);
		for (m = (nopath = 0); (++nopath) <= na;) {
			for (v[j = nopath] = ++testCase, k = 1;
			     v[j = f[j]] != testCase; ++k)
				v[j] = testCase;
			if (f[f[j]] == j)
				count[j] = max(count[j], k);
			if (nopath == j)
				m = max(m, k);
		}
		for (nopath = (k = 0); (++nopath) <= na;)
			if (count[nopath]) {
				k += count[nopath];
				if (f[nopath] < nopath)
					k -= 2;
			}
		m = max(m, k);
		printf("Case #%u: %u\n", str, m);
	}
	return 0;
}
