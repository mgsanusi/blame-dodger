#include <stdio.h>
#include <string.h>
int g[10000001];
int main()
{
	int i, j;
	int R, k, N;
	int cc, ca;
	scanf("%d", &ca);
	for (cc = 1; cc <= ca; cc++) {
		scanf("%d %d %d", &R, &k, &N);
		for (i = 0; i < N; i++)
			scanf("%d", &g[i]);
		long long cycle_r = 0;
		long long cycle_s = 0;
		int p = 0;
		while (cycle_r < R) {
			int s = 0;
			int pp = p;
			while (k - s >= g[pp]) {
				s += g[pp];
				pp = (pp + 1) % N;
				if (pp == p)
					break;
			}
			p = pp;
			cycle_r++;
			cycle_s += s;
			if (p == 0)
				break;
		}
//              printf("%lld %lld\n", cycle_r, cycle_s);
		if (cycle_r < R) {
			cycle_s += cycle_s * ((R - cycle_r) / cycle_r);
			cycle_r += cycle_r * ((R - cycle_r) / cycle_r);
			while (cycle_r < R) {
				int s = 0;
				int pp = p;
				while (k - s >= g[pp]) {
					s += g[pp];
					pp = (pp + 1) % N;
					if (pp == p)
						break;
				}
				p = pp;
				cycle_s += s;
				cycle_r++;
			}
		}
		printf("Case #%d: %lld\n", cc, cycle_s);
	}
}
