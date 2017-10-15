#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_cnt(char next[105][105], int count)
{
	int ans = 0;
	int i;
	int size;
	for (i = 0; i < count; i++) {
		for (size = 0; size < count; size++) {
			if (next[i][size])
				ans++;
		}
	}
	return ans;
}

int Main()
{
	int t;
	int grid;
	scanf("%d", &t);
	static char next[105][105];
	static char a2[105][105];
	for (grid = 0; grid < t; grid++) {
		memset(next, 0, sizeof(next));
		int vx;
		int o;
		int q;
		int c;
		int testc;
		scanf("%d", &testc);
		int i;
		int t;
		int k;
		int count = 0;
		for (i = 0; i < testc; i++) {
			scanf("%d %d %d %d", &vx, &o, &q, &c);
			if (q > count)
				count = q;
			if (c > count)
				count = c;
			vx--;
			o--;
			q--;
			c--;
			for (t = vx; t <= q; t++) {
				for (k = o; k <= c; k++) {
					next[t][k] = 1;
				}
			}
		}
		int ans = 0;
		while (get_cnt(next, count) > 0) {
			memset(a2, 0, sizeof(a2));
			for (t = 1; t < count; t++) {
				for (k = 1; k < count; k++) {
					if (next[t][k]) {
						if (next[t - 1][k]
						    || next[t][k - 1])
							a2[t][k] = 1;
					} else {
						if (next[t - 1][k]
						    && next[t][k - 1])
							a2[t][k] = 1;
					}
				}
			}
			memcpy(next, a2, sizeof(a2));
			ans++;
		}
		printf("Case #%d: %d\n", grid + 1, ans);
	}
	return 0;
}
