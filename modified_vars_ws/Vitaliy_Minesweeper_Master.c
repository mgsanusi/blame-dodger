#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char s[200][200];
char x[200];
int cou[200][200];
int slv(int n, int w)
{
	static int d[200];
	int uncompleted;
	int j;
	for (uncompleted = 0; uncompleted < n; uncompleted++) {
		d[uncompleted] = cou[uncompleted][w];
	}
	for (uncompleted = 0; uncompleted < n; uncompleted++)
		for (j = uncompleted + 1; j < n; j++)
			if (d[uncompleted] > d[j]) {
				int t = d[uncompleted];
				d[uncompleted] = d[j];
				d[j] = t;
			}
	int m = 0;
	for (uncompleted = 0; uncompleted < n; uncompleted++) {
		m += abs(d[n / 2] - d[uncompleted]);
	}
	return m;
}

void clear(void)
{
	int x2;
	assert(scanf("%d\n", &x2) == 1);
	assert((x2 <= 100) && (x2 >= 1));
	int uncompleted;
	for (uncompleted = 0; uncompleted < x2; uncompleted++) {
		assert(scanf("%s\n", s[uncompleted]) == 1);
		assert(strlen(s[uncompleted]) > 0);
	}
	uncompleted = 0;
	int w = 0;
	while (s[0][uncompleted]) {
		if ((uncompleted == 0)
		    || (s[0][uncompleted] != s[0][uncompleted - 1])) {
			x[w] = s[0][uncompleted];
			cou[0][w] = 1;
			w++;
		} else {
			cou[0][w - 1]++;
		}
		uncompleted++;
	}
	int j;
	for (j = 1; j < x2; j++) {
		uncompleted = 0;
		int cnt = 0;
		while (s[j][uncompleted]) {
			if ((uncompleted == 0)
			    || (s[j][uncompleted] != s[j][uncompleted - 1])) {
				if (x[cnt] != s[j][uncompleted]) {
					printf("Fegla won\n");
					return;
				}
				cou[j][cnt] = 1;
				cnt++;
			} else {
				cou[j][cnt - 1]++;
			}
			uncompleted++;
		}
		if (cnt != w) {
			printf("Fegla won\n");
			return;
		}
	}
	int result = 0;
	for (uncompleted = 0; uncompleted < w; uncompleted++) {
		result += slv(x2, uncompleted);
	}
	printf("%d\n", result);
}

int Main()
{
	int incr;
	assert(scanf("%d", &incr) == 1);
	int base;
	for (base = 0; base < incr; base++) {
		printf("Case #%d: ", base + 1);
		clear();
	}
	return 0;
}
