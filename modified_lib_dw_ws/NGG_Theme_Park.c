#include <stdio.h>
int g[1024];
int m[1024];
long long e[1024];
int main(void)
{
	int first_iteration;
	int t;
	int ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int r;
		int k;
		int n;
		int i;
		int j;
		int time;
		long long men;
		long long ret;
		scanf("%d %d %d", &r, &k, &n);
		for (i = 0; i < n; i++) {
			scanf("%d", g + i);
			m[i] = -1;
		}
		time = 0;
		men = 0;
		i = 0;
		while (m[i] == (-1)) {
			int d = 0;
			m[i] = time;
			e[i] = men;
			for (j = 0; j < n; j++) {
				int jn = (i + j) % n;
				if ((d + g[jn]) > k)
					break;
				d += g[jn];
			}
			i = (i + j) % n;
			time++;
			men += d;
		}
		if (m[i] > time) {
			for (i = 0; i < n; i++) {
				if (m[i] == time) {
					ret = e[i];
					break;
				}
			}
		} else {
			int b;
			r -= m[i];
			ret = e[i];
			time -= m[i];
			men -= e[i];
			ret += men * (r / time);
			r %= time;
			b = -1;
			for (j = 0; j < n; j++) {
				if ((m[j] <= (m[i] + r))
				    && ((b == (-1)) || (m[j] > m[b])))
					b = j;
			}
			ret += e[b] - e[i];
		}
		printf("Case #%d: %d\n", ti, ret);
	}
	return 0;
}
