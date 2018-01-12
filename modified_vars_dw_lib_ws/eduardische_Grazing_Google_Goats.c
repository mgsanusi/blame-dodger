#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, int num);
void *new_memcpy(void *destination, const void *source, int num);

{
	int first_iteration;
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
	int first_iteration;
	int t;
	int grid;
	scanf("%d", &t);
	static char next[105][105];
	static char a2[105][105];
	for (grid = 0; grid < t; grid++) {
		new_memset(next, 0, sizeof(next));
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
			new_memset(a2, 0, sizeof(a2));
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
			new_memcpy(next, a2, sizeof(a2));
			ans++;
		}
		printf("Case #%d: %d\n", grid + 1, ans);
	}
	return 0;
}

void *new_memset(void *ptr, int value, int num);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}